#include <iostream>
using namespace std;
int minDistance(string word1, string word2) {
    if(word1.size() == 0) return word2.size();
    if(word2.size() == 0) return word1.size();
    int dp[501][501];
    // longest common string
    for(int i = 1; i <= word1.size(); i++){
        for(int j = 1; j <= word2.size(); j++){
            if(word1[i-1] == word2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);                       
            }
        }
    }
    printf("maxlen = %d, word1 = %d, word2 = %d\n",dp[word1.size()][word2.size()],word1.size(),word2.size());
    return word1.size() + word2.size() - 2 * dp[word1.size()][word2.size()];
}
int main(){
    return 0;
}