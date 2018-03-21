#include <iostream>
using namespace std;
int intersect(int afirst, int asecond, int bfirst, int bsecond){
    if(afirst < bfirst){
        if(asecond <= bfirst){
            return 0;
        }else if(bsecond <= asecond){
            return bsecond - bfirst;
        }else{
            return asecond - bfirst;
        }
    }else{
        if(bsecond <= afirst){
            return 0;
        }else if(asecond <= bsecond){
            return asecond - afirst;
        }else{
            return bsecond - afirst;
        }
    }
}
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int area1 = (C-A) * (D-B);
    int area2 = (G-E) * (H-F);
    int overlap = intersect(A,C,E,G) * intersect(B,D,F,H);
    return area1 + area2 - overlap;
    
}
int main(){
    return 0
}