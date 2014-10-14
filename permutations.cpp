class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> > r;
        do{
            r.push_back(num);
        }
        while (next_permutation(num.begin(), num.end()));
        return r;
    }
};