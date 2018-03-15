#include <iostream>
#include <vector>
using namespace std;
void nextPermutation(vector<int>& nums) {
    bool changed = false;
    int n = nums.size() - 1;
    int max = nums[n]; int lo = -1;
    int min = -1; int index = -1;
    for(int i = n - 1; i >= 0; i--){
        if(nums[i] < max){
            min = max;
            for(int j = i+1; j <= n; j++){
                if(nums[j] > nums[i] && nums[j] <= min){
                    index = j;
                    min = nums[j];
                }
            }
            swap(nums[i],nums[index]);
            lo = i;
            break;
        }else{
            max = nums[i];
        }
    }
    sort(nums.begin()+lo+1, nums.end());
}
int main(){
    return 0;
}