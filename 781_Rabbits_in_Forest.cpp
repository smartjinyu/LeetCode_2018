#include <iostream>
#include <vector>
using namespace std;
int numRabbits(vector<int>& answers) {
    if(answers.size() == 0) return 0;
    int table[1001] = {0};
    int ans = 0;
    for(int num : answers){
        if(table[num] == 0){
            table[num] = num;
            ans += (num + 1);
        }else{
            table[num]--;
        }
    }
    return ans;
}
int main(){
    return 0;
}