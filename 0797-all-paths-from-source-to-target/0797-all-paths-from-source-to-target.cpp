class Solution {
public:
vector<vector<int>> ans;
vector<int> path;
void dfs(int u, vector<vector<int>> & graph) {
    path.push_back(u);
    if(u == graph.size() -1) ans.push_back(path);
    else {
        for(int v : graph[u]) dfs(v, graph);
    }
    path.pop_back();
}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(0, graph);
        return ans;
    }
};