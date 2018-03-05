#include <iostream>
#include <vector>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
    int len = 0;
    if (strs.size() == 0){
        return "";
    }
    if (strs.size() == 1){
        return strs[0];
    }
    bool flag = true;
    while (flag){
        char c = strs[0][len];
        for (int i = 1; i < strs.size(); i ++){
            if(len >= strs[i].size() || strs[i][len] != c){
                flag = false;
            }
        }
        len++;
    }
    string result = strs[0].substr(0,len-1);
    return result;
}

int main(){
    vector<string> strs;
    strs.push_back("Iamagenius");
    strs.push_back("Iamaguui");
    strs.push_back("Iamageef");
    cout << longestCommonPrefix(strs) << endl;
    return 0;
}