class Solution {
public:
    int productMaker(int n) {
        int prod = 1;
        while (n > 0) {
            int digit = n % 10;
            prod = prod * digit;
            n = n / 10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {

        for (int i = 0; i < 100; i++) {
            if (productMaker(n+i) % t == 0)
                return n + i;
        }
        return 0;
    }
};