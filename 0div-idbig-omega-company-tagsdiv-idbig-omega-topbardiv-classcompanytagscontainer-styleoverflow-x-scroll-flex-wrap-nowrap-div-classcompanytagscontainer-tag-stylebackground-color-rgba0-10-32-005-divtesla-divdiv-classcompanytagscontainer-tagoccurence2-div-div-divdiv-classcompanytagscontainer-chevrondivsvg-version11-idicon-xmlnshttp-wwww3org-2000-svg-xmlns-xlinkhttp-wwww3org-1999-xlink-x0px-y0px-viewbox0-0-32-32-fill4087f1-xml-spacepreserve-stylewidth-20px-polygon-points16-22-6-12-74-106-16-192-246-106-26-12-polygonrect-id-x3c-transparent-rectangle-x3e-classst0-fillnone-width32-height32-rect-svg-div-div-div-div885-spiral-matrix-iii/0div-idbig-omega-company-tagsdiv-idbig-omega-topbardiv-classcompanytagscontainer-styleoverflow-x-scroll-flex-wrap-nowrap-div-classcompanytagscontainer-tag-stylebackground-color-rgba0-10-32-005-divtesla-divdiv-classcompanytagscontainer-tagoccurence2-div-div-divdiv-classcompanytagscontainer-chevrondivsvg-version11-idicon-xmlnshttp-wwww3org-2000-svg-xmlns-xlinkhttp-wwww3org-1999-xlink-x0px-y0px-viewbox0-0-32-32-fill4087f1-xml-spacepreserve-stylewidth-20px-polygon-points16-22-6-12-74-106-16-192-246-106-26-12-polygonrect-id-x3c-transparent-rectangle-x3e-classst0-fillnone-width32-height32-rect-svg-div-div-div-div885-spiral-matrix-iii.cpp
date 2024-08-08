class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int r,int c) {
        // Store all possible directions in an array.
        vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> ans;

        //E->S->W->N is the way we are following 
        // Initial step size is 1, value of d represents the current direction.
        int step = 1, d = 0;
        while ( ans.size() < rows * cols) {
            // d = 0 -> East, d = 1 -> South
            // d = 2 -> West, d = 3 -> North
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < step; ++j) {
                    // Validate the current position
                    if (r >= 0 && r < rows && c >= 0 && c < cols) {
                        ans.push_back({r, c});
                    }
                    // Make changes to the current position.
                    r += dir[d][0];
                    c += dir[d][1];
                }

                d = (d + 1) % 4;
            }
            ++step;
        }
        return ans;
    }
};