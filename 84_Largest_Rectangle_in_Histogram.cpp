#include <iostream>
#include <vector>
using namespace std;
// This solution is based on the discuss in LeetCode
int largestMid(vector<int>& heights, int start, int mid, int end){
    // find the largest area including heights[mid]
    if(start == end) return heights[start];
    int area = heights[mid];
    int h = heights[mid];
    int l = mid, r = mid;
    while(true){
        if(l == start && r == end){
            break;
        } else if(l == start){
            r++;
            h = min(h, heights[r]);
        } else if(r == end){
            l--;
            h = min(h, heights[l]);
        }else{
            if(heights[l-1] < heights[r+1]){ 
                r++;
                h = min(h, heights[r]);
            } else{ 
                l--;
                h = min(h, heights[l]);
            }
        }
        area = max(area, h * (r - l + 1));
    }
    return area;
}
int divideAndConquer(vector<int>& heights, int start, int end){
    // find the largest area in heights [start, end]
    if(start == end) return heights[start];
    int mid = (start + end) / 2;
    int area1 = divideAndConquer(heights, start, mid);
    int area2 = largestMid(heights, start, mid, end);
    int area3 = divideAndConquer(heights, mid + 1, end);
    return max(area1, max(area2, area3));
}
int largestRectangleArea(vector<int>& heights) {
    if(heights.size() == 0) return 0;
    if(heights.size() == 1) return heights[0];
    return divideAndConquer(heights, 0, heights.size() - 1);
}

int largestRectangleArea2(vector<int>& heights) {
        if(heights.size() == 0) return 0;
        if(heights.size() == 1) return heights[0];
        stack<int> sk;
        int l, h;
        int maxArea = 0;
        heights.push_back(0); // for last computation
        for(int i = 0; i < heights.size(); i++){
            while(!sk.empty() && heights[sk.top()] >= heights[i]){
                h = heights[sk.top()]; sk.pop();
                l = sk.empty() ? -1 : sk.top();
                maxArea = max(maxArea, h * (i - l - 1));
            }
            sk.push(i);
        }
        return maxArea;
    }

 int main(){
     return 0;
 }