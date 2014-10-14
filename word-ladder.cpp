class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<string> *q = new queue<string> (), *qNext =  new queue<string> ();
        q->push(start);
        dict.erase(start); // allow key miss
        int level = 1;
        while (!q->empty()) {
            string s = q->front();
            for (int i = 0; i < s.size(); i++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    char si = s[i];
                    if (si != c) {
                        s[i] = c;
                        if (s == end)
                            return level + 1;
                        if (dict.count(s)) {
                            qNext->push(s);
                            dict.erase(s);
                        }
                        s[i] = si;
                    }
                }
            }
            q->pop();
            if (q->empty()) {
                swap(q, qNext);
                level++;
            }
        }
        delete q;
        delete qNext;
        return 0;
    }
};