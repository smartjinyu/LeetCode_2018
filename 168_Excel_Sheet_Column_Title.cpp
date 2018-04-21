#include <iostream>
#include <vector>
using namespace std;
string convertToTitle(int n) {
    vector<char> ans;
    int remainder = 0;
    while(n != 0){
        remainder = n % 26;
        n /= 26;
        if(remainder == 0){
            ans.push_back('Z');
            n--;
        }else{
            ans.push_back((char)('A' + remainder - 1));
        }
        
    }
    reverse(ans.begin(), ans.end());
    string str(ans.begin(),ans.end());
    return str;
}

int main(){
    return 0;
}
