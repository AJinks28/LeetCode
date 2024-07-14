class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horz, vector<int>& vert) {
        sort(horz.begin(),horz.end());
        sort(vert.begin(),vert.end());
        
        int i=horz.size()-1;
        int j=vert.size()-1;
        
        long long h=1,v=1;
        
        long long ans=0;
        while(i>=0 && j>=0){
            if(horz[i]>=vert[j]){
                ans+=v*horz[i];
                i--;
                h++;
            }else{
                ans+=h*vert[j];
                j--;
                v++;
            }
        }
        while(i>=0) {ans+=v*horz[i];i--;}
        while(j>=0) {ans+=h*vert[j];j--;}
        return ans;
    }
};