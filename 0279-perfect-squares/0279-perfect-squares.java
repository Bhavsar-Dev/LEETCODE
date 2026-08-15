// class Solution {
//     int f(int n) {
//         if(n == 0) return 0;
//         int ans = Integer.MAX_VALUE;
//         for(int i= 1; i * i <= n; ++i) {
//             ans = Math.min(ans, 1 + f(n - i * i));
//         }
//         return ans;
//     }
//     public int numSquares(int n) {
//         return f(n);
//     }
// }

// class Solution {
//     int f(int n, int[] dp) {
//         if(n == 0) return 0;
//         if(dp[n] != -1) return dp[n];
//         int ans = Integer.MAX_VALUE;
//         for(int i = 1; i * i <= n; ++i) {
//             ans = Math.min(ans, 1 + f(n - i * i, dp));
//         }
//         return dp[n] = ans;
//     }
//     public int numSquares(int n) {
//         int[] dp = new int[n + 1];
//         Arrays.fill(dp, -1);
//         return f(n, dp);
//     }
// }

class Solution {
    public int numSquares(int n) {
        int[] dp = new int[n + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j * j <= i; ++j) {
                dp[i] = Math.min(dp[i], dp[i - j * j] + 1);
            } 
        }
        return dp[n];
    }
}