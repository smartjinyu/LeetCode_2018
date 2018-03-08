#include <iostream>
#include <vector>
using namespace std;
// This solution needs supplementary code to run
class NestedIterator {
public:
    vector<int> result;
    int curIndex;
    NestedIterator(vector<NestedInteger> &nestedList) {
        curIndex = 0;
        flatten(nestedList);
    }

    int next() {
        return result[curIndex++];
    }

    bool hasNext() {
        return curIndex < result.size();
        
    }
    void flatten(vector<NestedInteger> &nestedList){
        for(NestedInteger ni : nestedList){
            if(ni.isInteger()){
                result.push_back(ni.getInteger());
            }else{
                flatten(ni.getList());
            }
        }
    }
};

int main(){
    return 0;
}
