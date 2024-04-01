class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
        int lastIdx=n-1,cnt=0;
        //to remove spaces at last
        while(lastIdx>=0 && s[lastIdx]==' ') lastIdx--;
        //counting last word's length
        while(lastIdx>=0 && s[lastIdx]!=' '){
            cnt++;
            lastIdx--;
        }
        return cnt;
    }
};