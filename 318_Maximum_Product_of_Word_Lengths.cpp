#include <iostream>
#include <vector>
using namespace std;
// This solution is based on the discuss in LeetCode
int maxProduct(vector<string>& words) {
    if(words.size() <= 1) return 0;
    vector<int> um(words.size(),0);
    int code = 0;
    for(int i = 0; i < words.size(); i++){
        code = 0;
        for(char c : words[i]){
            code |= (1 << (c - 'a'));
        }
        um[i] = code;
    }
    int ans = 0;
    for(int i = 0; i < words.size(); i++){
        for(int j = i + 1; j < words.size(); j++){
            if((um[i] & um[j]) == 0){
                ans = max(ans,(int)(words[i].size() * words[j].size()));
            }
        }
    }
    return ans;
}

int main(){
    return 0;
}