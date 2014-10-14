class Solution {
public:
	vector<vector<int> > result;
	vector<vector<int> > combinationSum2(vector<int> &nums, int target) {
		sort(nums.begin(), nums.end());
		vector<int> trace;
		dfs(nums, target, 0, trace);
		return result;
	}
	void dfs(vector<int> &nums, int gap, int start, vector<int> &trace) {
		if (gap == 0) {
			result.push_back(trace);
			return;
		}
		int previous = nums[start] - 1;
		for (int i = start; i < nums.size(); i++) {
			if (previous == nums[i]) // for duplicates
			    continue;
			if (gap < nums[i]) 
			    return; 
			previous = nums[i];
			trace.push_back(nums[i]);
			dfs(nums, gap - nums[i], i + 1, trace);
			trace.pop_back();
		}
	}
};