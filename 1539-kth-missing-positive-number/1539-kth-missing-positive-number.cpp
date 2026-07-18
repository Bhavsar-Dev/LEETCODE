class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for(int i = 0; i < arr.size(); ++i) {
            int miss = arr[i] - (i + 1);
            if(miss >= k) return k + i;
        }
        return k + arr.size();
    }
};