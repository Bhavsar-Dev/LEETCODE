class Solution {
    struct F {
        int x = 0, y = 0, z = 0, w = 0;
    };
    F get(int d) {
        if(d == 2) return {1, 0, 0, 0};
        if(d == 3) return {0, 1, 0, 0};
        if(d == 4) return {2, 0, 0, 0};
        if(d == 5) return {0, 0, 1, 0};
        if(d == 6) return {1, 1, 0, 0};
        if(d == 7) return {0, 0, 0, 1};
        if(d == 8) return {3, 0, 0, 0};
        if(d == 9) return {0, 2, 0, 0};
        return {0, 0, 0, 0};
    }
    int need6(long long a, long long b) {
        a = max(0LL, a);
        b = max(0LL, b);
        return (a + 2) / 3 + (b + 1) / 2;
    }
    int need(long long a, long long b, long long c, long long d) {
        a = max(0LL, a);
        b = max(0LL, b);
        c = max(0LL, c);
        d = max(0LL, d);
        int ans = c + d + need6(a, b);
        if(a > 0 && b > 0) ans = min(ans, (int)(c + d + 1 + need6(a - 1, b - 1)));
        return ans;
    }
    string build(long long a, long long b, long long c, long long d, int len) {
        a = max(0LL, a);
        b = max(0LL, b);
        c = max(0LL, c);
        d = max(0LL, d);
        int m = need(a, b, c, d);
        string s(len - m, '1');
        for(int i = 0; i < m; i++) {
            int left = m - i - 1;
            for(int dig = 1; dig <= 9; dig++) {
                F f = get(dig);
                long long na = max(0LL, a - f.x);
                long long nb = max(0LL, b - f.y);
                long long nc = max(0LL, c - f.z);
                long long nd = max(0LL, d - f.w);
                if(need(na, nb, nc, nd) <= left) {
                    s += char('0' + dig);
                    a = na;
                    b = nb;
                    c = nc;
                    d = nd;
                    break;
                }
            }
        }
        return s;
    }
public:
    string smallestNumber(string num, long long t) {
        long long a = 0, b = 0, c = 0, d = 0;
        while(t % 2 == 0) a++, t /= 2;
        while(t % 3 == 0) b++, t /= 3;
        while(t % 5 == 0) c++, t /= 5;
        while(t % 7 == 0) d++, t /= 7;
        if(t > 1) return "-1";
        int n = num.size();
        int z = n;
        for(int i = 0; i < n; i++) {
            if(num[i] == '0') {
                z = i;
                break;
            }
        }
        vector<long long> p2(n + 1), p3(n + 1), p5(n + 1), p7(n + 1);
        for(int i = 0; i < z; i++) {
            F f = get(num[i] - '0');
            p2[i + 1] = p2[i] + f.x;
            p3[i + 1] = p3[i] + f.y;
            p5[i + 1] = p5[i] + f.z;
            p7[i + 1] = p7[i] + f.w;
        }
        if(z == n) {
            if(p2[n] >= a && p3[n] >= b && p5[n] >= c && p7[n] >= d) return num;
        }
        int last = min(n - 1, z);
        for(int i = last; i >= 0; i--) {
            long long ra = max(0LL, a - p2[i]);
            long long rb = max(0LL, b - p3[i]);
            long long rc = max(0LL, c - p5[i]);
            long long rd = max(0LL, d - p7[i]);
            int st = (i < z ? num[i] - '0' + 1 : 1);
            int rem = n - i - 1;
            for(int dig = st; dig <= 9; dig++) {
                F f = get(dig);
                long long na = max(0LL, ra - f.x);
                long long nb = max(0LL, rb - f.y);
                long long nc = max(0LL, rc - f.z);
                long long nd = max(0LL, rd - f.w);
                if(need(na, nb, nc, nd) <= rem) {
                    string ans = num.substr(0, i);
                    ans += char('0' + dig);
                    ans += build(na, nb, nc, nd, rem);
                    return ans;
                }
            }
        }
        int len = max((long long)n + 1, (long long)need(a, b, c, d));
        return build(a, b, c, d, len);
    }
};