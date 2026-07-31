class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0, bot = m- 1, l = 0, r= n - 1;
        while(top <= bot && l <= r) {
            for(int j = l; j <= r; ++j) {
                ans.push_back(matrix[top][j]);
            }
            top++;
            for(int i = top; i <= bot; ++i) {
                ans.push_back(matrix[i][r]);
            }
            r--;
            if(top <= bot) {
                for(int j = r; j >= l; --j) {
                    ans.push_back(matrix[bot][j]);
                }
                bot--;
            }
            if(l <= r) {
                for(int i = bot; i >= top; --i) {
                    ans.push_back(matrix[i][l]);
                }
                l++;
            }
        }
        return ans;
    }
};