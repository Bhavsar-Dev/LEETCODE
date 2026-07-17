class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1), par(n);
        int mx = 1, idx = 0;
        for(int i = 0; i < n; ++i) {
            par[i] = i;
            for(int j = 0; j < i; ++j) {
                if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    par[i] = j;
                }
            }
            if(dp[i] > mx) {
                mx = dp[i];
                idx = i;
            }
        }
        vector<int> ans;
        while(par[idx] != idx) {
            ans.push_back(nums[idx]);
            idx = par[idx];
        }
        ans.push_back(nums[idx]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};