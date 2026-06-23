class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int t) {
        int m = a.size();
        int n = a[0].size();
        int l = 0, r = m * n - 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            int x = a[mid / n][mid % n];
            if(x== t) return true;
            if(x < t) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};