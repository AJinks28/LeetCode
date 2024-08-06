class Solution {
public:
    int minimumPushes(string word) {
        priority_queue<int> pq;
        unordered_map<char,int> mp;
        for(int i=0;i<word.size();i++){
            mp[word[i]]++;
        }
        for(auto it:mp){
            pq.push(it.second);
        }
        int k=0,ans=0;
        while(!pq.empty()){
            int cnt=pq.top();
            pq.pop();
            ans+=(cnt*(k/8+1));
            k++;
            
        }
        return ans;
    }
};