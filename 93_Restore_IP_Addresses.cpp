#include <iostream>
#include <vector>
using namespace std;
bool isValid(string str){
    if(str.size() >= 2 && str[0] == '0'){
        // avoid leading zero like 01
        return false;
    }
    int num = stoi(str);
    if(num >= 0 && num <= 255){
        return true;
    }else{
        return false;
    }

}
void combine(string s, int begin, vector<string>& cur,vector<vector<string>>& res){
    if(begin == s.size() && cur.size() == 4){
        res.push_back(cur);
        return;
    }else if(begin >= s.size() || cur.size() >= 4){
        return;
    }else{
        string str = s.substr(begin,1);
        if(isValid(str)){
            cur.push_back(str);
            combine(s,begin+1,cur,res);
            cur.pop_back();
        }
        
        if(begin < s.size() - 1){
            str = s.substr(begin,2);
            if(isValid(str)){
                cur.push_back(str);
                combine(s,begin+2,cur,res);
                cur.pop_back();
            }
        }
        
        if(begin < s.size() - 2){
            str = s.substr(begin,3);
            if(isValid(str)){
                cur.push_back(str);
                combine(s,begin+3,cur,res);
                cur.pop_back();
            }
        }

    }
}
vector<string> restoreIpAddresses(string s) {
    vector<vector<string>> res;
    vector<string> cur;
    combine(s,0,cur,res);
    vector<string> ans;
    for(auto vec : res){
        string str;
        for(auto ss : vec){
            str += ss;
            str += '.';
        }
        str.pop_back(); // last .
        ans.push_back(str);
        
    }
    return ans;
}
int main(){
    return 0;
}