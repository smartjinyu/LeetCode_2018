#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> generate(int numRows) {
    static vector<vector<int>> ans;
    if(ans.size() == 0){
        vector<int> ss; ss.push_back(1);
        ans.push_back(ss);
    }

    if(numRows == 0){
        vector<vector<int>> res;
        return res;
    }else if(ans.size() >= numRows){
        vector<vector<int>> res(&ans[0],&ans[numRows]); 
        return res;
    }else{
        for(int i = ans.size(); i < numRows; i++){
            vector<int> temp; temp.push_back(1);
            for(int j = 1; j < i; j++){
                temp.push_back(ans[i-1][j-1] + ans[i-1][j]);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
}

int main(){
    vector<vector<int>> res = generate(2);
    for(vector<int> vec : res){
        for(int num : vec){
            printf("%d ",num);
        }
        printf("\n");
    }
    return 0;
}