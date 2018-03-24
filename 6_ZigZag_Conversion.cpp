#include <iostream>
#include <vector>
using namespace std;
string convert(string s, int numRows) {
    if(s.size() <= 1 || numRows <= 1 ) return s;
    vector<char> ans;
    int len2 = 2*numRows - 2;
    for(int i = 0; i < numRows; i++){
        int index = i;
        int len3 = len2;
        while(index < s.size()){
            ans.push_back(s[index]);
            if(i != 0 && i != numRows-1){
                index = len3 - i;
                if(index < s.size()) ans.push_back(s[index]);
            }
            index = len3 + i;
            len3 += len2;
        }
    }
    string str(ans.begin(),ans.end());
    return str;
}
int main(){
    return 0;
}