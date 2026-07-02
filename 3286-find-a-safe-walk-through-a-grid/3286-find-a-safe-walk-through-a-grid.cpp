#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();
        deque<pair<int,int>> q;
        vector<vector<int>> d(n, vector<int>(m, 1e9));
        d[0][0] = grid[0][0];
        q.push_front({0, 0});
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop_front();
            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                int w = grid[nx][ny];
                if(d[x][y] + w < d[nx][ny]) {
                    d[nx][ny] = d[x][y] + w;
                    if(w == 0) q.push_front({nx, ny});
                    else q.push_back({nx, ny});
                }
            }
        }
        return d[n - 1][m - 1] < health;
    }
};