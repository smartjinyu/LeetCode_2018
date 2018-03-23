#include <iostream>
using namespace std;
// This solution is based on the solution in LeetCode
int reachNumber(int target) {
    if(target == 0) return 0;
    target = abs(target);
    if(target == 1) return 1;
    int k = 1, sum = 0;
    while(sum < target){
        sum += k; k++;
    }
    while((sum-target)%2 != 0){
        sum += k; k++;
    }
    return k-1;
}

int main(){
    return 0;
}