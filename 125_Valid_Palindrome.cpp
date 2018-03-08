#include <iostream>
#include <cmath>
using namespace std;
bool isPalindrome(string s) {
    if(s.size() == 0){
        return true;
    }
    int i = 0, j = s.size() - 1;
    while(i < j){
        if(s[i] < 48 || (s[i] > 57 && s[i] < 65) || (s[i] > 90 && s[i] < 97) || s[i] > 122){
            i++;
        }else if(s[j] < 48 || (s[j] > 57 && s[j] < 65)  || (s[j] > 90 && s[j] < 97) || s[j] > 122){
            j--;
        }else if(s[i] >= 65 && ( abs(s[i] - s[j]) == 32 || s[i] == s[j])){
            i++; j--;
        }else if(s[i] == s[j]){
            i++; j--;
        }else{
            return false;
        }
    }
    return true;
}

int main(){
    printf("%d\n",isPalindrome("A man, a plan, a canal: Panama"));
    return 0;
}