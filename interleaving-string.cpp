class Solution {
public:
    string s1, s2, s3;
    int n1, n2, n3;
    map<pair<int, int>, bool> mp;
    bool isInterleave(string s1, string s2, string s3) {
       this->s1 = s1;
       this->s2 = s2;
       this->s3 = s3;
       n1 = s1.length();
       n2 = s2.length();
       n3 = s3.length();
       if (n1 + n2 != n3){
           return false;
       }
       return isInterleave(0, 0);
       
    }
private: 
    bool isInterleave(int i, int j){
        int k = i + j;
        pair<int, int> ij = make_pair(i, j);
        if (mp.count(ij) > 0){
            return mp[ij];
        }
        
        if (i == n1 && j == n2 && k == n3){
            return mp[ij] = true;
        }
        char c1 = (i < n1) ? s1[i] : '\0';
        char c2 = (j < n2) ? s2[j] : '\0';
        char c3 = (k < n3) ? s3[k] : '\0';
        if (c1 == c3 && c2 == c3){
            return mp[ij] = isInterleave(i, j+1) || isInterleave(i+1, j);
        }
        else if (c1 == c3 && c2 != c3){
            return mp[ij] = isInterleave(i+1, j);
        }
        else if (c1 != c3 && c2 == c3){
            return mp[ij] = isInterleave(i, j+1);
        }
        else {
            return mp[ij] = false;
        }
    }
};