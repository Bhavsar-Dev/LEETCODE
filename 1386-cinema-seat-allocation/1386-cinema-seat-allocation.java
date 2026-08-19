class Solution {
    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {
        HashMap<Integer, HashSet<Integer>> mp = new HashMap<>();
        for(int[] x : reservedSeats) {
            mp.computeIfAbsent(x[0], k -> new HashSet<>()).add(x[1]);
        }
        int ans = (n - mp.size()) * 2;
        for(HashSet<Integer> s : mp.values()) {
            boolean a = true;
            boolean b = true;
            boolean c = true;
            for(int i = 2; i <= 5; ++i) {
                if(s.contains(i)) a = false;
            }
            for(int i  =4; i <= 7; ++i) {
                if(s.contains(i)) b = false;
            }
            for(int i = 6; i <= 9; ++i) {
                if(s.contains(i)) c = false;
            }
            if(a && c) {
                ans += 2;
            }
            else if(a || b || c) ans += 1;
        }
        return ans;
    }
}