class Solution {
public:
    bool hasValidPath(vector<vector<char>>& g) {
        int m = g.size(), n = g[0].size();
        if ((m + n - 1) % 2) return false;
        if (g[0][0] == ')') return false;
        vector<vector<bitset<201>>> d(m, vector<bitset<201>>(n));
        d[0][0][1] = 1;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) continue;
                int x = (g[i][j] == '(' ? 1 : -1);
                if(i > 0) {
                    for(int k = 0; k <= 200; k++) {
                        if(d[i - 1][j][k] && k + x >= 0) d[i][j][k + x] = 1;
                    }
                }
                if(j > 0) {
                    for(int k = 0; k <= 200; k++) {
                        if(d[i][j - 1][k] && k + x >= 0) d[i][j][k + x] = 1;
                    }
                }
            }
        }
        return d[m - 1][n - 1][0];
    }
};