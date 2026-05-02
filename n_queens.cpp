class Solution {
    public:
        void solve(int col, int n, vector<int>& leftRow, vector<int>& lowerDiagonal, vector<int>& upperDiagonal, vector<string>& board, vector<vector<string>>& ans) {
            if (col == n) {
                ans.push_back(board);
                return;
            }
    
            for (int row = 0; row < n; row ++) {
                if (leftRow[row] == 0 && lowerDiagonal[col + row] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
                    leftRow[row] = 1;
                    lowerDiagonal[col + row] = 1;
                    upperDiagonal[n - 1 + col - row] = 1;
                    board[row][col] = 'Q';
                    solve(col + 1, n, leftRow, lowerDiagonal, upperDiagonal, board, ans);
                    leftRow[row] = 0;
                    lowerDiagonal[col + row] = 0;
                    upperDiagonal[n - 1 + col - row] = 0;
                    board[row][col] = '.';
                }
            } 
        }
    
        vector<vector<string>> solveNQueens(int n) {
            vector<vector<string>> ans;
            vector<string> board(n);
            string s(n, '.');
            for(int i = 0; i < n; i ++) {
                board[i] = s;
            }
    
            vector<int> leftRow(n, 0), lowerDiagonal(2 * n - 1, 0), upperDiagonal(2 * n - 1, 0);
    
            solve(0, n, leftRow, lowerDiagonal, upperDiagonal, board, ans);
            return ans;
        }
    };
