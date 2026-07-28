class Solution {
public:
int ans = 0;
void dfs(vector<vector<int>>& req, vector<int>& bal, int idx, int cnt) {
    if(idx == req.size()) {
        for(int x : bal) {
            if(x != 0) return;
        }
        ans = max(ans, cnt);
        return;
    }
    int fr = req[idx][0];
    int to = req[idx][1];
    bal[fr]--;
    bal[to]++;
    dfs(req, bal, idx + 1, cnt +1);
    bal[fr]++;
    bal[to]--;
    dfs(req, bal, idx + 1, cnt);
}
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> bal(n, 0);
        dfs(requests, bal, 0, 0);
        return ans;
    }
};