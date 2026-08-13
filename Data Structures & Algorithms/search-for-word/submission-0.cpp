class Solution {
   public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int r{}; r < board.size(); ++r) {
            for (int c{}; c < board[0].size(); ++c) {
                if (board[r][c] == word[0]) {
                    if (dfs(board, word, r, c, 0, dirs)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int r, int c, int index,
             vector<vector<int>>& dirs) {
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) {
            return false;
        }
        if (board[r][c] != word[index]) {
            return false;
        }

        if (index == word.size() - 1) {
            return true;
        }
        cout << board[r][c] << '\n';
        char temp = board[r][c];
        board[r][c] = '#';
        bool ret;
        for (int i{}; i < 4; ++i) {
            if (dfs(board, word, r + dirs[i][0], c + dirs[i][1], index + 1, dirs)) {
                return true;
            }
        }
        board[r][c] = temp;
        return false;
    }
};
