class Solution {
public:
    using ll = long long;
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        map<ll, ll> mp;
        ll ans = LLONG_MIN;
        for(int i = 0; i < nums.size(); i++) {
            ll k = (ll)nums[i] - i;
            ll cur = nums[i];
            auto it = mp.upper_bound(k);
            if(it != mp.begin()) {
                --it;
                cur = max(cur, it->second + (ll)nums[i]);
            }
            ans = max(ans, cur);
            it = mp.lower_bound(k);
            if(it != mp.end() && it->first == k) {
                if(it->second >= cur) continue;
                it->second = cur;
            } 
            else {
                it = mp.insert({k, cur}).first;
            }
            auto nx = next(it);
            while(nx != mp.end() && nx->second <= it->second) {
                auto t = nx;
                ++nx;
                mp.erase(t);
            }
        }
        return ans;
    }
};