class Solution {
public:
    vector<string> vs;
    int genParen(int n, int val, string s){
        if (val < 0 ){
            return 0;
        }   
        if (n == 0){
            if (val == 0){
                vs.push_back(s);
                return 1;
            }
            return 0;
        }
        int leftCount = genParen(n-1, val - 1, s + ")");
        int rightCount = genParen(n-1, val + 1, s + "("); 
        return leftCount + rightCount;
    }
    
    vector<string> generateParenthesis(int n) {
        genParen(2*n, 0, "");
        return vs;
    }
};