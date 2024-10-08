class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> mp;
        
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5) mp[5]++;
            else if(bills[i]==10){
                if(mp[5]==0) return false;
                mp[5]--;
                mp[10]++;
            }
            else{
                if(mp[5]==0) return false;
                if(mp[10]==0 && mp[5]<=2) return false;
                if(mp[10]>0){
                    mp[10]--;
                    mp[5]--;
                }else if(mp[5]>=3) mp[5]-=3;
                mp[20]++;
            }
        }
        return true;
    }
};