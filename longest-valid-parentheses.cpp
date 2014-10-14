class Solution {
public:
    int longestValidParentheses(string s) {
        int n = (int) s.length();
        stack<int> memo; 
        memo.push(-1);
        int longestSoFar = 0;
        for (int i = 0; i < n; i++){
            if (s[i] == '(')
                memo.push(i);
            else{
                if (memo.size() > 1) {
                    memo.pop();
                    longestSoFar = max(longestSoFar, i - memo.top());
                }
                else{
                    memo.top() = i;
                }
            }
        }
        return longestSoFar;
    }
};