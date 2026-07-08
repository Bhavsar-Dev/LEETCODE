class Solution {
public:
    static const int MOD = 1000000007;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> pos, d;
        for(int i = 0; i < n; i++) {
            if(s[i] != '0') {
                pos.push_back(i);
                d.push_back(s[i] - '0');
            }
        }
        int k = d.size();
        vector<long long> pw(k + 1, 1);
        for(int i = 1; i <= k; i++)
            pw[i] = (pw[i - 1] * 10) % MOD;
        vector<long long> pre(k + 1, 0), sum(k + 1, 0);
        for(int i = 1; i <= k; i++) {
            pre[i] = (pre[i - 1] * 10 + d[i - 1]) % MOD;
            sum[i] = sum[i - 1] + d[i - 1];
        }
        vector<int> ans;
        for(auto &q : queries) {
            int l = q[0], r = q[1];
            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;
            if(L > R) {
                ans.push_back(0);
                continue;
            }
            int len = R - L + 1;
            long long x = (pre[R + 1] - pre[L] * pw[len]) % MOD;
            if(x < 0) x += MOD;
            long long s = sum[R + 1] - sum[L];
            ans.push_back((x * (s % MOD)) % MOD);
        }
        return ans;
    }
};