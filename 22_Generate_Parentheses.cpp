#include <iostream>
#include <vector>
using namespace std;
void addPar(int left, int right,string str, vector<string>& ans){
    if(left == 0 && right == 0){
        ans.push_back(str);
    }else{
        if(left > 0) addPar(left-1, right, str+"(",ans);
        if(right > left) addPar(left,right-1,str+")",ans);
    }
}
vector<string> generateParenthesis(int n) {
    vector<string> ans;
    if(n == 0){
        return ans;
    }else{
        addPar(n,n,"",ans);
        return ans;
    }
}

int main(){
    vector<string> ans = generateParenthesis(5);
    for(string str : ans){
        printf("%s\n",str);
    }
    return 0;
}