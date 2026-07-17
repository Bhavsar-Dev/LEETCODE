class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<long long> f(mx + 1, 0);
        for(int x : nums) f[x]++;
        vector<long long> cnt(mx + 1, 0);
        for(int g = 1; g <= mx; g++) {
            for(int j = g; j <= mx; j += g) cnt[g] += f[j];
        }
        vector<long long> exact(mx + 1, 0);
        for(int g = mx; g >= 1; g--) {
            exact[g] = cnt[g] * (cnt[g] - 1) / 2;
            for (int j = 2 * g; j <= mx; j += g)
                exact[g] -= exact[j];
        }
        vector<long long> pre(mx + 1, 0);
        for(int g = 1; g <= mx; g++)
            pre[g] = pre[g - 1] + exact[g];
        vector<int> ans;
        for(long long q : queries) {
            int l = 1, r = mx;
            while(l < r) {
                int m = (l + r) / 2;
                if(pre[m] > q) r = m;
                else l = m + 1;
            }
            ans.push_back(l);
        }
        return ans;
    }
};