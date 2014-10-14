class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        map <char, char> pa;
        pa[')'] = '(';
        pa[']'] = '[';
        pa['}'] = '{';
        for (int i = 0; i < s.length(); i++){
            char c = s[i];
            if (pa.count(c) == 0){
                stk.push(c);
                continue;
            }
            if (stk.size() == 0 || stk.top() != pa[c]){
                return false;
            }
            stk.pop();
        }
        return 0 == stk.size();
    }
};