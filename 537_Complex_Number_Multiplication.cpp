#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> parse(string s){
    // "a+bi" -> [a,b]
    int sign = 1, start = 0;
    if(s[start] == '-'){
        sign = -1; start++;
    }
    int i = start;
    while(s[i] != '+' && i < s.size()) i++;
    int a = sign * stoi(s.substr(start,i - start));
    start = i + 1; sign = 1;
    if(s[start] == '-'){
        sign = -1; start++;
    }
    i = start;
    while(s[i] != 'i' && i < s.size()) i++;
    int b = sign * stoi(s.substr(start,i - start));
    vector<int> res;
    res.push_back(a); res.push_back(b);
    return res;
}
string complexNumberMultiply(string a, string b) {
    vector<int> ans1 = parse(a);
    vector<int> ans2 = parse(b);
    int real = ans1[0] * ans2[0] - ans1[1] * ans2[1];
    int imagine = ans1[0] * ans2[1] + ans1[1] * ans2[0];
    string str = to_string(real) + '+' + to_string(imagine) + 'i';
    return str;
}
int main(){
    return 0;
}
