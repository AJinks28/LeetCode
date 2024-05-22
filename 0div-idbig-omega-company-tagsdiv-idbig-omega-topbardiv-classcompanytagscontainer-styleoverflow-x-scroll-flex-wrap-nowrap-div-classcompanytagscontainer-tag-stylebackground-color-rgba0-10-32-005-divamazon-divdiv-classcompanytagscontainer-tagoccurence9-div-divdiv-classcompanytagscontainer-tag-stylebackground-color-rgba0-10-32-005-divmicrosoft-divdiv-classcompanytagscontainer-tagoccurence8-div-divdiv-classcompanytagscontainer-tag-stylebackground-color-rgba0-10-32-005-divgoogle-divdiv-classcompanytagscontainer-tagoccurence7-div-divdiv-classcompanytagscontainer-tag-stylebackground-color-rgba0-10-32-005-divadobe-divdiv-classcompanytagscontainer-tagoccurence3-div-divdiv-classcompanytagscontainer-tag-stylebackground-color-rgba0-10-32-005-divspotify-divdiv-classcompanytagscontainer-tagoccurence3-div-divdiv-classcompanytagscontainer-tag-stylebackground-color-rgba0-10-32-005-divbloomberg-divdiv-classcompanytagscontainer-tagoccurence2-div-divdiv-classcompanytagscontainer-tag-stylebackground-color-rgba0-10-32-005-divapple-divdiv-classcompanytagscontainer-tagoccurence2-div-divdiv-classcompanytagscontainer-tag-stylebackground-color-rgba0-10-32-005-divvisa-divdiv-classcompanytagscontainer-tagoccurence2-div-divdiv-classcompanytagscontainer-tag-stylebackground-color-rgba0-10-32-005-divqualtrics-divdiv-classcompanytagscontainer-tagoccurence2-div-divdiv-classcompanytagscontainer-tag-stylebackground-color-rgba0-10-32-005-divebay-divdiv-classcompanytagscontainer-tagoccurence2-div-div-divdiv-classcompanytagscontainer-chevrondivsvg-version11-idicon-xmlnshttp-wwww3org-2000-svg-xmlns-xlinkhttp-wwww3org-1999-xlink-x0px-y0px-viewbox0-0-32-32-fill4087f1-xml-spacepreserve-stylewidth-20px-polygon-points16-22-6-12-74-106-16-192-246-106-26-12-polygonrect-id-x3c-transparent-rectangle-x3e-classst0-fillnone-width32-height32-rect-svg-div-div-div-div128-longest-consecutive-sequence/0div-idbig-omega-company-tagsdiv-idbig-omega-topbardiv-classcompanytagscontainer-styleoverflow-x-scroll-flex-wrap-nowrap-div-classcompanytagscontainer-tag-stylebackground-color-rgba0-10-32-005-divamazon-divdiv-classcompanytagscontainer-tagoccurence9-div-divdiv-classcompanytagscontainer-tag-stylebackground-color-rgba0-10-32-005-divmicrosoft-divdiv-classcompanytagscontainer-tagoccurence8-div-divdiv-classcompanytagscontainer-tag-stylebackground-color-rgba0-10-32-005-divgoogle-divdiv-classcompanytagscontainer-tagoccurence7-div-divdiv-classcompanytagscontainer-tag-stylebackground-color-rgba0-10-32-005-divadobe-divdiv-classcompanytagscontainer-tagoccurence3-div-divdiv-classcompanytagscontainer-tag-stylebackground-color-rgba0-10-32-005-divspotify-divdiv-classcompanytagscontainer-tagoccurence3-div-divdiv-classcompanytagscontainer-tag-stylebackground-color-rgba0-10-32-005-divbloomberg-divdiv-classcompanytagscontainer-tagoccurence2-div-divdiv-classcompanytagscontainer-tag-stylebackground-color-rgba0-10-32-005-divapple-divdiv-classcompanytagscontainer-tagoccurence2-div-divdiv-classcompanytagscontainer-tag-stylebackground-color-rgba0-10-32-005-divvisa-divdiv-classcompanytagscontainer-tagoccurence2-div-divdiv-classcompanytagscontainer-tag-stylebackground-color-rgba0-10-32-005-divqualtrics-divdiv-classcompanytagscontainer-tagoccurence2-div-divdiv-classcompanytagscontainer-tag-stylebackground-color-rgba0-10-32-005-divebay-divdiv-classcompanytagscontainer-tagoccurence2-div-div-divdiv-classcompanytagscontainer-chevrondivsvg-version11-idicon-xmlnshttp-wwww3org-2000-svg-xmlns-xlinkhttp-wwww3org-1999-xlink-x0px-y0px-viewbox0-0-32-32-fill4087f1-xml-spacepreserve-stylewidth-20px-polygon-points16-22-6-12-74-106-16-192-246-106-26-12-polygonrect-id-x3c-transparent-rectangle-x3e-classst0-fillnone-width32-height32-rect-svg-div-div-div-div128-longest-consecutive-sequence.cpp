class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> s;
        int maxcnt=0;
        
        for(int num:nums) s.insert(num);
        
        for(auto it:s){
            if(s.find(it-1)==s.end()){
                int x=it;
                int cnt=1;
                
                while(s.find(x+1)!=s.end()){
                    cnt++;
                    x++;
                }
                maxcnt=max(maxcnt,cnt);
            }
        }
        return maxcnt;
    }
};