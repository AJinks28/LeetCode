class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if (n <= 1) {
            return s;
        }
        
        int max_len = 1;
        int start = 0;
        int end = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
            for (int j = 0; j < i; ++j) {
                //expanding around center
                if (s[j] == s[i] && (i - j <= 2 || dp[j + 1][i - 1])) {
                    //i - j <= 2 means either 1 or 2 bcz center can be of len 1 or 2
                    dp[j][i] = true;
                    if (i - j + 1 > max_len) {
                        max_len = i - j + 1;
                        start = j;
                        end = i;
                    }
                }
            }
        }
        
        return s.substr(start, end - start + 1);
    }
};