#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> findDuplicates(vector<int>& nums) {
    vector<int> ans;
    for(int i = 0; i < nums.size(); i++){
        int index = abs(nums[i]) - 1;
        if(nums[index] < 0){
            ans.push_back(index+1);
        }else{
            nums[index] *= -1;
        }
    }
    return ans;
}
int main(){
    int myArray[] = {1,2,2,4,5,5,7};
    vector<int> nums(myArray, myArray + sizeof(myArray)/sizeof(int));
    vector<int> ans = findDuplicates(nums);
    for(int num : ans) printf("%d ",num);
    return 0;
}
