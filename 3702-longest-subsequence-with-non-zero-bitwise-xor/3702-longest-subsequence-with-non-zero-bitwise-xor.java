class Solution {
    public int longestSubsequence(int[] nums) {
        int n = nums.length, xor = 0;
        boolean ok = false;
        for(int num : nums) {
            xor ^= num;
            if(num != 0) ok = true;
        }
        if(xor != 0) return n;
        if(ok) return n - 1;
        return 0;
    }
}