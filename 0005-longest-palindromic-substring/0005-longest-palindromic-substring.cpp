class Solution {
public:
    
    bool isPalindrome(int st,int end,string& s){
        while(st<=end){
            if(s[st]!=s[end]) return false;
            st++;end--;
        }
        return true;
    }
    
    string longestPalindrome(string s) {
        int n=s.size();
        
        string ans;
        int len=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,s) && (j-i+1)>len){
                    len=max(len,j-i+1);
                    ans=s.substr(i,j-i+1);
                } 
            }
        }
        return ans;
    }
};