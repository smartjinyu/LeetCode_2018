#include <iostream>
#include <stack>
using namespace std;
bool isValid(string s) {
    stack<char> stk;
    for(int i = 0; i < s.size(); i++){
        if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
            stk.push(s[i]);
        }else{ 
            if(!stk.empty() && ((stk.top() == '(' && s[i] == ')') || (stk.top() == '[' && s[i] == ']') || (stk.top() == '{' && s[i] == '}') )){
                stk.pop();
            }else{
                return false;
            }
        }
    }
    return stk.empty();
}


int main(){
    printf("%d\n",isValid("(([])){}"));
    return 0;
}