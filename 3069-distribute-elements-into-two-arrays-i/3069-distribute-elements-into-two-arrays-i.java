class Solution {
    public int[] resultArray(int[] nums) {
        int n = nums.length;
        int[] arr1 = new int[n];
        int[] arr2 = new int[n];
        int s1 = 1;
        int s2 = 1;
        arr1[0] = nums[0];
        arr2[0] = nums[1];
        for(int i = 2; i < n; ++i) {
            if(arr1[s1 - 1] > arr2[s2- 1]) {
                arr1[s1] = nums[i];
                s1++;
            }
            else {
                arr2[s2] = nums[i];
                s2++;
            }
        }
        int[] ans = new int[n];
        for(int i = 0; i < s1; ++i) ans[i] = arr1[i];
        for(int i = 0; i < s2; ++i) ans[s1 + i] = arr2[i];
        return ans;
    }
}