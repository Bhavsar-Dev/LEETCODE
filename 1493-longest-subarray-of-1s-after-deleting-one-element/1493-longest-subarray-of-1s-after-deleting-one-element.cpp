class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, z = 0, ans = 0;
        for(int r = 0; r < nums.size(); ++r) {
            if(nums[r] == 0) z++;
            while(z > 1) {
                if(nums[l] == 0) z--;
                l++;
            }
            ans = max(ans, r - l);
        }
        return ans;
    }
};