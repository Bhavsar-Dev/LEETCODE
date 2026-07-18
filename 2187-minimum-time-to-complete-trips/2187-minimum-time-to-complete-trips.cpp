class Solution {
public:
using ll = long long;
    long long minimumTime(vector<int>& time, int totalTrips) {
        ll l = 1;
        ll r = (ll)* min_element(time.begin(), time.end()) * totalTrips;
        while(l < r) {
            ll m = l + (r - l) / 2;
            ll trips = 0;
            for(int t : time) {
                trips += m / t;
                if(trips >= totalTrips) break;
            }
            if(trips >= totalTrips) r = m;
            else l = m  + 1;
        }
        return l;
    }
};