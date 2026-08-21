class Solution {
    public double knightProbability(int n, int k, int row, int column) {
        int[][] mov = {{2,1}, {2,-1}, {-2, 1}, {-2,-1}, {1,2}, {1,-2},{-1,2},{-1,-2}};
        double[][] dp = new double[n][n];
        dp[row][column] = 1.0;
        for(int s = 0; s < k; ++s) {
            double[][] nex = new double[n][n];
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n;++j) {
                    if(dp[i][j] == 0) continue;
                    for(int[] move: mov) {
                        int ni = i + move[0];
                        int nj = j + move[1];
                        if(ni >= 0 && ni < n && nj >= 0 && nj < n) {
                            nex[ni][nj] += dp[i][j] / 8.0;
                        }
                    }
                }
            }
            dp= nex;
        }
        double ans = 0.0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                ans += dp[i][j];
            }
        }
        return ans;
    }
}