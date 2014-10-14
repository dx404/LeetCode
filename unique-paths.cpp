class Solution {
public:
    map<tuple<int, int>, int> t;
    int uniquePaths(int m, int n) {
        tuple<int, int> mn = make_tuple(m, n);
        if (m == 1 || n == 1) 
            return 1;
        if (t.count(mn) > 0){
            return t[mn];
        }
        return t[mn] = uniquePaths(m-1, n) + uniquePaths(m, n-1);
    }
};