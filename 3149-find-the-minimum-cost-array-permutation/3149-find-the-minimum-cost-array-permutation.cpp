class Solution {
public:
    int n;
    vector<int> nums;
    vector<vector<int>> dp;
    vector<vector<int>> nxtChoice;
    int dfs(int mask, int last) {
        if(mask == (1 << n) - 1) return abs(last - nums[0]);
        if(dp[mask][last] != -1) return dp[mask][last];
        int best = INT_MAX;
        int pick = -1;
        for(int nxt = 1; nxt < n; nxt++) {
            if(mask & (1 << nxt)) continue;
            int cur = abs(last - nums[nxt]) + dfs(mask | (1 << nxt), nxt);
            if(cur < best || (cur == best && nxt < pick)) {
                best = cur;
                pick = nxt;
            }
        }
        nxtChoice[mask][last] = pick;
        return dp[mask][last] = best;
    }
    vector<int> findPermutation(vector<int>& a) {
        nums = a;
        n = nums.size();
        dp.assign(1 << n, vector<int>(n, -1));
        nxtChoice.assign(1 << n, vector<int>(n, -1));
        dfs(1, 0);
        vector<int> ans;
        ans.push_back(0);
        int mask = 1;
        int last = 0;
        while(true) {
            int nxt = nxtChoice[mask][last];
            if (nxt == -1) break;
            ans.push_back(nxt);
            mask |= 1 << nxt;
            last = nxt;
        }
        return ans;
    }
};