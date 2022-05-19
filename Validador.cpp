#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

// Exercicio 5 - Validador de chaves, colchetes e parênteses

bool casal(char abre, char fecha){
    switch(abre){
        case '(':
            return fecha == ')';
        case '[':
            return fecha == ']';
        case '{':
            return fecha == '}';
    }
}

bool validar(string ex){
    stack<char> p;
    for(int i = 0; i < ex.size(); i++){
        switch(ex[i]){
            case '(': case '[': case '{':
                p.push(ex[i]);
                break;
            case ')': case ']': case '}':
                if(!p.empty()){
                    char abre = p.top();
                    if(!casal(abre, ex[i])){
                        return false; // expressão incorreta
                    }
                    p.pop();
                }
                else{
                    return false; // expressão incorreta
                }
                break;
        }
    }
    return p.empty();
}

int main(){
    string ex;
    while(true){
        if(ex == "0"){
            break;
        }
        cin >> ex;
        if(validar(ex)){
            cout << "VALIDA" << endl;
        }
        else{
            cout << "INVALIDA" << endl;
        }
    }
    return 0;
}
