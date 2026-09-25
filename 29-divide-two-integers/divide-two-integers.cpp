class Solution {
public:
    int divide(int dividend, int divisor) {
        // Explicit overflow edge case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determine the sign of the result
        bool isNegative = (dividend < 0) ^ (divisor < 0);

        // Convert to 64-bit integers to safely handle abs(INT_MIN)
        long long d = abs((long long)dividend);
        long long q = abs((long long)divisor);
        long long ans = 0;

        while (d >= q) {
            long long temp = q;
            long long multiple = 1;

            // Double the divisor until it exceeds d
            while (d >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            d -= temp;
            ans += multiple;
        }

        if (isNegative) ans = -ans;

        // Clamp to 32-bit signed integer range
        if (ans > INT_MAX) return INT_MAX;
        if (ans < INT_MIN) return INT_MIN;

        return (int)ans;
    }
};