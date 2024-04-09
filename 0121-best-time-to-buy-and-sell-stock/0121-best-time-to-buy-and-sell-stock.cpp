class Solution {
public:
    //2 ptr's algo
    int maxProfit(vector<int>& prices) {
        int l = 0;//buy
        int r = 1;//sell
        int max_prof=0;
        while(r<prices.size()){
            if(prices[l]<prices[r]){
                int prof=prices[r]-prices[l];
                max_prof=max(max_prof,prof);
            }else{
                l=r;
            }
            r++;
        }
        return max_prof;
    }
};