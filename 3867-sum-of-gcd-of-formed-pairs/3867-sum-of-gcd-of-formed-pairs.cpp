class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> a;
        long long mx = 0;
        for(int x: nums) {
            mx = max(mx, 1LL * x);
            a.push_back(gcd(mx, 1LL * x));
        }
        sort(a.begin(), a.end());
        long long ans = 0;
        int l = 0, r = n - 1;
        while(l < r) {
            ans += gcd(a[l], a[r]);
            l++;
            r--;
        }
        return ans;
    }
};