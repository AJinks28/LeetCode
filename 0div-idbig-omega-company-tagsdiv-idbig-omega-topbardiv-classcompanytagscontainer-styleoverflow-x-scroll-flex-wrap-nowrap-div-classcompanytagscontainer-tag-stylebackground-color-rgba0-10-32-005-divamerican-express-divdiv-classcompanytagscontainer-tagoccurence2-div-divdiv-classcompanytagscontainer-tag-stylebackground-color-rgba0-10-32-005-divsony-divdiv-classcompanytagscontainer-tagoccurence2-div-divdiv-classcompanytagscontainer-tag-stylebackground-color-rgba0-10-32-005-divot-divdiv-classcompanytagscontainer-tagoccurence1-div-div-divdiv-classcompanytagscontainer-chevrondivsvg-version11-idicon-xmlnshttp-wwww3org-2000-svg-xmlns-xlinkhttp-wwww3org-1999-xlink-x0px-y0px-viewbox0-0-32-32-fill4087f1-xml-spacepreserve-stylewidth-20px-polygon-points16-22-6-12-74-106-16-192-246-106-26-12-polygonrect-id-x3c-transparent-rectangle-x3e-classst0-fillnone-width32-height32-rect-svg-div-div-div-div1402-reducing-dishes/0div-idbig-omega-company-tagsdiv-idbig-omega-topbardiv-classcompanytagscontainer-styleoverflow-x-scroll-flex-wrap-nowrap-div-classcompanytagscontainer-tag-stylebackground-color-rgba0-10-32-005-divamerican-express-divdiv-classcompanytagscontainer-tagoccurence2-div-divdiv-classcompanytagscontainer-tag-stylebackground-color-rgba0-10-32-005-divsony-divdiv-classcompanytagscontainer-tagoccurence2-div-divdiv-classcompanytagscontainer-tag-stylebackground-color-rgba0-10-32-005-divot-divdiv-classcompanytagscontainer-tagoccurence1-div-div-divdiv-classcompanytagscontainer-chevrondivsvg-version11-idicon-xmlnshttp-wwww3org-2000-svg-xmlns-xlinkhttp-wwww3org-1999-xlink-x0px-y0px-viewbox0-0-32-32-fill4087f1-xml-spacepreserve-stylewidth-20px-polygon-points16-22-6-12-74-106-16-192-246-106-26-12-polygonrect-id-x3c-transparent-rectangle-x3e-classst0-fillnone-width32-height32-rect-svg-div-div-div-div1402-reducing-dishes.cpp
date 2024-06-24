class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
         sort(sat.begin(), sat.end());
        int res = 0, total = 0, n = sat.size();
        for (int i = n - 1; i >= 0 && sat[i] > -total; --i) {
            total += sat[i];
            res += total;
        }
        return res;
    }
};