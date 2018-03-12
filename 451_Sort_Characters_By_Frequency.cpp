#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// This solution is in reference to the discuss in LeetCode
string frequencySort(string s) {
    if(s.size() < 2) return s;
    unordered_map<char,int> um;
    vector<string> bucket(s.size()+1,"");
    for(char c : s) um[c]++;
    for(auto& p : um){
        int n = p.second;
        char c = p.first;
        bucket[n].append(n,c);
    }
    string ans;
    for(int i = bucket.size() - 1; i > 0; i--){
        if(!bucket[i].empty()){
            ans.append(bucket[i]);
        }
    }
    return ans;
}

int main(){
    printf("%s\n",frequencySort("LeetCodeooo"));
    return 0;
}