//
//  Created by Duo Donald Zhao on 2/18/14.
//  Copyright (c) 2014 Duo Donald Zhao. All rights reserved.
//
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > result;
        int m = (int) num.size();
        if (m < 4)
            return result;
        
        // create a histogram for each single element in the array
        map<int, int> histNum;
        for (int k : num)
            histNum[k]++;
        
        // make a copy of the keys of the hash map histNum
        int n = (int) histNum.size();
        vector<int> numUnique;
        numUnique.reserve(n);
        for (auto &kv : histNum){
            numUnique.push_back(kv.first);
        }
        
        // creat a two-pair sum hash map - 1) non-duplicates
        multimap<int, pair<int, int> > twoSumPair;
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                int ni = numUnique[i];
                int nj = numUnique[j];
                int sum2 = ni + nj;
                twoSumPair.insert({sum2, make_pair(ni, nj)});
            }
        }
        
        // make a copy of the unique sum - 2) for duplicates
        for (int i = 0; i < n; i++){
            if (histNum[numUnique[i]] >= 2){
                int sum2 = 2 * numUnique[i];
                twoSumPair.insert({sum2, make_pair(numUnique[i], numUnique[i])});
            }
        }
        // extract the unique pair sums
        int nSum2 = (int) twoSumPair.size();
        vector<int> sum2Unique;
        sum2Unique.reserve(nSum2);
        int last = sum2Unique[0] + 1;
        for (auto &kv : twoSumPair){
            if (kv.first != last)
                sum2Unique.push_back(kv.first);
            last = kv.first;
            
        }
        
        // search target sum by pairing the pairs, greedy algorithm 
        nSum2 = (int) sum2Unique.size();
        int i = 0;
        int j = nSum2 - 1;
        while (i <= j){
            int sum2i = sum2Unique[i];
            int sum2j = sum2Unique[j];
            int sum4 = sum2i + sum2j;
            if (sum4 == target){
                auto iPairs = twoSumPair.equal_range(sum2i);
                auto jPairs = twoSumPair.equal_range(sum2j);
                for (auto it = iPairs.first; it != iPairs.second; it++) {
                    for (auto jt = jPairs.first; jt != jPairs.second; jt++) {
                        int a = it->second.first;
                        int b = it->second.second;
                        int c = jt->second.first;
                        int d = jt->second.second;
                        if (b < c) {
                            result.push_back({a,b,c,d});
                        }
                        else if (b == c){
                            if (a != b && c != d && histNum[b] >= 2){
                                    result.push_back({a,b,c,d});
                            }
                            else if (a == b && c != d && histNum[b] >= 3) {
                                result.push_back({a,b,c,d});
                            }
                            else if (a != b && c == d && histNum[c] >= 3) {
                                result.push_back({a,b,c,d});
                            }
                            else if (a == b && c == d && histNum[b] >= 4) {
                                result.push_back({a,b,c,d});
                            }
                            
                        }
                    }
                }
                
            }
            if (sum4 <= target) i++;
            if (sum4 >= target) j--;
            
        }
        return result;
        
    }
};