class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size(), i = 0;
        vector<vector<int>> res;
        int st= newInterval[0],end= newInterval[1];
        while (i < n && intervals[i][1] < st) {
            res.push_back(intervals[i]);
            i++;
        }
        
        while (i < n && end >= intervals[i][0]) {
            st = min(st, intervals[i][0]);
            end = max(end, intervals[i][1]);
            i++;
        }
        res.push_back({st,end});

        while (i < n) {
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};