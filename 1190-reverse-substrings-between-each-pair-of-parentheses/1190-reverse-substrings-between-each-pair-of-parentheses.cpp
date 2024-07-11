class Solution {
public:
    string reverseParentheses(string s) {
        string res;
        int n=s.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(s[i]=='(' ){
                st.push(res.size());
            }else if(s[i]==')' ){
                int start=st.top();
                st.pop();
                reverse(res.begin()+start,res.end());
            }
            else{
                res+=s[i];
            }
        }
    
        return res;
    }
};