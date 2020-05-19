#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct bracket{
    bracket(char type): type(type) {}
    bool match(char c)
    {
        if(type == '[' && c == ']')
            return true;
        if(type == '(' && c == ')')
            return true;
        if(type == '{' && c == '}')
            return true;
        else
            return false;
    }
    char type;
};

int main()
{
    string s;
    getline(cin,s);
    stack <bracket> brack;
    int position = 0;
    for(int i=0; i < s.length(); i++){
        char c = s[i];
        if(c == '(' || c == '{' || c == '['){
            brack.push(bracket(c));
            position = i+1;
        }
        else if(c == ')' || c == '}' || c == ']'){
            if(brack.empty()){
                brack.push(bracket(c));
                position = i+1;
                break;
            }
            else{
                bracket top = brack.top();
                if(top.match(c)){
                    brack.pop();
                }
                else{
                    position = i+1;
                    break;
                }
            }
        }
    }
    if(brack.empty()){
        cout << "success!!!" << endl;
    }
    if(position){
        cout << "Failed!!!" << endl;
        cout<<position <<endl;
    }
}
