#include <iostream>
#include <stack>
#include <vector>
using namespace std;
    string decodeString(string s) {
        stack<char> sk; vector<char> temp;
        for(char c : s){
            if(c != ']'){
                sk.push(c);
            }else{
                char ck = sk.top();
                while(ck != '['){
                    temp.push_back(ck);
                    sk.pop(); ck = sk.top();
                }
                sk.pop(); // '['
                int times = 0, base = 1;
                ck = sk.top();
                while(ck >= '0' && ck <= '9' ){
                    times += base * ((int)ck - '0');
                    base *= 10;
                    sk.pop(); 
                    if(sk.empty()) break;
                    ck = sk.top();
                } // number may have several digits
                for(int i = 0; i < times; i++){
                    for(int i = temp.size() - 1; i >= 0; i--){
                        sk.push(temp[i]);
                    }
                }
                temp.clear();
            }
        }
        string str(sk.size(),'0');
        for(int i = sk.size() - 1; i >= 0; i--){
            str[i] = sk.top(); sk.pop();
        }
        return str;

    }

int main(){
    printf("%s\n",decodeString("3[a2[c]]"));
    return 0;
}