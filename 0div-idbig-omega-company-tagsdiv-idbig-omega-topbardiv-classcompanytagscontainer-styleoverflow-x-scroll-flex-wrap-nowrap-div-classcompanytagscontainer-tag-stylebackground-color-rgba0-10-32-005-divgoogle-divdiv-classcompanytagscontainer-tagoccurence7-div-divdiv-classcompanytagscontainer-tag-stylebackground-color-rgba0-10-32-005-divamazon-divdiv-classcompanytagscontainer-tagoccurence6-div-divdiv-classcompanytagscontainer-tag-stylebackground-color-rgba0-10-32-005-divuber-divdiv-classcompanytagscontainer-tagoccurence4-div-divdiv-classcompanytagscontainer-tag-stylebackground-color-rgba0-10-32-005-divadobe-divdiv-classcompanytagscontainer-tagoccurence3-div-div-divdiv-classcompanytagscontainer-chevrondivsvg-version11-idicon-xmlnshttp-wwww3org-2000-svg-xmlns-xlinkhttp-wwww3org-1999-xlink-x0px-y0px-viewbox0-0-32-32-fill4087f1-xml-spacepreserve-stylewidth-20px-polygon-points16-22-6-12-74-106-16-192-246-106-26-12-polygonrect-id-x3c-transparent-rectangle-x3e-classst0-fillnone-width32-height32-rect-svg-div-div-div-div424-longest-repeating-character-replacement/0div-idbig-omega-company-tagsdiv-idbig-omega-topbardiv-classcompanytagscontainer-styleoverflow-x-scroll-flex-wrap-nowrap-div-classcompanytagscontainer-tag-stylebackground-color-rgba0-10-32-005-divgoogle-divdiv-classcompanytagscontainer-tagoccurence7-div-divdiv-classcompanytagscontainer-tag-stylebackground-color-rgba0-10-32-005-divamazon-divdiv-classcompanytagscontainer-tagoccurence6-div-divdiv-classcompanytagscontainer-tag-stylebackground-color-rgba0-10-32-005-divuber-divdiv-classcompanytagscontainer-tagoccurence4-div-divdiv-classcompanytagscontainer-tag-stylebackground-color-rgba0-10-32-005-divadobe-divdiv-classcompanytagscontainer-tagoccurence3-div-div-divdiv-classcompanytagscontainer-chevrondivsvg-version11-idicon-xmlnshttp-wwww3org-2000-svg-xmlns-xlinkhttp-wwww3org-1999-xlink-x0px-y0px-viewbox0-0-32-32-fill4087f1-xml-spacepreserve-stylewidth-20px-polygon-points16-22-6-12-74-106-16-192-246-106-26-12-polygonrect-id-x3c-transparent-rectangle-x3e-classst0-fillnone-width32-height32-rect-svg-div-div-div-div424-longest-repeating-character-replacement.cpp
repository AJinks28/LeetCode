class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        unordered_map<int,int> freq;
        int i=0,maxFreq=0,ans=0;
        for(int j=0;j<n;j++){
            freq[s[j]]++;
            maxFreq=max(maxFreq,freq[s[j]]);
            
            if((j-i+1)-maxFreq > k){
                freq[s[i]]--;
                i++;
            }
            
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};