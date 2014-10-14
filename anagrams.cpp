class Solution {
public:

    vector<string> anagrams (vector<string> &strs) {
        vector<string> result;
        map<vector<int>, string> ec;
        vector<int> histc(26, 0);
        set<string> init;
        int i = 0;
        for (string &s : strs){
            fill (histc.begin(), histc.end(), 0);
            for (char &c : s){
                histc[c - 'a']++;
            }
            if (ec.count(histc) > 0) {
                init.insert(ec[histc]);
                result.push_back(s);
            }
            else{
                ec[histc] = s;
            }
            i++;
        }
        for (string s : init){
            result.push_back(s);
        }
        return result;
    }
};