class Solution {
    public int totalNumbers(int[] digits) {
        int ans = 0;
        int[] freq = new int[10];
        for(int d : digits) freq[d]++;
        for(int i = 100; i <= 999; ++i) {
            if(i % 2 != 0) continue;
            int a = i / 100;
            int b = (i / 10) % 10;
            int c = i % 10;
            int[] temp = freq.clone();
            temp[a]--;
            temp[b]--;
            temp[c]--;
            if(temp[a] >= 0 && temp[b] >= 0 && temp[c] >= 0) ans++;
        }
        return ans;
    }
}