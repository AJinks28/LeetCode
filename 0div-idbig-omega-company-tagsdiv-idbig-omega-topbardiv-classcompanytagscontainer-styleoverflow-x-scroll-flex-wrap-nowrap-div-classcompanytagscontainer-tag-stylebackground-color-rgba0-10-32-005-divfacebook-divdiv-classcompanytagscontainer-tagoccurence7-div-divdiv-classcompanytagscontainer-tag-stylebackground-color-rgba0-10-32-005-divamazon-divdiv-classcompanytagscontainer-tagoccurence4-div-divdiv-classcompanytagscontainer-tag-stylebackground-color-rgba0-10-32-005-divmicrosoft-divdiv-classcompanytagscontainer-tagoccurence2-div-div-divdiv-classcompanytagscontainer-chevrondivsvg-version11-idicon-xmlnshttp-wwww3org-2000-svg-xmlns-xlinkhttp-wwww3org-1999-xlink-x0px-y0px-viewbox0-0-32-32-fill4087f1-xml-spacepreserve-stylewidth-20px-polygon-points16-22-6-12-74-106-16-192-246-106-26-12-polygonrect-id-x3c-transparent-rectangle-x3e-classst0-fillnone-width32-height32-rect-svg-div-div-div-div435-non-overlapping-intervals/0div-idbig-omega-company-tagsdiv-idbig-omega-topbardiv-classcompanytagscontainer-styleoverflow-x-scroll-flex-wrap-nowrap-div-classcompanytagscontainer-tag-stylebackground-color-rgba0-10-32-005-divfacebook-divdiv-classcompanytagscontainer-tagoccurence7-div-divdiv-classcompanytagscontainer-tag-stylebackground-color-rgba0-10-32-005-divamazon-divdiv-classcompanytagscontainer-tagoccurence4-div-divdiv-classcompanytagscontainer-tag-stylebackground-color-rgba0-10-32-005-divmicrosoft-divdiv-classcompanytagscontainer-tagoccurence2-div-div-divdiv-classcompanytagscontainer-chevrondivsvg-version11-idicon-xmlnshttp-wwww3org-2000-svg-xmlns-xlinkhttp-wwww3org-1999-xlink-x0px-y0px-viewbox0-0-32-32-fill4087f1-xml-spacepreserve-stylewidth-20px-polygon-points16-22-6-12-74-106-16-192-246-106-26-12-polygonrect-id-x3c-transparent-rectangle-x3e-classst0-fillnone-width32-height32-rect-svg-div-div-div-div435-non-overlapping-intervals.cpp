bool cmp(vector<int> &a,vector<int> &b){ return a[1]<b[1];}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int ans=0;
        int prevEnd=intervals[0][1];
        
        for(int i=1;i<intervals.size();i++){
            int st=intervals[i][0];
            int end=intervals[i][1];
            
            if(st>=prevEnd) prevEnd=end;
            else ans++;
        }
        return ans;
    }
};