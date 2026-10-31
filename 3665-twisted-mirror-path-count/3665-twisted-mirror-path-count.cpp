class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        const int MOD = 1e9 + 7;

        // Store resolved mirror destinations
        // -2 = Not calculated, -1 = Invalid
        vector<vector<vector<int>>> memo(
            m, vector<vector<int>>(n, vector<int>(2, -2))
        );

        // dir = 0 means moving right
        // dir = 1 means moving down

        function<int(int, int, int)> solve =
        [&](int r, int c, int dir) -> int {

            // Out of bounds
            if (r >= m || c >= n)
                return -1;

            // Already calculated
            if (memo[r][c][dir] != -2)
                return memo[r][c][dir];

            // Empty cell: destination reached
            if (grid[r][c] == 0)
                return memo[r][c][dir] = r * n + c;

            int ans;

            // Mirror reflection
            if (dir == 0) {
                // Right -> Down
                ans = solve(r + 1, c, 1);
            }
            else {
                // Down -> Right
                ans = solve(r, c + 1, 0);
            }

            return memo[r][c][dir] = ans;
        };

        // DP array
        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = 1;

        // Traverse grid
        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1 || dp[i][j] == 0)
                    continue;

                int ways = dp[i][j];

                // Move right
                int right = solve(i, j + 1, 0);

                if (right != -1) {
                    int r = right / n;
                    int c = right % n;

                    dp[r][c] = (dp[r][c] + ways) % MOD;
                }

                // Move down
                int down = solve(i + 1, j, 1);

                if (down != -1) {
                    int r = down / n;
                    int c = down % n;

                    dp[r][c] = (dp[r][c] + ways) % MOD;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};