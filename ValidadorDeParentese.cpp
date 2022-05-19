#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

// Exercicio 4 - Validador de parênteses

bool validar(string ex){
    stack<char> p;
    for(int i = 0; i < ex.size(); i++){
        if(ex[i] == '('){
            p.push(ex[i]);
        }
        else{
            if(ex[i] == ')'){
                if(!p.empty()){
                    p.pop();
                }
                else{
                    return false; // expressão incorreta
                }
            }
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
