class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxSoFar = 0;
        int maxEndHere = 0;
        unordered_map<char,int> last;
        for (int i = 0; i < n; i++){
            char c = s[i];
            maxEndHere = (last.count(c) == 0 || last[c] < i - maxEndHere) ? 
                         maxEndHere + 1 :  i - last[c];
            maxSoFar = max(maxSoFar, maxEndHere);
            last[c] = i;
        }
        return maxSoFar;
    }
};