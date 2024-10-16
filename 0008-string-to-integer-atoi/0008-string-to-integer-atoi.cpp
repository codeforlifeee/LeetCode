class Solution {
public:
    int myAtoi(string s) {
        stringstream ss(s);
        long long num = 0;
        ss>>num;
        
         if(num>= INT_MAX) return INT_MAX;
         if(num<=INT_MIN) return INT_MIN;

        
        return num;
        
    }
};