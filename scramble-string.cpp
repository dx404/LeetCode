class Solution {
public:
    map<pair<string, string>, bool> memo;
    
    bool isScramble(string s1, string s2) {
        if (s1 == s2){
            return true;
        }
            
        if (s1.size() != s2.size())
            return false;
        
        if (memo.count({s1, s2})){
            return memo[{s1, s2}];
        }
        
        map<char, int> hist;
        for (char c : s1) hist[c]++;
        for (char c : s2){
            hist[c]--;
            if (hist[c] < 0){
                return memo[{s1, s2}] = false;
            }
        }

        int n = s1.size();
        bool status = false;
        for (int i = 0; i <= n - 2; i++){
            string s1a = s1.substr(0, i + 1);
            string s1b = s1.substr(i + 1, n - i - 1);
            string s2a0 = s2.substr(0, i + 1);
            string s2b0 = s2.substr(i + 1, n - i - 1);
            string s2a = s2.substr(0, n - i - 1);
            string s2b = s2.substr(n - i - 1, i + 1);
            status = (isScramble(s1a, s2a0) && isScramble(s1b, s2b0)) ||
                    (isScramble(s1a, s2b) && isScramble(s2a, s1b)) ;
            if (status){
                break;
            }
        }
        return memo[{s1, s2}] = status;
    }
};

