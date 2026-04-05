class Solution {
    public:
    
        int getAllPaths(int row, int col, int currRow, int currCol, vector<vector<int>>& dp) {
            if (currRow >= row || currCol >= col) return 0;
            if (currRow == row - 1 && currCol == col - 1) return 1;
    
            if (dp[currRow][currCol] != -1) {
                return dp[currRow][currCol];
            }
            dp[currRow][currCol] = getAllPaths(row, col, currRow + 1, currCol, dp) + getAllPaths(row, col, currRow, currCol + 1, dp);
            return dp[currRow][currCol];
        }
        int uniquePaths(int m, int n) {
            vector<vector<int>> dp(m, vector<int>(n, -1));
            return getAllPaths(m, n, 0 , 0, dp);
        }
    };
