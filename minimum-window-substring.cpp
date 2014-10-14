class Solution {
public:
    string minWindow(string S, string T) {
        string result = "";
        int n = (int) S.length();
        unordered_map<char, int> hist;
        for (auto c : T) hist[c]++;
        int memoCount = hist.size();
        int iBest = 0, lenBest = n + 1;
        for (int i = 0, j = 0; j < n; j++) {
            hist[S[j]]--; // inclusive
            if (hist[S[j]] == 0) 
                memoCount--; 
            if(memoCount) 
                continue;
            while (hist[S[i]]) { // < 0
                hist[S[i]]++;
                i++;
            }
            if (j - i + 1 < lenBest) {
                iBest = i;
                lenBest = j - i + 1;
            }
        }
        return lenBest <= n ? S.substr(iBest, lenBest) : "";
    }
};
