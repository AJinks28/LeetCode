class Solution {
public:
    bool checkValidString(string s) {
        int cmax=0,cmin=0;
        //storing range {cmin,cmax}
        for(auto c: s){
            if(c=='('){
                cmax++;
                cmin++;
            }
            if(c==')'){
                cmax--;
                cmin=max(0,cmin-1);
            }
            if(c=='*'){
                cmax++;
                cmin=max(0,cmin-1);
            }
            if(cmax<0) return false;
        }
        return cmin==0;
    }
};
// cmax considers each '*' as '(', which should never be negative
// cmin considers each '*' as ')' as much as possible (treat it as empty string if cmin<0 -- "max(cmin-1, 0)").
// In the end, cmin should be 0. If it's larger than 0, it means even if we consider every '*' as ')', there is still some '(' left.

// cmax counts the maximum open parenthesis,
// which means the maximum number of unbalanced '(' that COULD be paired.
// cmin counts the minimum open parenthesis,
// which means the number of unbalanced '(' that MUST be paired.