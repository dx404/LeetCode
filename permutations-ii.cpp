class Solution {
public:
    vector<vector<int> > result;
    vector<vector<int> > permuteUnique(vector<int> &num) {
        unordered_map<int, int> hist;
    	int total = 0;
    	for (int x : num) {
    	    hist[x]++;
    	    total++;    
    	}
    	vector<int> trace;
    	dfs(hist, total, trace);
    	return result;
    }
    void dfs(unordered_map<int, int> &hist, int total, vector<int> &trace) {
    	if (total == 0) {
    		result.push_back(trace);
    		return;
    	}
    	for (auto &kv : hist){ // pair <kv.first, kv.second>
    		if (kv.second > 0){
    			kv.second--;
    			trace.push_back(kv.first);
    			dfs(hist, total - 1, trace);
    			trace.pop_back();
    			kv.second++;
    		}
    	}
    }
};