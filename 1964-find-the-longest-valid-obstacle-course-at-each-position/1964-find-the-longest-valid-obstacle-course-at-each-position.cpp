class Solution {
public:
    //https://www.youtube.com/watch?v=sUtUgMW2kMY&list=PLpIkg8OmuX-L_QqcKB5abYynQbonaNcq3&index=28&ab_channel=codestorywithMIK
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& o) {
        int n=o.size();
        vector<int> lis,res(n);
        
        
        for(int i=0;i<n;i++){
            int idx=upper_bound(begin(lis),end(lis),o[i])-begin(lis);
            
            if(idx>=lis.size()) lis.push_back(o[i]);
            
            else lis[idx]=o[i];
            
            res[i]=idx+1;
        }
        return res;
    }
};