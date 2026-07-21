class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long sum = 0, l = 0, ans = 1;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            while(nums[i] * (i - l + 1) - sum > k) {
                sum -= nums[l];
                l++;
            }
            ans = max(ans, i - l + 1);
        }
        return ans;
    }
};