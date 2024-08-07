class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int d=s.size();
        if (n == 1) return -1;
        
        /* find the first decreasing digit from the right, eg: 59876, 5 is the first decreasing digit */
        int i = d - 2; // 21 -> i = 0; 59876 -> i = 3
        while(i>=0 && s[i] >= s[i + 1]) i--;
        if (i == -1) return -1;
        
        reverse(s.begin() + i + 1, s.end());
        for (int j = i + 1; j < d; j++) {
            if (s[j] > s[i]) {
                swap(s[i], s[j]);
                break;
            }
        }
        long next = stol(s);
        return next > INT_MAX ? -1 : next;
    }
};