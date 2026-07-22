class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> v;
        for(int i = 0; i < n; i++) {
            double t = (double)(target - position[i]) / speed[i];
            v.push_back({position[i], t});
        }
        sort(v.begin(), v.end(), greater<pair<int, double>>());
        int ans = 0;
        double mx = 0;
        for(int i = 0; i < n; i++) {
            if(v[i].second > mx) {
                ans++;
                mx = v[i].second;
            }
        }
        return ans;
    }
};