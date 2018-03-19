#include <vector>
#include <algorithm>
using namespace std;
vector<int> partitionLabels(string S) {
    vector<int> res;
    if(S.size() <= 1){
        res.push_back(res.size());
        return res;
    }
    vector<int> last(26,-1);
    for(int i = 0; i < S.size(); i++){
        last[(int)S[i] - 'a'] = max(last[(int)S[i] - 'a'],i);
    }
    for(int i = 0; i < S.size(); ){
        int j = last[(int)S[i] - 'a'];
        int right = j;
        for(int k = i + 1; k <= right; k++){
            right = max(right,last[(int)S[k]-'a']);
        }
        res.push_back(right-i+1);
        i = right + 1;
    }
    return res;
}
int main(){
    return 0;
}