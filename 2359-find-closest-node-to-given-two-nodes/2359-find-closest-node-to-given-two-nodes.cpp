class Solution {
public:
vector<int> get(vector<int>& edges, int st) {
    int n = edges.size();
    vector<int> dist(n, -1);
    vector<bool> vis(n, false);
    int cur = st, d = 0;
    while(cur != -1 && !vis[cur]) {
        vis[cur] = true;
        dist[cur] = d++;
        cur = edges[cur];
    }
    return dist;
}
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int> dist1 = get(edges, node1);
        vector<int> dist2 = get(edges, node2);
        int ans = -1, best = INT_MAX;
        for(int i = 0; i < edges.size(); ++i) {
            if(dist1[i] != -1 && dist2[i] != -1) {
                int mx = max(dist1[i], dist2[i]);
                if(mx < best) {
                    best = mx;
                    ans = i;
                }
            }
        }
        return ans;
    }
};