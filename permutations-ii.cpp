class Solution {
public:
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
    vector<vector<int> > result;
    void dfs(unordered_map<int, int> &hist, int remaining, vector<int> &trace) {
    	if (remaining == 0) {
    		result.push_back(trace);
    		return;
    	}
    	for (auto &numFreq : hist){
    		if (numFreq.second > 0){
    			numFreq.second--;
    			trace.push_back(numFreq.first);
    			dfs(hist, remaining - 1, trace);
    			trace.pop_back();
    			numFreq.second++;
    		}
    	}
    }
};
