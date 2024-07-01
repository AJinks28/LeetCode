class Solution {
public:
    int lcs(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        vector<int> prev(n2+1,0),curr(n2+1,0);
        
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(s1[i]==s2[j]) curr[j+1]=1+prev[j];
                else curr[j+1]=max(prev[j+1],curr[j]);
        
            }
            prev=curr;
        }
        
        return prev[n2];
    }
    int longestPalindromeSubseq(string s) {
        string r=s;
        reverse(r.begin(),r.end());
        
        return lcs(s,r);
    }
};