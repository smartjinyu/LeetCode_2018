#include <iostream>
#include <vector>
using namespace std;
int sgn(int x){
    if(x > 0){
        return 1;
    }else if(x < 0){
        return -1;
    }else{
        return 0;
    }
}
int wiggleMaxLength(vector<int>& nums) {
    if(nums.size() <= 1) return nums.size();
    vector<int> diff(nums.size() - 1,0);
    for(int i = 1; i < nums.size(); i++){
        diff[i - 1] = nums[i] - nums[i-1];
    }
    int len = nums.size();
    for(int i = 0; i < nums.size() - 1;){
        if(sgn(diff[i]) == 0){
            i++;
            len--;
        }else{
            int j = i + 1;
            while(j < nums.size() - 1 && sgn(diff[i]) * sgn(diff[j]) != -1){
                j++; len--;
            }
            i = j;            
        }
    }
    return len;
}
int main(){
    return 0;
}