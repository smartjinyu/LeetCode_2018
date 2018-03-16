#include <iostream>
#include <vector>
using namespace std;
// The dicuss section in LeetCode has a much better solution
void lineup(vector<pair<int, int>>& people, vector<int>& num, vector<pair<int, int>>& res){
    if(res.size() == people.size()) return;
    pair<int,int> min{INT_MAX,0}; int index = 0;
    for(int i = 0; i < people.size(); i++){
        if(num[i] == 0 && people[i].first < min.first){ min = people[i]; index = i;}
    }
    num[index] = -1; // flag this pair is used
    res.push_back(min);
    for(int i = 0; i < people.size(); i++){
        if(num[i] != -1 && people[i].first <= min.first){
            num[i]--;
        }
    }
    lineup(people,num,res);
    
}
vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
    if(people.size() <= 2) return people;
    vector<int> num;
    for(auto p : people){
        num.push_back(p.second);
    }
    vector<pair<int,int>> res;
    lineup(people,num,res);
    return res;
}
int main(){
    return 0;
}