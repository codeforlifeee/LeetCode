class Solution {
public:
    int reverse(int x) {
        long revNum;
        while(x!=0){
            int last_digit = x%10;
            revNum = revNum*10 + last_digit;
            x = x/10;
        }
        if(revNum>INT_MAX || revNum < INT_MIN) {
            return 0;
        }
        return revNum;
    }
};