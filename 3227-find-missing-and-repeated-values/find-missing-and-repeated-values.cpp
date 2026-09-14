class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int repeated = -1, missing = -1;

        for (int x = 1; x <= n * n; x++) {
            int count = 0;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == x)
                        count++;
                }
            }

            if (count == 2)
                repeated = x;
            else if (count == 0)
                missing = x;
        }

        return {repeated, missing};
    }
};