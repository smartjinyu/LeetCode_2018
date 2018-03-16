#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int thirdMax(vector<int>& nums) {
    long long first = LLONG_MIN, second = LLONG_MIN, third = LLONG_MIN;
    for(int num : nums){
        if(num > first){
            third = second;
            second = first;
            first = num;
        }else if(num < first && num > second){
            third = second;
            second = num;
        }else if(num < second && num > third){
            third = num;
        }
    }
    if(third == LLONG_MIN){
        return first;
    }else{
        return third;
    }
}

int main(){
    int myArray[] = {1,2,-2147483648};
    vector<int> nums(myArray, myArray + sizeof(myArray)/sizeof(int));
    printf("%d\n",thirdMax(nums));
    return 0;
}