class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        int ans = 0, last = INT_MIN;
        for(auto &p : pairs) {
            if(p[0] > last) {
                ans++;
                last = p[1];
            }
        }
        return ans;
    }
};