/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> seg;
        sort(intervals.begin(), intervals.end(), 
            [](Interval a, Interval b){return a.start < b.start;});
        for (auto &pq : intervals) {
            if (seg.empty()) {
                seg.push_back(pq);
                continue;
            }
            Interval &segTop = seg.back();
            if (pq.start <= segTop.end) // merge or push_back
                segTop.end =  max(segTop.end, pq.end); 
            else 
                seg.push_back(pq);
        }
        return seg;
    }
};