class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string sum = "";
        int na = (int) a.length();
        int nb = (int) b.length();
        int n = max(na, nb) + 1;
        bool dc = 0;
        for (int i = 0; i < n; i++){
            bool da = (i >= na || a[i] == '0') ? 0 : 1;
            bool db = (i >= nb || b[i] == '0') ? 0 : 1;
            bool s = da ^ db ^ dc;
            sum = char(s + 48) + sum;
            dc = (da & db) | (dc & (da ^ db));
        }
        if (sum.length() > 0 && sum[0] == '0'){
            return sum.substr(1);
        }
        return sum;
    }
};