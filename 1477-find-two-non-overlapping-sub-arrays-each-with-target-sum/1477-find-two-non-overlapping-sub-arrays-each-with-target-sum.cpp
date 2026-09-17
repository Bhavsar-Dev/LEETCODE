class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;
        vector<int> be(n, INF);
        long long l = 0, sum = 0;
        int ans = INF;
        for(int r = 0; r < n; ++r) {
            sum += arr[r];
            while(sum > target) sum -= arr[l++];
            if(r > 0) be[r] = be[r - 1];
            if(sum == target) {
                int len = r - l + 1;
                if(l > 0 && be[l - 1] != INF) {
                    ans = min(ans, len + be[l - 1]);
                }
                be[r] = min(be[r], len);
            }
        }
        return ans == INF ? -1 : ans;
    }
};