class Solution {
public:
    vector<vector<int> > rc;
    vector<int> t;
    
    vector<vector<int> > combine(int n, int k) {
        combine(1, n, k);
        return rc;
    }
    
private:
    void combine(int start, int end, int k){ //both inclusive
        if ( k > end - start + 1){
            return;
        }
        if (k == 0){
            rc.push_back(t);
            return;
        }
        
        for (int i = start; i <= end - k + 1; i++){
            t.push_back(i);
            combine(i+1, end, k-1);
            t.pop_back();
        }
    }
};