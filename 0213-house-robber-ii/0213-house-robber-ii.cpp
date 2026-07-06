class Solution {
public:
    int sol(vector<int>& nums, int l, int r) {
        int p1 = 0, p2 = 0;
        for(int i = l; i <= r; ++i) {
            int cur = max(p1, p2 + nums[i]);
            p2 = p1;
            p1 = cur;
        }
        return p1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int a = sol(nums, 0, n - 2);
        int b = sol(nums, 1, n - 1);
        return max(a, b);
    }
};