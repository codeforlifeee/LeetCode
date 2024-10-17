class Solution {
public:
    double myPow(double x, int n) {
        
         long long N = n;  // Use long long to handle large negative values
        if (N < 0) {  
            x = 1 / x;  // Take reciprocal for negative powers
            N = -N;     // Work with positive exponent now
        }

        double ans = 1.0;  // Initialize answer

        while (N > 0) {
            if (N % 2 == 1) {  // If N is odd
                ans *= x;
                N -= 1;
            } else {  // If N is even
                x *= x;
                N /= 2;
            }
        }
        return ans;
        
    }
};