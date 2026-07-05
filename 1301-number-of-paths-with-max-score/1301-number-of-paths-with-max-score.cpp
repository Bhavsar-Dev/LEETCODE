class Solution {
public:
    int mod = 1e9 + 7;
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        vector<vector<int>> mx(n, vector<int>(n, -1));
        vector<vector<int>> cnt(n, vector<int>(n, 0));
        mx[n - 1][n - 1] = 0;
        cnt[n - 1][n - 1] = 1;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(board[i][j] == 'X') continue;
                if(i == n - 1 && j == n - 1) continue;
                int best = -1;
                long long ways = 0;
                vector<pair<int, int>> d = {{i + 1, j}, {i, j + 1}, {i + 1, j + 1}};
                for(auto [x, y] : d) {
                    if(x >= n || y >= n) continue;
                    if(mx[x][y] == -1) continue;
                    if(mx[x][y] > best) {
                        best = mx[x][y];
                        ways = cnt[x][y];
                    } 
                    else if (mx[x][y] == best) {
                        ways = (ways + cnt[x][y]) % mod;
                    }
                }
                if(best == -1) continue;
                int val = 0;
                if (board[i][j] >= '1' && board[i][j] <= '9') val = board[i][j] - '0';
                mx[i][j] = best + val;
                cnt[i][j] = ways % mod;
            }
        }
        if(cnt[0][0] == 0) return {0, 0};
        return {mx[0][0], cnt[0][0]};
    }
};