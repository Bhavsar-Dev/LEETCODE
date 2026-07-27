class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = a.size(), m = b.size();
        int i = 0, j = 0;
        vector<vector<int>> ans;
        while(i < n || j < m) {
            int t;
            if(i == n) t = b[j][0];
            else if(j == m) t = a[i][0];
            else t = min(a[i][0], b[j][0]);
            long long x = 0, y = 0;
            if(i < n) x = a[i][1];
            if(j < m) y = b[j][1];
            ans.push_back({t, (int)(x + y)});
            if(i < n && a[i][0] == t) ++i;
            if(j < m && b[j][0] == t) ++j;
        }
        return ans;
    }
};