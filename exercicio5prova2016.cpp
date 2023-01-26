#include <iostream>
#include <stack>

using namespace std;

stack<char> pilha;
int bem_formada(string s) {
    int i = 0;
    while(s[i] != '\0') {
        if(s[i] == '(' or s[i] == '[' or s[i] == '{')
            pilha.push(s[i]);
        else if(s[i] == ')' or s[i] == ']' or s[i] == '}') {
            if(pilha.empty()) return 0;
            char x = pilha.top();
            switch(s[i]) {
                case ')':
                    if(x != '(') return 0;
                    break;
                case ']':
                    if(x != '[') return 0;
                    break;
                case '}':
                    if(x != '{') return 0;
                    break;
            }
            pilha.pop();
        }
        i++;
    }
    return pilha.empty();
}

int main ()
{
    int t = 0;
    while(++t < 5) {
        cout<<"Caso "<<t<<":"<<"\n";
        string s;
        getline(cin, s);
        cout<<"string: "<<s<<"\n";
        cout<<bem_formada(s)<<"\n";
    }
    return 0;
}
