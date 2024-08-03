class Solution {
public:
    bool canBeEqual(vector<int>& t, vector<int>& arr) {
        sort(t.begin(),t.end());
        sort(arr.begin(),arr.end());
        return t==arr;
    }
};