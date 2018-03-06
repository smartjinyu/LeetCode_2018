#include <iostream>
using namespace std;
string reverseString(string s) {
    string ans;
    for (int i = 0; i < s.size(); i++){
        ans.push_back(s[s.size() - 1 -i]);
    }
    return ans;
}

int main(){
    printf("%s\n",reverseString("hello"));
    return 0;
}