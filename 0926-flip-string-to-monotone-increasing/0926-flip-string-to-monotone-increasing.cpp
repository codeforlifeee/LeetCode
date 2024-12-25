class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int count_ones = 0;
        int flip = 0;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '1') count_ones++;
            else flip = min(flip+1, count_ones);
        }
        return min(count_ones, flip);
    }
};