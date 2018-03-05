#include <iostream>
#include <cmath>
using namespace std;
int mySqrt(int x) {
    // use Newton's method
    if (x == 0){
        return 0;
    }
    double x_0 = x + 1, x_1 = x;
    while(abs(x_0 - x_1) > 0.00001){
        x_0 = x_1;
        x_1 = (x_0 * x_0 + double(x))/(2*x_0);
    }
    return x_0;
}

int main(){
    printf("%d\n",mySqrt(2147395599));
    return 0;
}