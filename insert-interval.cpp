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
    vector<Interval> insert(vector<Interval> &intervals, Interval &newInterval) {
        vector<Interval> result;
        Interval absorber = newInterval;
        for(Interval &ab : intervals){
            if (isIntersect(ab, absorber)){
                absorber = coalesce(ab, absorber);
            }
            else{
                result.push_back(ab);
            }
        }
        int i = 0, n = result.size();
        while (i < n && absorber.start > result[i].end) i++;
        result.insert(result.begin() + i, absorber);
        return result;
    }
    bool isIntersect(Interval &ab, Interval &cd){
        if (ab.end < cd.start)
            return false;
        if (cd.end < ab.start)
            return false;
        return true;
    }
    Interval coalesce(Interval &ab, Interval &cd){
        return Interval(min(ab.start, cd.start), max(ab.end, cd.end));
    }
};