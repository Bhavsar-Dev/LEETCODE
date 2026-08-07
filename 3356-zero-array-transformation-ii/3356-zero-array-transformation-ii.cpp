class Solution {
public:
bool check(int k, vector<int>& nums, vector<vector<int>>& q) {
    int n = nums.size();
    vector<int> diff(n + 1, 0);
    for(int i = 0; i < k; ++i) {
        diff[q[i][0]] += q[i][2];
        if(q[i][1] + 1 < n) diff[q[i][1] + 1] -= q[i][2];
    }
    int cur= 0;
    for(int i =0; i < n; ++i) {
        cur += diff[i];
        if(cur < nums[i]) return false;
    }
    return true;
}
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int m = queries.size();
        if(!check(m, nums, queries)) return -1;
        int l = 0, r = m;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(check(mid, nums, queries)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};