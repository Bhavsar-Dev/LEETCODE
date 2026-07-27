class Solution {
public:
using ll = long long;
const ll MOD = 1000000007;
ll po(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) {
            ans = ans * a % MOD;
        }
        a = a * a % MOD;
        b /= 2;
    }
    return ans;
}
    int countValidSequences(int n, int k) {
        vector<ll> fact(n + 1), inv(n + 1);
        fact[0] = 1;
        for(int i = 1; i <= n; ++i) {
            fact[i] = fact[i - 1] * i % MOD;
        }
        inv[n] = po(fact[n], MOD - 2);
        for(ll i = n; i > 0; --i) {
            inv[i - 1] = inv[i] * i % MOD;
        }
        auto C = [&](int n, int r) -> ll {
            if(r < 0 || r > n) return 0;
            return fact[n] * inv[r] % MOD * inv[n - r] % MOD;
        };
        ll tot = C(n- 1, k - 1);
        ll odd = 0;
        if((n - k) % 2 == 0) {
            int x = (n + k - 2) / 2;
            odd = C(x, k - 1);
        }
        return (tot - odd + MOD) % MOD;
    }
};