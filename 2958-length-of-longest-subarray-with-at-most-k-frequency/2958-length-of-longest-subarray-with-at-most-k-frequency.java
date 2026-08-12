class Solution {
    public int maxSubarrayLength(int[] nums, int k) {
        HashMap<Integer, Integer> freq = new HashMap<>();
        int l = 0, ans = 0;
        for(int ri = 0; ri < nums.length; ri++) {
            freq.put(nums[ri], freq.getOrDefault(nums[ri], 0) + 1);
            while(freq.get(nums[ri]) > k) {
                freq.put(nums[l], freq.get(nums[l]) - 1);
                l++;
            }
            ans = Math.max(ans, ri - l+ 1);
        }
        return ans;
    }
}