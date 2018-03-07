#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <functional>
using namespace std;
// This solution is in reference to the discuss in LeetCode
vector<int> topKFrequent(vector<int>& nums, int k) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int, int>>> pq; // the smallest is on the top
    unordered_map<int,int> um;
    for(int num : nums){
        um[num]++;
    }
    vector<int> res;
    for(auto p : um){
        pq.push({p.second,p.first});
        while(pq.size() > k){
            pq.pop();
        }
    }
    while(!pq.empty()){
        res.push_back(pq.top().second);
        pq.pop();
    }
    return res;
}

int main(){
    int myArray[] = {1,1,2,2,2,3,3,3,3,4};
    vector<int> nums(myArray,myArray + sizeof(myArray)/sizeof(int));
    vector<int> res = topKFrequent(nums,2);
    for(int i = 0; i < res.size(); i++){
        printf("%d ",res[i]);
    }
    return 0;
}
