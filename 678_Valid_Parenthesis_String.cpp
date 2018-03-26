#include <iostream>
using namespace std;
// This solution is based on the solution in LeetCode
bool checkValidString(string s) {
    int lo = 0, hi = 0;
    for(char c : s){
        if(c == '('){
            lo++; hi++;
        }else if(c == ')'){
            lo--; hi--;
        }else{
            lo--; hi++;
        }
        if(hi < 0) return false;
        lo = max(lo,0);
    }
    return lo == 0;
}
int main(){
    return 0;
}