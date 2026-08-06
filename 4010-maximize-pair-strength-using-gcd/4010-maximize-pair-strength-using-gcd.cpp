class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                long long g = gcd(nums[i], nums[j]);
                long long cur = 1LL * nums[i] * nums[j] / (g * g);
                ans = max(ans, cur);
            }
        }
        return ans;
    }
};