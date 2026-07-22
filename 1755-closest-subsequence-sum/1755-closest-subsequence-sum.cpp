class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        int m = n/2;
        int k = n - m;
        vector<long long> l, r;
        int l1 = 1 << m;
        for(int ma = 0; ma<l1; ++ma) {
            long long sum = 0;
            for(int i = 0; i < m; ++i) {
                if(ma & (1 << i)) {
                    sum += nums[i];
                }
            }
            l.push_back(sum);
        } 
        int l2 = 1 << k;
        for(int ma = 0; ma < l2; ++ma) {
            long long sum = 0;
            for(int i = 0; i < k; ++i) {
                if(ma & (1 << i)) {
                    sum += nums[m + i];
                }
            }
            r.push_back(sum);
        }
        sort(r.begin(), r.end());
        long long ans = LLONG_MAX;
        for(long long s : l) {
            long long t = goal - s;
            auto it = lower_bound(r.begin(), r.end(), t);
            if(it != r.end()) {
                ans = min(ans, abs(s + *it - goal));
            }
            if(it != r.begin()) {
                --it;
                ans = min(ans, abs(s + *it - goal));
            }
        }
        return ans;
    }
};