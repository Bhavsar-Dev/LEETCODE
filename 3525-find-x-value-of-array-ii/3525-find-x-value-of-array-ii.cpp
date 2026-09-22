class Solution {
public:
    struct Node {
        int prod;
        int cnt[5];
        Node() { 
            prod = 1;
            for(int i = 0; i < 5; i++) cnt[i] = 0;
        }
    };
    int n, k;
    vector<Node> seg;
    vector<int> nums;
    Node merge(Node &A, Node &B) {
        Node C;
        C.prod = (A.prod * B.prod) % k;
        for(int r = 0; r < k; r++) {
            C.cnt[r] += A.cnt[r];
        }
        for(int r = 0; r < k; r++) {
            int newRem = (A.prod * r) % k;
            C.cnt[newRem] += B.cnt[r];
        }
        return C;
    }
    void build(int node, int l, int r) {
        if(l == r) {
            int rem = nums[l] % k;
            seg[node].prod = rem;
            seg[node].cnt[rem] = 1;
            return;
        }
        int mid = (l + r) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }
    void update(int node, int l, int r, int pos, int val) {
        if(l == r) {
            int rem = val % k;
            seg[node] = Node();
            seg[node].prod = rem;
            seg[node].cnt[rem] = 1;
            return;
        }
        int mid = (l + r) / 2;
        if(pos <= mid) update(node * 2, l, mid, pos, val);
        else update(node * 2 + 1, mid + 1, r, pos, val);
        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }
    Node query(int node, int l, int r, int ql, int qr) {
        if(ql <= l && r <= qr) {
            return seg[node];
        }
        int mid = (l + r) / 2;
        if(qr <= mid) {
            return query(node * 2, l, mid, ql, qr);
        }
        if(ql > mid) {
            return query(node * 2 + 1, mid + 1, r, ql, qr);
        }
        Node left = query(node * 2, l, mid, ql, qr);
        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);
        return merge(left, right);
    }
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        this->nums = nums;
        this->k = k;
        this->n = nums.size();
        seg.resize(4 * n + 5);
        build(1, 0, n - 1);
        vector<int> ans;
        for(auto &q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];
            nums[index] = value;
            update(1, 0, n - 1, index, value);
            Node res = query(1, 0, n - 1, start, n - 1);
            ans.push_back(res.cnt[x]);
        }
        return ans;
    }
};