class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string token,res;
        
        while(ss>>token){
            res= token+" "+res;
        }
        return res.substr(0,res.size()-1);
    }
};