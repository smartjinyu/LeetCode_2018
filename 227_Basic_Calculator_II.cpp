#include <iostream>
#include <stack>
#include <cmath>
using namespace std;
int calculate(string s) {
    if(s.size() == 0) return 0;
    stack<int> num;
    stack<char> op;
    for(int i = 0; i < s.size(); i++){
        char c = s[i];
        if(c >= '0' && c <= '9'){
            int nums = (int)c - '0';
            int j = i;
            while(j < s.size() - 1 && s[j + 1] >= '0' && s[j + 1] <= '9'){
                j++;
                nums = nums * 10 + (int)s[j] - '0';
            }
            i = j;
            num.push(nums);
        }else if(c == '+' || c == '-'){
            if(!op.empty()){
                int num1 = num.top(); num.pop();
                int num2 = num.top(); num.pop();
                int ans = 0;
                if(op.top() == '+'){
                    ans = num1 + num2;
                }else if(op.top() == '-'){
                    ans = (num2 - num1);
                }
                num.push(ans);
                op.pop(); 
            }
            op.push(c);
        }else if(c == '*'){
            int num1 = num.top(); num.pop();
            int j = i + 1;
            while(j < s.size() && s[j] == ' ') j++;
            int num2 = (int)s[j] - '0';
            while(j < s.size() - 1 && s[j + 1] >= '0' && s[j + 1] <= '9'){
                j++;
                num2 = num2 * 10 + (int)s[j] - '0';
            }

            num.push(num1 * num2);
            i = j;
        }else if(c == '/'){
            int num1 = num.top(); num.pop();
            int j = i + 1;
            while(j < s.size() && s[j] == ' ') j++;
            int num2 = (int)s[j] - '0';
            while(j < s.size() - 1 && s[j + 1] >= '0' && s[j + 1] <= '9'){
                j++;
                num2 = num2 * 10 + (int)s[j] - '0';
            }
            num.push(num1 / num2);
            i = j;
        }
    }
    if(!op.empty()){
        int num1 = num.top(); num.pop();
        int num2 = num.top(); num.pop();
        int ans = 0;
        if(op.top() == '+'){
            ans = num1 + num2;
        }else if(op.top() == '-'){
            ans = (num2 - num1);
        }
        num.push(ans);
        op.pop(); 
    }
    return num.top();
}

int main(){
    printf("%d\n",calculate("1+9/10"));
    return 0;
}