class Solution {
    struct B {
        int l, r, len;
    };
    struct ST {
        int n;
        vector<int> t;
        ST(int sz) {
            n = sz;
            t.assign(4 * n + 1, 0);
        }
        void upd(int i, int s, int e, int p, int v) {
            if(s == e) {
                t[i] = v;
                return;
            }
            int m = s + (e - s) / 2;
            if(p <= m) upd(i * 2, s, m, p, v);
            else upd(i * 2 + 1, m + 1, e, p, v);
            t[i] = max(t[i * 2], t[i * 2 + 1]);
        }
        int qry(int i, int s, int e, int l, int r) {
            if(r < s || e < l) return 0;
            if(l <= s && e <= r) return t[i];
            int m = s + (e - s) / 2;
            return max(qry(i * 2, s, m, l, r), qry(i * 2 + 1, m + 1, e, l, r));
        }
    };
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& q) {
        int n = s.size();
        int one = 0;
        for(char c : s)
            if(c == '1') one++;
        vector<B> b;
        for(int i = 0; i < n;) {
            if(s[i] == '0') {
                int j = i;
                while(j < n && s[j] == '0') j++;
                b.push_back({i, j - 1, j - i});
                i = j;
            } 
            else {
                i++;
            }
        }
        int m = b.size();
        ST st(max(1, m - 1));
        if(m >= 2) {
            for(int i = 0; i < m - 1; i++){
                st.upd(1, 0, m - 2, i, b[i].len + b[i + 1].len);
            }
                
        }
        vector<int> ans;
        ans.reserve(q.size());
        for(auto &v : q) {
            int l = v[0], r = v[1];
            int add = 0;
            if(m >= 2) {
                int f = -1, e = -1;
                auto it1 = lower_bound(b.begin(), b.end(), l, [](const B &x, int y) {
                        return x.r < y;
                    });
                if(it1 != b.end() && it1->l <= r) f = it1 - b.begin();
                auto it2 = upper_bound(b.begin(), b.end(), r, [](int y, const B &x) {
                        return y < x.l;
                    });
                if(it2 != b.begin()) {
                    --it2;
                    if(it2->r >= l) e = it2 - b.begin();
                }
                if(f != -1 && e != -1 && f < e) {
                    int x = b[f].r - max(b[f].l, l) + 1;
                    int y = min(b[e].r, r) - b[e].l + 1;
                    if(e == f + 1) {
                        add = x + y;
                    } 
                    else {
                        add = max(add, x + b[f + 1].len);
                        add = max(add, b[e - 1].len + y);
                        if(f + 1 <= e - 2) add = max(add, st.qry(1, 0, m - 2, f + 1, e - 2));
                    }
                }
            }
            ans.push_back(one + add);
        }
        return ans;
    }
};