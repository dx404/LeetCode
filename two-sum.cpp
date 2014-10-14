class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        unordered_map<int, int> memo;
        int n = numbers.size();
        for (int i = 0; i < n; i++) {
            if (memo.count(target - numbers[i])) {
                return {memo[target - numbers[i]] + 1, i + 1};
            }
            memo[numbers[i]] = i;
        }
        return result;
    }
};