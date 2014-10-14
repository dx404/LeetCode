class Solution {
public:
    vector<vector<string> > result;
    vector<string> trace;
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        dict.insert(start);
        queue<string> *q = new queue<string> ();
        queue<string> *qNext =  new queue<string> ();
        unordered_set<string> qSet, qNextSet;
        q->push(end);
        qSet.insert(end);
        multimap<string, string> from;
        int level = 1, levelCap = numeric_limits<int>::max();
        while (!q->empty() && level < levelCap) {
            const string &sRecord = q->front();
            string s = q->front();
            for (int i = 0; i < s.size(); i++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    char si = s[i];
                    if (si != c) {
                        s[i] = c;
                        if (s == start)
                            levelCap = level + 1;
                        if (dict.count(s) && !qSet.count(s)) {
                            from.insert({s, sRecord});
                            if (!qNextSet.count(s)) {
                                qNext->push(s);
                                qNextSet.insert(s);
                            }
                        }
                        s[i] = si;
                    }
                }
            }
            dict.erase(s);
            q->pop();
            qSet.erase(s);
            if (q->empty()) {
                swap(q, qNext);
                swap(qSet, qNextSet);
                level++;
            }
        }
        delete q;
        delete qNext;
        trace.push_back(start);
        dfs (start, level, from);
        return result;
    }
    
    void dfs (string word, int level, multimap<string, string> &from) {
        if (level == 1) {
            result.push_back(trace);
            return;
        }
        auto ret = from.equal_range(word);
        for (auto it = ret.first; it != ret.second; ++it) {
            trace.push_back(it->second);
            dfs (it->second, level - 1, from);
            trace.pop_back();
        }
    }
};