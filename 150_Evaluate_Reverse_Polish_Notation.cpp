#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> nums;
    for(string str : tokens){
        if(str.size() == 1 && str[0] == '+'){
            if(!nums.empty()){
                int num1 = nums.top(); nums.pop();
                int num2 = nums.top(); nums.pop();
                nums.push(num1 + num2);
            }
        } else if(str.size() == 1 && str[0] == '-'){
            if(!nums.empty()){
                int num1 = nums.top(); nums.pop();
                int num2 = nums.top(); nums.pop();
                nums.push(num2 - num1);
            }
        } else if(str.size() == 1 && str[0] == '*'){
            if(!nums.empty()){
                int num1 = nums.top(); nums.pop();
                int num2 = nums.top(); nums.pop();
                nums.push(num1 * num2);
            }
        } else if(str.size() == 1 && str[0] == '/'){
            if(!nums.empty()){
                int num1 = nums.top(); nums.pop();
                int num2 = nums.top(); nums.pop();
                nums.push(num2 / num1);
            }
        } else{
            int num = stoi(str);
            nums.push(num);
        }
    }
    return nums.top();
}

int main(){
    vector<string> tokens;
    tokens.push_back("2"); tokens.push_back("1"); 
    tokens.push_back("+"); tokens.push_back("-3"); tokens.push_back("*");
    printf("%d\n",evalRPN(tokens));
    return 0;
}