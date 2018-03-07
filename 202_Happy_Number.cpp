#include <iostream>
#include <unordered_map>
using namespace std;
int getSum(int n){
    int ans = 0;
    while(n >= 10){
        ans += (n%10) * (n%10);
        n /= 10;
    }
    ans += n*n;
    return ans;
}
bool isHappy(int n) {
    unordered_map<int,int> res;
    int temp = n;
    while(true){
        if(temp == 1){
            return true;
        }else if(res[temp] > 0){
            return false;
        }else{
            res[temp]++;
        }
        temp = getSum(temp);
    }
}

int main(){
    printf("20 is %d, 19 is %d\n",isHappy(20),isHappy(19));
    return 0;
}