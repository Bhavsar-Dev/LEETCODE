class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        int pos = 0;
        set<string> result = parse(expression, pos);
        return vector<string>(result.begin(), result.end());
    }
private:
    set<string> parse(string& s, int& pos) {
        set<string> result;
        set<string> current = {""};
        while(pos < s.size() && s[pos] != '}') {
            if(s[pos] == ',') {
                for(string word : current) {
                    result.insert(word);
                }
                current = {""};
                pos++;
            }
            else {
                set<string> part;
                if(s[pos] == '{') {
                    pos++;
                    part = parse(s, pos);
                    pos++;
                }
                else {

                    part.insert(string(1, s[pos]));
                    pos++;
                }
                set<string> next;
                for(string a : current) {
                    for(string b : part) {
                        next.insert(a + b);
                    }
                }
                current = next;
            }
        }
        for(string word : current) {
            result.insert(word);
        }
        return result;
    }
};