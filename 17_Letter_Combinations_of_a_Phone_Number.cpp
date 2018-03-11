#include <iostream>
#include <vector>
using namespace std;
void combine(string digits,string curRes,vector<string>& ans, int n){
    if(n == digits.size()){
        ans.push_back(curRes);
        return;
    }else{
        switch(digits[n]){
            case '2': curRes.push_back('a'); combine(digits,curRes,ans,n+1);
                      curRes.pop_back(); curRes.push_back('b'); combine(digits,curRes,ans,n+1);
                      curRes.pop_back(); curRes.push_back('c'); combine(digits,curRes,ans,n+1);
                      break;
            case '3': curRes.push_back('d'); combine(digits,curRes,ans,n+1);
                      curRes.pop_back(); curRes.push_back('e'); combine(digits,curRes,ans,n+1);
                      curRes.pop_back(); curRes.push_back('f'); combine(digits,curRes,ans,n+1);
                      break;
            case '4': curRes.push_back('g'); combine(digits,curRes,ans,n+1);
                      curRes.pop_back(); curRes.push_back('h'); combine(digits,curRes,ans,n+1);
                      curRes.pop_back(); curRes.push_back('i'); combine(digits,curRes,ans,n+1);
                      break;
            case '5': curRes.push_back('j'); combine(digits,curRes,ans,n+1);
                      curRes.pop_back(); curRes.push_back('k'); combine(digits,curRes,ans,n+1);
                      curRes.pop_back(); curRes.push_back('l'); combine(digits,curRes,ans,n+1);
                      break;
            case '6': curRes.push_back('m'); combine(digits,curRes,ans,n+1);
                      curRes.pop_back(); curRes.push_back('n'); combine(digits,curRes,ans,n+1);
                      curRes.pop_back(); curRes.push_back('o'); combine(digits,curRes,ans,n+1);
                      break;
            case '7': curRes.push_back('p'); combine(digits,curRes,ans,n+1);
                      curRes.pop_back(); curRes.push_back('q'); combine(digits,curRes,ans,n+1);
                      curRes.pop_back(); curRes.push_back('r'); combine(digits,curRes,ans,n+1);
                      curRes.pop_back(); curRes.push_back('s'); combine(digits,curRes,ans,n+1);
                      break;
            case '8': curRes.push_back('t'); combine(digits,curRes,ans,n+1);
                      curRes.pop_back(); curRes.push_back('u'); combine(digits,curRes,ans,n+1);
                      curRes.pop_back(); curRes.push_back('v'); combine(digits,curRes,ans,n+1);
                      break;
            case '9': curRes.push_back('w'); combine(digits,curRes,ans,n+1);
                      curRes.pop_back(); curRes.push_back('x'); combine(digits,curRes,ans,n+1);
                      curRes.pop_back(); curRes.push_back('y'); combine(digits,curRes,ans,n+1);
                      curRes.pop_back(); curRes.push_back('z'); combine(digits,curRes,ans,n+1);
                      break;
            default:  combine(digits,curRes,ans,n+1); break;

        }
    }

}
vector<string> letterCombinations(string digits) {
    vector<string> ans;
    string curRes;
    if(digits.size() == 0){
        return ans;
    }
    combine(digits, curRes, ans, 0);
    return ans;
}

int main(){
    vector<string> ans = letterCombinations("23");
    for(string str : ans){
        printf("%s ",str);
    }
    return 0;
}