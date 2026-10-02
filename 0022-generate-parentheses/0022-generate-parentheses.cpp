class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        function<void(string, int, int)> f = [&](string s, int op, int cl) {
            if(s.size() == 2 * n) {
                ans.push_back(s);
                return;
            }
            if(op < n) {
                f(s + '(', op + 1, cl);
            }
            if(cl < op) {
                f(s + ')', op, cl + 1);
            }
        };
        f("", 0, 0);
        return ans;
    }
};