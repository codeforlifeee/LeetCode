class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }
        
        bool sign = (dividend >= 0) == (divisor>=0);
        
        long n = abs(dividend);
        long d= abs(divisor);
        long quotient = 0;
        
        while (n >= d) {
            long temp = d, multiple = 1;
            while (n >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            n -= temp;
            quotient += multiple;
        }
        
        quotient = sign ? quotient : -quotient;
        return (quotient > INT_MAX) ? INT_MAX : quotient;
    }
};