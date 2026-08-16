class Solution {
    public int elevatorRequests(int n, int[] requests) {
        int cur = 0, ans = 0;
        for(int x: requests) {
            ans += Math.abs(cur - x);
            cur = x;
        }
        return ans;
    }
}