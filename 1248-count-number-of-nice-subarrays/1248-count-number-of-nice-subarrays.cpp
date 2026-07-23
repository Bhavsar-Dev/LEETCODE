class Solution {
public:
    int solve(vector<int>& nums, int k) {
        if(k < 0) return 0;
        int l = 0, cnt = 0, ans = 0;
        for(int r = 0; r < nums.size(); ++r) {
            if(nums[r] % 2) cnt++;
            while(cnt > k) {
                if(nums[l] % 2) cnt--;
                l++;
            }
            ans += r - l + 1;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};