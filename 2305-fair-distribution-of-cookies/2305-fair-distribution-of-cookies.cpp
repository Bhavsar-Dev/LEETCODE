class Solution {
public:
int ans = INT_MAX;
void dfs(vector<int>& cookies, vector<int>& child, int idx) {
    if(idx == cookies.size()){
        int mx = 0;
        for(int x : child) mx = max(mx, x);
        ans = min(ans, mx);
        return;
    }
    for(int i = 0; i < child.size(); ++i) {
        child[i] += cookies[idx];
        dfs(cookies, child, idx+1);
        child[i] -= cookies[idx];
        if(child[i] == 0) break;
    }
}
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> child(k, 0);
        dfs(cookies, child, 0);
        return ans;
    }
};