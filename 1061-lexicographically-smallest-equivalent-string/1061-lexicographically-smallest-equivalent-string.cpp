class Solution {
public:
vector<int>p;
int find(int x) {
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}
void uni(int a, int b) {
    a = find(a);
    b= find(b);
    if(a == b) return;
    if(a < b) p[b] = a;
    else p[a] = b;
}
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        p.resize(26);
        for(int i = 0; i < 26; ++i) p[i] = i;
        for(int i = 0; i < s1.size(); ++i) uni(s1[i] - 'a', s2[i] - 'a');
        for(char &c : baseStr) c = char(find(c - 'a') + 'a');
        return baseStr;
    }
};