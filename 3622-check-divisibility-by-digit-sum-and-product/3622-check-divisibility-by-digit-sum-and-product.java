class Solution {
    public boolean checkDivisibility(int n) {
        int temp = n, sum = 0, prod = 1;
        while(temp > 0) {
            int digi = temp % 10;
            sum += digi;
            prod *= digi;
            temp /= 10;
        }
        return n % (sum + prod) == 0;
    }
}