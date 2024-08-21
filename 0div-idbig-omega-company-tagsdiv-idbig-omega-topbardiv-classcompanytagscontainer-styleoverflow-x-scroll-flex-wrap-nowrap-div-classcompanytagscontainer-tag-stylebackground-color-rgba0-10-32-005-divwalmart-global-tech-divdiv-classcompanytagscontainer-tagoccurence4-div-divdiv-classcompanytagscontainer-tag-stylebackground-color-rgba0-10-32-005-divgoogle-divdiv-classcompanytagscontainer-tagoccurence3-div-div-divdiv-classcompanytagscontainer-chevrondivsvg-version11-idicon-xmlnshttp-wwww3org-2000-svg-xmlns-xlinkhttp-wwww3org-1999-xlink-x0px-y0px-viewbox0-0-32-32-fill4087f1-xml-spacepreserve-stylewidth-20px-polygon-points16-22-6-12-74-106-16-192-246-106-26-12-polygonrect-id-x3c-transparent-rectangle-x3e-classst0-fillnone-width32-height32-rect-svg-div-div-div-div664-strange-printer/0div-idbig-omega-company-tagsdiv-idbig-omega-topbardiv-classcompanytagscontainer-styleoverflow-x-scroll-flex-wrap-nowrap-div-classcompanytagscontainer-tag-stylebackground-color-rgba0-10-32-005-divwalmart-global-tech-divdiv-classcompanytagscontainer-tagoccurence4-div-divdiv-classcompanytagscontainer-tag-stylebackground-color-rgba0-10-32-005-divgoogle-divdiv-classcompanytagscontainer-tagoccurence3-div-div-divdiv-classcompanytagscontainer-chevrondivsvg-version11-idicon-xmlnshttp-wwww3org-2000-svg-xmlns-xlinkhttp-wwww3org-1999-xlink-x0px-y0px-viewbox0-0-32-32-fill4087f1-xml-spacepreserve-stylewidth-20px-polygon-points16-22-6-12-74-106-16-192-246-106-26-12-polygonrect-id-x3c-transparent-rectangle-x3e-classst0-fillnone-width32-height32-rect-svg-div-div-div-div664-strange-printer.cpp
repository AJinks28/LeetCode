class Solution {
public:
    int dp[101][101];
    int solve(int i,int j,string &s){
        if (dp[i][j]!=-1) return dp[i][j];
        if (i==j) return dp[i][j]=1;// base case
        
        if (s[i]==s[j]) return solve(i, j-1, s);
        
        int ans=1+solve(i, j-1, s);
        
        for(int k=i+1; k<j-1; k++){// s[j-1]!=s[j]
            if (s[k]==s[j])
                ans=min(ans, solve(i, k-1, s)+solve(k, j-1, s));
        }
        return dp[i][j]=ans;
    }
    string removedupl(string s){
        int n=s.size();
        string newStr;
        newStr.push_back(s[0]);
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]) continue;
            else newStr.push_back(s[i]);
        }
        return newStr;
    }
    int strangePrinter(string s) {
        string str=removedupl(s);
        cout<<str<<" ";
        memset(dp,-1,sizeof(dp));
        return solve(0,str.size()-1,str);
    }
};