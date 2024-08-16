class Solution {
public:
    string largestOddNumber(string s) {
        int n=s.size();
        int i=0,num=0,idx=-1;
        string ans;
        while(i<n){
            num=s[i]-'0';
            
            if(num%2) idx=i;
            
            i++;
        }
        if(idx!=-1) ans=s.substr(0,idx+1);
        return ans;
    }
};