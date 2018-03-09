#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int twoPows[26] ={0};
long long calHash(string str){
    long long ans = 0;
    // similar to binary number
    for(int i = 0; i < str.size(); i++){
        ans += twoPows[(int)str[i] - 97];
    }
    return ans;
}
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    twoPows[0] = 1;
    for(int i = 1; i < 26 ;i++){
        twoPows[i] = 17*twoPows[i-1];
    } // initialize
    unordered_map<long long,int> vectorIndex;
    vector<vector<string>> ans;
    vector<string> ep; ans.push_back(ep); 
    // avoid the problem that initial value of vector index is 0
    long long curHash;
    for(string str : strs){
        curHash = calHash(str);
        if(vectorIndex[curHash] == 0){
            vector<string> ss; ss.push_back(str);
            ans.push_back(ss);
            vectorIndex[curHash] = ans.size() - 1;
        }else{
            ans[vectorIndex[curHash]].push_back(str);
        }
    }
    vector<vector<string>> ans0(&ans[1],&ans[ans.size()]);
    return ans0;

}

int main(){
    vector<string> str;
    str.push_back("eat"); str.push_back("tea"); str.push_back("tan"); 
    str.push_back("ate"); str.push_back("nat"); str.push_back("bat");
    printf("huh = %ld, h = %ld, u = %ld\n",calHash("huh"),calHash("h"),calHash("u"));
    printf("tit = %ld, t = %ld, i = %ld\n",calHash("tit"),calHash("i"),calHash("t"))
    vector<vector<string>> ans = groupAnagrams(str);
    for(vector<string> vec : ans){
        for(string s : vec){
            printf("%s ",s);
        }
        printf("\n");
    }
    return 0;
}