#include <iostream>
#include <vector>
using namespace std;
// This solution is in reference to the discuss section in LeetCode
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p = m - 1;
    int q = n - 1;
    for (int i = m + n - 1; i >= 0; i--){
        if(p != -1 && (q == -1 || nums1[p] >= nums2[q])){
            nums1[i] = nums1[p--];
        }else{
            nums1[i] = nums2[q--];
        }
    }
}

int main(){
    int myArray1[] = {1,3,5,9,11}; int m = 5;
    int myArray2[] = {-2,4,6,7,10,11,12}; int n = 7;
    vector<int> nums1(myArray1, myArray1 + sizeof(myArray1)/sizeof(int));
    vector<int> nums2(myArray2, myArray2 + sizeof(myArray2)/sizeof(int));
    nums1.resize(m+n);
    merge(nums1,m,nums2,n);
    for (int i = 0; i < nums1.size(); i++){
        printf("%d ",nums1[i]);
    }
    return 0;
}