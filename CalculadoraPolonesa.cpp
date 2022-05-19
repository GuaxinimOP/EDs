#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

// Exercicio 3 - Calculadora polonesa invertida

int calcular(string ex){
    stack<char> p;
    for(int i = 0; i < ex.size(); i++){
        if(ex[i] >= '0' && ex[i] <= '9'){
            p.push(ex[i] - 48);
        }
        else{
            if(ex[i] == '+'){
                int x = p.top();
                p.pop();
                int y = p.top();
                p.pop();
                p.push(x + y);
            }
            else if(ex[i] == '-'){
                int x = p.top();
                p.pop();
                int y = p.top();
                p.pop();
                p.push(x - y);
            }
            else if(ex[i] == '*'){
                int x = p.top();
                p.pop();
                int y = p.top();
                p.pop();
                p.push(x * y);
            }
        }
    }
    return p.top();
}


int main(){
    string s;
    cin >> s;
    calcular(s);

    cout << calcular(s) << endl;
    return 0;
}
