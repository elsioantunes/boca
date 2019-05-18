#include <iostream>
#include <stack>
using namespace std;


int main() {
    int n,i;
    int m; 
    char op;
    stack<int> pilha, aux;

    cin>>n;
    while(cin>>op ) 
        if(op == 'E') {
            cin >> m;
            if(pilha.size()<n)
                pilha.push(m);

        } else if(!pilha.empty())
            if(op == 'D') 
                pilha.pop();
    
            else if(op == 'T') {
                cout << pilha.top() << endl;;
                
            } else {
                while(!pilha.empty()){
                    if(op == 'B')
                        cout << (aux.size()?" ":"") << pilha.top();
                    aux.push(pilha.top());
                    pilha.pop();
                }
                while(!aux.empty()){
                    if(op != 'B')
                        cout << (pilha.size()?" ":"") << aux.top();
                    pilha.push(aux.top());
                    aux.pop();
                }
                cout << endl;
            }
                
        
    return 0;
}
