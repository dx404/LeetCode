class MiniSet {
public:
    bool inSet(int x){
        return repTable.count(x) > 0 ? true : false;
    }
    
    void makeSet(int x) {
        if (repTable.count(x) == 0)
            repTable[x] = {x, 0};
    }
    
    int findSet(int x) {
        int &xRep = repTable[x].first;
        if (x != xRep){
            xRep = findSet(xRep);
        }
        return xRep;
    }
    
    void merge(int x, int y) {
        link(findSet(x), findSet(y));
    }
    
    int getMostFrequency(){
        int maxFre = numeric_limits<int>::min();
        for (auto &info : repTable){
            setCount[findSet(info.first)]++;
        }
        for (auto &xf: setCount){
            maxFre = max(maxFre, xf.second);
        }
        return maxFre;
    }
    
private: 
    unordered_map<int, pair<int, int> > repTable;
    unordered_map<int, int> setCount;
    
    void link(int x, int y) {
        int &xrank = repTable[x].second;
        int &yrank = repTable[y].second;
        if (xrank > yrank){
            repTable[y].first = x;
        }
        else {
            repTable[x].first = y;
            if (xrank == yrank) yrank++;
        }
    }

};

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        MiniSet ms;
        for (int x : num){
            ms.makeSet(x);
        }
        for (int x : num){
            if (ms.inSet(x-1)){
                ms.merge(x, x-1);
            }
            if (ms.inSet(x+1)){
                ms.merge(x, x+1);
            }
        }
        return ms.getMostFrequency();
    }
};