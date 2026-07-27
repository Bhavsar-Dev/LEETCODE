class Solution {
public:
    int m, n;
    bool dfs(vector<vector<char>>& b, string& w, int i, int j, int k) {
        if (k == w.size()) return true;
        if (i < 0 || j < 0 || i >= m || j >= n || b[i][j] != w[k]) return false;
        char c = b[i][j];
        b[i][j] = '#';
        bool ans = dfs(b, w, i + 1, j, k + 1) || dfs(b, w, i - 1, j, k + 1) || dfs(b, w, i, j + 1, k + 1) || dfs(b, w, i, j - 1, k + 1);
        b[i][j] = c;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0] && dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};