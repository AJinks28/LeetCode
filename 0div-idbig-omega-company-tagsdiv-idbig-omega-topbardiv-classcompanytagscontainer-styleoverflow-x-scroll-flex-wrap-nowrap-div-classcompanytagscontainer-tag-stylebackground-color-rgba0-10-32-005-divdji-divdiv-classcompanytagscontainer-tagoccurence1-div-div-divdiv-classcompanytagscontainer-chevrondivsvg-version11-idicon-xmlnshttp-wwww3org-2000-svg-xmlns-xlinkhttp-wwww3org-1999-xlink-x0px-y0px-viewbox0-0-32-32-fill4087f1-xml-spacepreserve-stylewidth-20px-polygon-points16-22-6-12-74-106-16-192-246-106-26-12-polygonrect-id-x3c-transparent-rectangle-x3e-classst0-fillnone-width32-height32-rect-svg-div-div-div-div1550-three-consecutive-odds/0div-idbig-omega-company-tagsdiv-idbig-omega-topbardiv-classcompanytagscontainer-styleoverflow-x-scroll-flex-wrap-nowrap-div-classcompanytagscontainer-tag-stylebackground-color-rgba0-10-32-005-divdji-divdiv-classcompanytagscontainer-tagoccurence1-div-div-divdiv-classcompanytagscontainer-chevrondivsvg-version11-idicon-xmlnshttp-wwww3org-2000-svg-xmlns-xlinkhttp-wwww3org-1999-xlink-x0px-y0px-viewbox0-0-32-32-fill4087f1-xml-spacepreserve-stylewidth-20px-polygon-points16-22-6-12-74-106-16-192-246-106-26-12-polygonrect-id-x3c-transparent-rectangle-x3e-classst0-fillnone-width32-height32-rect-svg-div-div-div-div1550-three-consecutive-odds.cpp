class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n=arr.size();
        if(n<3) return false;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(arr[i]%2!=0) cnt++;
            else cnt=0;
            if(cnt==3) return true;
            
        }
        return false;
    }
};