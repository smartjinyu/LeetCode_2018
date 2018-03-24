#include <iostream>
#include <vector>
using namespace std;
bool checkPossibility(vector<int>& nums) {
    if(nums.size() <= 2) return true;
    int index, ni,ni1;
    for(int i = 0; i < nums.size() - 1; i++){
        if(nums[i] > nums[i+1]){
            index = i;
            ni = nums[i];
            ni1 = nums[i+1];
            nums[i+1] = nums[i];
            break;
        }
    }
    bool flag = true;
    for(int i = 0; i < nums.size() - 1; i++){
        if(nums[i] > nums[i+1]){
            flag = false;
            break;
        }
    }
    if(flag){
        return true;
    }else{
        nums[index] = ni1;
        nums[index+1] = ni1;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] > nums[i+1]){
                return false;
            }
        }
        return true;
    }
}

int main(){
    return 0;
}