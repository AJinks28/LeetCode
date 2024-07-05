class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        
        int i=0;//to iterate s
        int l=0;//l is start of curr word
        int r=0;//r is end of curr word
        reverse(s.begin(), s.end());
        while(i<n){
            
            while(i<n && s[i]!=' '){
                s[r]=s[i];
                r++;
                i++;
            }
            if (l < r) { // if we can find a non-empty word then
                reverse(s.begin() + l, s.begin() + r); // reverse current word
                if (r == n) break;
                s[r] = ' '; // set empty space
                r++;
                l = r;
            }
            ++i; // now i == n or s[i] == ' ', so we skip that character!
        }
         if (r > 0 && s[r-1] == ' ') --r; // skip last empty character if have
        s.resize(r);
        return s;
    }
};