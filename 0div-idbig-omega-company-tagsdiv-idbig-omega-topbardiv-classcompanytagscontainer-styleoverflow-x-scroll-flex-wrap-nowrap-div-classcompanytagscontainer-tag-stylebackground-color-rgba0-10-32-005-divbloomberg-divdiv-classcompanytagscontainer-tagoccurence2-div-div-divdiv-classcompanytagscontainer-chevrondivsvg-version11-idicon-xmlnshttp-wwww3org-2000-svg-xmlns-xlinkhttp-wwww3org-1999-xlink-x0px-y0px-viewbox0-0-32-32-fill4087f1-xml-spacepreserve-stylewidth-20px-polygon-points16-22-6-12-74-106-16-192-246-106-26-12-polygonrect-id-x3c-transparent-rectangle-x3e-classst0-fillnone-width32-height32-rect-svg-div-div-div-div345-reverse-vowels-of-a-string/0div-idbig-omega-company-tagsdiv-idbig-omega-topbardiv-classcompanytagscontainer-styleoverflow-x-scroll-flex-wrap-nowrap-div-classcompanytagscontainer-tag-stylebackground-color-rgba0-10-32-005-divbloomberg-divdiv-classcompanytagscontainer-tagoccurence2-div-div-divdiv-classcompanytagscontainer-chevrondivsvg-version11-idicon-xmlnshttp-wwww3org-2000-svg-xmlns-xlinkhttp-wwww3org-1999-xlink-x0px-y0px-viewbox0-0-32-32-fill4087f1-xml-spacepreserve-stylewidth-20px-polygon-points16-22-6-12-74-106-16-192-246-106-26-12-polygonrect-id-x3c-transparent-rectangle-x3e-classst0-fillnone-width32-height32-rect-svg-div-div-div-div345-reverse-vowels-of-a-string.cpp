class Solution {
public:
    set<char> s={'a','e','i','o','u','A','E','I','O','U'};
    bool isVowel(char c){
        if(s.count(c)>0) return true;
        return false;
    }
    string reverseVowels(string s) {
        int n=s.size();
        
        int l=0,r=n-1;
        while(l<r){
            if(!isVowel(s[l])) l++;
            else if(!isVowel(s[r])) r--;
            else {
                swap(s[l],s[r]);
                l++;
                r--;
            }
        }
        return s;
    }
};