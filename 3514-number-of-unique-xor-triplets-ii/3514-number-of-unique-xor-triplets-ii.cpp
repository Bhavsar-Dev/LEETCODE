class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int M = 2048;
        vector<int> dp(M, 0), ndp(M, 0);
        dp[0] = 1;
        for(int t = 0; t < 3; ++t) {
            fill(ndp.begin(), ndp.end(), 0);
            for(int x = 0; x < M; ++x) {
                if(!dp[x]) continue;
                for(int v : nums) {
                    ndp[x ^ v] = 1;
                }
            }
            dp = ndp;
        }
        int ans = 0;
        for(int x : dp) ans += x;
        return ans;
    }
};