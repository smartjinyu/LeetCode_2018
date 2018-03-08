#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// This solution is in reference to the discuss in LeetCode
int maxArea(vector<int>& height) {
    int curHeight = 0;
    int ans = 0;
    int i = 0, j = height.size() - 1;
    while(i < j){
        curHeight = min(height[i],height[j]);
        ans = max(ans,curHeight * (j-i));
        while(i < j && height[i] <= curHeight) i++;
        while(i < j && height[j] <= curHeight) j--;
    }
    return ans;

}

int main(){
    int myArray[] = {4,2,3,1,8,2};
    vector<int> height(myArray,myArray + sizeof(myArray)/sizeof(int));
    printf("%d\n",maxArea(height));
    return 0;
}