class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
        int word_cnt=0,cnt=0;
        
        for(int i=0;i<n;i++){
            if(s[i]==' ') cnt=0;
            else cnt++;
            if(cnt>0) word_cnt=cnt;
        }
        return word_cnt;
    }
};