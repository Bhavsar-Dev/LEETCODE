//TOP-DOWN

// class Solution {
// public:
//     vector<int> pref;
//     vector<int> dp;
//     int n;
//     int f(int i) {
//         if(i == n - 1) return pref[n - 1];
//         if(dp[i] != INT_MIN) return dp[i];
//         int take = pref[i] - f(i + 1);
//         int nottake = f(i + 1);
//         return dp[i] = max(take, nottake);
//     }
//     int stoneGameVIII(vector<int>& stones) {
//         n = stones.size();
//         pref.resize(n);
//         dp.assign(n, INT_MIN);
//         pref[0] = stones[0];
//         for(int i = 1; i < n; ++i) {
//             pref[i] = pref[i - 1] + stones[i];
//         }
//         return f(1);
//     }
// };


class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> pref(n);
        pref[0] = stones[0];
        for(int i = 1; i < n; ++i) {
            pref[i] = pref[i - 1] + stones[i];
        }
        vector<int> dp(n);
        dp[n - 1] = pref[n - 1];
        for(int i = n - 2; i >= 1; --i) {
            int take = pref[i] - dp[i + 1];
            int nottake = dp[i + 1];
            dp[i] = max(take, nottake);
        }
        return dp[1];
    }
};