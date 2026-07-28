class Solution {
public:
vector<string> ans;
string cur;
vector<string> mp = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void dfs(string& d, int idx) {
    if(idx == d.size()) {
        ans.push_back(cur);
        return;
    }
    string s = mp[d[idx] - '0'];
    for(char c :s) {
        cur.push_back(c);
        dfs(d, idx + 1);
        cur.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        dfs(digits, 0);
        return ans;
    }
};