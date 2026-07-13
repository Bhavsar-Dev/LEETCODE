class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int> ans;
        int l1 = to_string(low).size();
        int l2 = to_string(high).size();
        for(int i = l1; i <= l2; ++i) {
            for(int j = 0; j + i <= 9; ++j) {
                int num = stoi(s.substr(j, i));
                if(num >= low && num <= high) {
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};