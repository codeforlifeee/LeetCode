class Solution {
 /*
 Approach:
 first iterate a to c with condtition that square of a <=c
 
 then calculate the value of b for corresponding a 
 
 and then find the if the there is some number b which satisfy
 
 b*b = b_s
 and 
 b = sqrt(b_s)
 
 */
public:
    bool judgeSquareSum(int c) {
        long long a, b;
        for(a =0; a*a <= c; a++){
            long long b_s = c - a*a;
            long long b = sqrt(b_s);
            if(b*b == b_s) return true;
        }
        return false; 
    }
};