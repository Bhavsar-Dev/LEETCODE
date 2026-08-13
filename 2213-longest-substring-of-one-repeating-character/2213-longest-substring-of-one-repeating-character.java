class Solution {
    class Node {
        char l, r;
        int pre, suf, best, len;
        Node(char c) {
            l = r = c;
            pre = suf = best = len = 1;
        }
        Node() {}
    }
    Node[] st;
    public int[] longestRepeating(String s, String queryCharacters, int[] queryIndices) {
        int n = s.length();
        int k = queryIndices.length;
        st = new Node[4 * n];
        build(1, 0, n - 1, s);
        int[] ans = new int[k];
        for(int i = 0; i < k; i++) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters.charAt(i));
            ans[i] = st[1].best;
        }
        return ans;
    }
    void build(int p, int l, int r, String s) {
        if(l == r) {
            st[p] = new Node(s.charAt(l));
            return;
        }
        int m = (l + r) / 2;
        build(p * 2, l, m, s);
        build(p * 2 + 1, m + 1, r, s);
        st[p] = merge(st[p * 2], st[p * 2 + 1]);
    }
    void update(int p, int l, int r, int idx, char c) {
        if(l == r) {
            st[p] = new Node(c);
            return;
        }
        int m = (l + r) / 2;
        if(idx <= m) update(p * 2, l, m, idx, c);
        else update(p * 2 + 1, m + 1, r, idx, c);
        st[p] = merge(st[p * 2], st[p * 2 + 1]);
    }
    Node merge(Node a, Node b) {
        Node x = new Node();
        x.len = a.len + b.len;
        x.l = a.l;
        x.r = b.r;
        x.pre = a.pre;
        if(a.pre == a.len && a.r == b.l) x.pre = a.len + b.pre;
        x.suf = b.suf;
        if(b.suf == b.len && a.r == b.l) x.suf = b.len + a.suf;
        x.best = Math.max(a.best, b.best);
        if(a.r == b.l) x.best = Math.max(x.best, a.suf + b.pre);
        return x;
    }
}