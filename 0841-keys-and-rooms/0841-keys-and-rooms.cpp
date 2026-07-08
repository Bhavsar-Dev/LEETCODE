class Solution {
public:
void dfs(int u, vector<vector<int>>& rooms, vector<int>& vis) {
    vis[u] = 1;
    for(int v : rooms[u]) {
        if(!vis[v]) dfs(v, rooms, vis);
    }
}
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n, 0);
        dfs(0, rooms, vis);
        for(int i = 0; i < n; ++i) {
            if(!vis[i]) return false;
        }
        return true;
    }
};