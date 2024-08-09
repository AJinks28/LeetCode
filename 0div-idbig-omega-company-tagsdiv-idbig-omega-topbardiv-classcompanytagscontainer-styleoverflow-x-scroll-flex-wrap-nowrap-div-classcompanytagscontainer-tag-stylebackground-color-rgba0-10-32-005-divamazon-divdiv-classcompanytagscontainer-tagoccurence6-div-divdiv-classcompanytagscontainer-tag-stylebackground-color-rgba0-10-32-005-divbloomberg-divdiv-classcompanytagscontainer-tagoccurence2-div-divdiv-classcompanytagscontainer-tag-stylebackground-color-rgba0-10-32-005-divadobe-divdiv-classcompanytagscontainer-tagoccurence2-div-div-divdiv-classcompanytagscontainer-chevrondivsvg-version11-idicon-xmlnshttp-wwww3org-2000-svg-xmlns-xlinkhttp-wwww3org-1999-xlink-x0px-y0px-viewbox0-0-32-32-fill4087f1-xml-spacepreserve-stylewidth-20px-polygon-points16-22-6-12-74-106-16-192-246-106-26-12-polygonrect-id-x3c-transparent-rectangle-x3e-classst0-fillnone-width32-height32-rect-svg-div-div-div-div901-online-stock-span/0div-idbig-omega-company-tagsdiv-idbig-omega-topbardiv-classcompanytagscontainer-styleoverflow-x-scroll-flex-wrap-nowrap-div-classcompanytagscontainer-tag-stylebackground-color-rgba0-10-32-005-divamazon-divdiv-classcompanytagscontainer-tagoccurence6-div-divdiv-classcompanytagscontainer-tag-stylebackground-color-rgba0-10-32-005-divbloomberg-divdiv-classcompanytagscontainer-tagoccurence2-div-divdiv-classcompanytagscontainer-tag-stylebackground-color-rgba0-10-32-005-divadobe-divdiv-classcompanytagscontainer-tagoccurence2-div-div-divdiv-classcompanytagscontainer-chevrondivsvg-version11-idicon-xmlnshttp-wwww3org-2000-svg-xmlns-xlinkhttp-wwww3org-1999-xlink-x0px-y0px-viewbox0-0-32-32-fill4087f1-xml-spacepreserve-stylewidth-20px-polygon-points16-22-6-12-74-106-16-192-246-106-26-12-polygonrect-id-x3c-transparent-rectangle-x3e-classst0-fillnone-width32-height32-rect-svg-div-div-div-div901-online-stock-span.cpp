class StockSpanner {
public:
    stack<pair<int,int>> st;
    int i;
    StockSpanner() {
        i=-1;
    }
    
    int next(int p) {
        int ans;
        i++;
        
        while(!st.empty() && st.top().first<=p) st.pop();
        if(st.empty()) ans= i+1;
        else ans=i-st.top().second;
        cout<<i<<" ";
        st.push({p,i});
        
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */