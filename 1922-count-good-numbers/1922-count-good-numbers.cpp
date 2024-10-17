class Solution {
public:
    const long long p = 1e9 + 7;
    long long power(long long x, long long n) {
        long long ans = 1;
        while (n > 0) {
            if (n % 2 == 1) {
                ans = (ans * x) % p;
                n -= 1;
            } else {  
                x = (x * x) % p;
                n /= 2;
            }
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long count_of_4s = n / 2; 
        long long count_of_5s = n - count_of_4s;
        long long result = (power(4, count_of_4s) * power(5, count_of_5s)) % p;
        return (int)result;
    }
};
