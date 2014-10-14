class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int distToTarget = numeric_limits<int>::max();
        int result = -10;
        if (num.size() < 3){
            return result;
        }
        
        map<int, int> hist;
        for (int k : num)
            hist[k]++;
        
        int n = (int) hist.size();
        
        vector<int> v;
        v.reserve(n);
        
        for(auto &p : hist){
            v.push_back(p.first);
        }
        for (int i = 0; i < n; i++){
            int fi = hist[v[i]];
            int j = (fi >= 2) ? i : i+1;
            int k = n - 1;
            while (j < k || 
                   (j == k && j != i && hist[v[j]] >= 2) ||
                   (i == j && i == k && hist[v[j]] >= 3) 
                ) {
                int triSum = v[i] + v[j] + v[k];
                int triDiff = triSum - target;
                if (triDiff == 0) 
                    return target;
                if (abs(triDiff) < distToTarget){
                    distToTarget = abs(triDiff);
                    result = triSum;
                }
                if (triDiff <= 0) j++;
                if (triDiff >= 0) k--;
            
            }
        }
        return result;
    }
};  