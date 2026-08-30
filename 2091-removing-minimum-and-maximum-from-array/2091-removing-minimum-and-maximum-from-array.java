class Solution {
    public int minimumDeletions(int[] nums) {
        int n = nums.length;
        int mini = 0, maxi = 0;
        for(int i = 1; i < n; ++i) {
            if(nums[i] < nums[mini]) mini = i;
            if(nums[i] > nums[maxi]) maxi = i;
        }
        int l = Math.min(mini, maxi);
        int r = Math.max(mini, maxi);
        int fr = r + 1;
        int fb = n - l;
        int b = (l + 1) + (n - r);
        return Math.min(fr, Math.min(fb, b));
    }
}