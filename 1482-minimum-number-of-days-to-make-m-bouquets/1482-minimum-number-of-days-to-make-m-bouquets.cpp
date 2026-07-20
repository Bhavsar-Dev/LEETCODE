class Solution {
public:
    bool ok(vector<int>& a, int d, int m, int k) {
        int f = 0, b = 0;
        for(int x : a) {
            if(x <= d) {
                f++;
                if(f == k) {
                    b++;
                    f = 0;
                }
            } 
            else {
                f = 0;
            }
        }
        return b >= m;
    }
    int minDays(vector<int>& a, int m, int k) {
        if ((long long)m * k > a.size()) return -1;
        int l = *min_element(a.begin(), a.end());
        int r = *max_element(a.begin(), a.end());
        int ans = r;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(ok(a, mid, m, k)) {
                ans = mid;
                r = mid - 1;
            } 
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};