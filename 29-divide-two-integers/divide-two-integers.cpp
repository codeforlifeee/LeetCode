class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend==INT_MIN && divisor==-1) return INT_MAX;
        long long a=llabs((long long)dividend), b=llabs((long long)divisor), res=0;
        while (a>=b) {
            long long t=b, m=1;
            while ((t<<1)<=a) { t<<=1; m<<=1; }
            a-=t; res+=m;
        }
        if ((dividend>0)^(divisor>0)) res=-res;
        return (int)res;
    }
};
