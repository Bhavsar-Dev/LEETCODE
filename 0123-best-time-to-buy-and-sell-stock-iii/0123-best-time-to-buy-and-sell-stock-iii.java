class Solution {
    public int maxProfit(int[] prices) {
        int b1 = Integer.MIN_VALUE, b2 = Integer.MIN_VALUE;
        int s1 = 0, s2 = 0;
        for(int pri : prices){
            b1 = Math.max(b1, -pri);
            s1 = Math.max(s1, b1 + pri);
            b2 = Math.max(b2, s1 - pri);
            s2 = Math.max(s2, b2 + pri);
        }
        return s2;
    }
}