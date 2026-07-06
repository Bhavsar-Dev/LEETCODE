class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        int ans = 0, mx = -1;
        for(auto &v : intervals) {
            if(v[1] > mx) {
                ans++;
                mx = v[1];
            }
        }
        return ans;
    }
};