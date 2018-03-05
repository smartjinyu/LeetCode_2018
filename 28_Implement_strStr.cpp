#include <iostream>
using namespace std;
int strStr(string haystack, string needle) {
    if (needle == ""){
        return 0;
    }
    for(int i = 0; i < haystack.size(); i++){
        if(haystack[i] == needle[0]){
            bool flag = true;
            for(int j = 1; j < needle.size(); j++){
                if(needle[j] != haystack[i+j]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                return i;
            }
        }
    }
    return -1;
}

int main(){
    printf("%d\n",strStr("ll","ll"));
    return 0;
}