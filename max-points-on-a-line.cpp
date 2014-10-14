/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int n = (int) points.size();
        if (n <= 2)
            return n;
        
        map<pair<int, int>, int> pts;
        for (auto &pt : points){
            pts[{pt.x, pt.y}]++;
        }
        
        n = (int) pts.size();
        points.clear();
        for (auto &pt : pts){
            points.push_back(Point(pt.first.first, pt.first.second));
        }
        map<double, int> slope;
        int maxCount = pts[{points[0].x, points[0].y}];
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++){
                double sl = (points[j].x - points[i].x == 0) ?
                    numeric_limits<double>::infinity() :
                    1.0 * (points[j].y - points[i].y) / (points[j].x - points[i].x);
                slope[sl] += pts[{points[j].x, points[j].y}];
            }
            int maxBase = pts[{points[i].x, points[i].y}];
            for (auto &kc : slope) {
                maxCount = max(maxCount, kc.second + maxBase);
            }
            slope.clear();
        }
        return maxCount;
    }
};