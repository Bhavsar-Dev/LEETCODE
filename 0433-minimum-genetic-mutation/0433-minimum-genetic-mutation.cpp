class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());
        if(!st.count(endGene)) return -1;
        queue<pair<string, int>> q;
        q.push({startGene, 0});
        unordered_set<string> vis;
        vis.insert(startGene);
        string ch = "ACGT";
        while(!q.empty()) {
            auto [s, step] = q.front();
            q.pop();
            if(s == endGene) return step;
            for(int i = 0; i < 8; i++) {
                char old = s[i];
                for(char c : ch) {
                    if(c == old) continue;
                    s[i] = c;
                    if(st.count(s) && !vis.count(s)) {
                        vis.insert(s);
                        q.push({s, step + 1});
                    }
                }
                s[i] = old;
            }
        }
        return -1;
    }
};