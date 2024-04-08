class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int cnt1=0,cnt0=0;
        
        for(int stud:students){
            if(stud==0) cnt0++;
            else cnt1++;
        }
        
        for(int sw:sandwiches){
            if(sw==0){
                if(cnt0==0) return cnt1;
                cnt0--;
            }
            else{
                if(cnt1==0) return cnt0;
                cnt1--;
            }
        }
        return 0;
    }
};