class Solution {
    public int missingMultiple(int[] nums, int k) {
        for(int i = k; ; i += k) {
            boolean f = false;
            for(int num : nums) {
                if(num == i) {
                    f = true;
                    break;
                }
            }
            if(!f) return i;
        }
    }
}