class Solution {
public:
    const long long LIM = 1000001;
    long long C(int n, int r) {
        if(r < 0 || r > n) return 0;
        r = min(r, n - r);
        long long res = 1;
        for(int i = 1; i <= r; i++) {
            res = res * (n - r + i) / i;
            if(res > LIM) return LIM;
        }
        return res;
    }
    long long ways(vector<int>& cnt) {
        int rem = 0;
        for(int x : cnt) rem += x;
        long long ans = 1;
        for(int c : cnt) {
            if(c == 0) continue;
            ans *= C(rem, c);
            if(ans > LIM) return LIM;
            rem -= c;
        }
        return min(ans, LIM);
    }
    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for(char c : s) freq[c - 'a']++;
        vector<int> half(26, 0);
        string mid = "";
        int len = 0;
        for(int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            len += half[i];
            if(freq[i] % 2) mid.push_back(char('a' + i));
        }
        if(ways(half) < k) return "";
        string left;
        for(int pos = 0; pos < len; pos++) {
            for(int c = 0; c < 26; c++) {
                if(half[c] == 0) continue;
                half[c]--;
                long long cnt = ways(half);
                if(cnt >= k) {
                    left.push_back(char('a' + c));
                    break;
                }
                k -= cnt;
                half[c]++;
            }
        }
        string right = left;
        reverse(right.begin(), right.end());
        return left + mid + right;
    }
};