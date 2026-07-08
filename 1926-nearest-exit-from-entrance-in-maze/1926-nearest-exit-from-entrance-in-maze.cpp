class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        queue<pair<pair<int, int>, int>> q;
        q.push({{entrance[0], entrance[1]}, 0});
        maze[entrance[0]][entrance[1]] = '+';
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            int r = cur.first.first;
            int c = cur.first.second;
            int d = cur.second;
            if((r == 0 || r == m - 1 || c == 0 || c == n - 1) && !(r == entrance[0] && c == entrance[1]))
                return d;
            for(int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n &&
                    maze[nr][nc] == '.') {
                    maze[nr][nc] = '+';
                    q.push({{nr, nc}, d + 1});
                }
            }
        }
        return -1;
    }
};