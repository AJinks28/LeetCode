class Solution {
public:
    string reverseParentheses(string s) {
        string str;
        int n=s.size();
        // for(int i=0;i<n;i++){
        //     if(str[i]=='(' || str[i]==')') str[i]='#';
        // }
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i]==')' ){
                
                while(st.top()!='('){
                    str+=st.top();
                    st.pop();
                    
                }
                st.pop();
                for(char& c:str) st.push(c);
                str="";
            }else{
                st.push(s[i]);
            }
        }
        
        while(!st.empty()){
            str+=st.top();
            st.pop();

        }
        reverse(str.begin(),str.end());
        return str;
    }
};