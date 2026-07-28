class Solution {
public:
int m, n;
int ans = 0, cnt;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
void dfs(vector<vector<int>>& grid, int i, int j) {
    if(grid[i][j] == 2) {
        if(cnt == 1) {
            ans++;
        }
        return;
    }
    int temp = grid[i][j];
    grid[i][j] = -1;
    cnt--;
    for(int k = 0; k < 4; ++k) {
        int ni = i + dr[k];
        int nj = j + dc[k];
        if(ni >= 0 && nj >= 0 && ni < m && nj < n && grid[ni][nj] != -1) {
            dfs(grid, ni, nj);
        }
    }
    cnt++;
    grid[i][j] = temp;
}
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int si, sj;
        cnt = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] != -1) cnt++;
                if(grid[i][j] == 1) {
                    si = i;
                    sj = j;
                }
            }
        }
        dfs(grid, si, sj);
        return ans;
    }
};