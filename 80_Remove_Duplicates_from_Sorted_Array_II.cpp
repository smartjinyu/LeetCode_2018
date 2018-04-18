#include <vector>
using namespace std;
int removeDuplicates(vector<int>& nums) {
    if(nums.size() <= 2) return nums.size();
    int j = 1;
    for(int i = 1; i < nums.size(); i++){
        if(j == 1 || (nums[j-2] != nums[i])){
            nums[j++] = nums[i];
        }
    }
    return j;
}
int main(){
    return 0;
}