class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_set<char> set;
        int len=0;
        
        for(int i=0,j=0;j<n;j++){
            if(set.find(s[j])==set.end())  //if not in the set
                set.insert(s[j]);
            else{
                while(set.find(s[j])!=set.end()){ //if in the set
                    set.erase(s[i]);
                    i++;
                }
                set.insert(s[j]);
            }
            
            len=max(len,j-i+1);
        }
        return len;
    }
};