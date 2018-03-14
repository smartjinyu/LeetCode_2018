#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// This solution is in reference to the discuss in LeetCode
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

static bool comp(const Interval& a, const Interval& b){
    if(a.start == b.start) return a.end < b.end;
    else return (a.start < b.start);
}
vector<Interval> merge(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), comp);
    vector<Interval> ans;
    if(intervals.size() == 0) return ans;
    ans.push_back(intervals[0]);
    for(int i = 1; i < intervals.size(); i++){
        if(intervals[i].start > ans[ans.size() - 1].end){
            ans.push_back(intervals[i]);
        }else{
            ans[ans.size() - 1].end = max(ans[ans.size() - 1].end,intervals[i].end);
        }
    }
    return ans;
}

int main(){
    return 0;
}