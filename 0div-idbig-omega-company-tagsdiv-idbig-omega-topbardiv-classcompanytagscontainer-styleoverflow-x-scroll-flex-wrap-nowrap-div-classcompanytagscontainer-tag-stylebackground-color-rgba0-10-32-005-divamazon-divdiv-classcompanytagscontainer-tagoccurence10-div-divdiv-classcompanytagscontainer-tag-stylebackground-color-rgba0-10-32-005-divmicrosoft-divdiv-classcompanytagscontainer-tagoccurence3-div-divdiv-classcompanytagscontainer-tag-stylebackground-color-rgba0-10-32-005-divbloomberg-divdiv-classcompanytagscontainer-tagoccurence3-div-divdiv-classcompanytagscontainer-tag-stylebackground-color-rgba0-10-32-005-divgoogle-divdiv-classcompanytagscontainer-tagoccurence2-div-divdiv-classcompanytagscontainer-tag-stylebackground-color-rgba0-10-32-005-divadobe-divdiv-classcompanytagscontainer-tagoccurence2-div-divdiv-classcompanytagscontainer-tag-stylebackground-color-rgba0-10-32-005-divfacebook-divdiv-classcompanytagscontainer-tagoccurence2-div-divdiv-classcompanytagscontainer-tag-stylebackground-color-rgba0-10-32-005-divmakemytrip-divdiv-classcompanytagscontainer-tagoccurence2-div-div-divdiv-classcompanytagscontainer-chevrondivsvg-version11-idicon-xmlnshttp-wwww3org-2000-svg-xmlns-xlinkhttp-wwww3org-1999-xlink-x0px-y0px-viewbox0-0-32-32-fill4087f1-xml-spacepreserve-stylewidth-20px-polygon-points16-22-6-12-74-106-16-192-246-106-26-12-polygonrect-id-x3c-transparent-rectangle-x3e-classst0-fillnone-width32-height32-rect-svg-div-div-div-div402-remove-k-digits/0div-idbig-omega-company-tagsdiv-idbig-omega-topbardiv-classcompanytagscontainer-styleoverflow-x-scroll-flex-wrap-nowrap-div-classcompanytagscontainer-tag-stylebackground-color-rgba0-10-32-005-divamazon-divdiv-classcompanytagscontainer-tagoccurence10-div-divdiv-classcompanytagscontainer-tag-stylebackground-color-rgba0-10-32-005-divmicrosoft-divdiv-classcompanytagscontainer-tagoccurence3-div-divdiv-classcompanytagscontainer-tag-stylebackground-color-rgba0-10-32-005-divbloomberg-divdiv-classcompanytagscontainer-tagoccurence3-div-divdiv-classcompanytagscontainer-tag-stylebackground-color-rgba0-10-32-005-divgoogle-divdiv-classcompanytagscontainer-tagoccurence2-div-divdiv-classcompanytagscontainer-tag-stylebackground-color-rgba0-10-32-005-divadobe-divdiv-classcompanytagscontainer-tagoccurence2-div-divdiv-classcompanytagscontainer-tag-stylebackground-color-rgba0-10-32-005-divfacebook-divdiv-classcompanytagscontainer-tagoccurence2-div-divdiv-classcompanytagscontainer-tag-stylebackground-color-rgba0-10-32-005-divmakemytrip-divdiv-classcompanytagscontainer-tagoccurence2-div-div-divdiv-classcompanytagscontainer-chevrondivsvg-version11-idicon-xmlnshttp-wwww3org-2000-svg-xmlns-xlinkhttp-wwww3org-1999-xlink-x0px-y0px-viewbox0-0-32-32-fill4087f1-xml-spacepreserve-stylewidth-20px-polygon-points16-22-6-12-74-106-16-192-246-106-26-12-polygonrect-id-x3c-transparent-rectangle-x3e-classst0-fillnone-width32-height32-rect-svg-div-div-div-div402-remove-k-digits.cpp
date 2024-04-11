class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        
        for(char &c:num){
            
            while(ans.size() && ans.back()>c && k){
                ans.pop_back();
                k--;
            }
            
            if(ans.size() || c!='0') ans.push_back(c);
            //jb ans ki size 0 and c==0 ho tb push nhi krna hai
        }
        //cases like all digits in ascending order, we will pop from back
         while(ans.size() && k--){
                ans.pop_back();
            }
        
        return (ans=="")?"0":ans;
    }
};