#include<vector>
#include<iostream>

class Solution {
public:
    bool checkCarryNeeded(int digt_value){
        return digt_value == 9;
    }
    void appendOverflowDigit(vector<int>& digits_array){
        digits_array.insert(digits_array.begin(), 1);
    }

    vector<int> plusOne(vector<int>& input_digits) {

        int digit_count = input_digits.size();
        for(int cursor = digit_count -1; cursor >=0; cursor--){
            if(checkCarryNeeded(input_digits[cursor])){
                input_digits[cursor] = 0;
            }else{
                input_digits[cursor]++;
                return input_digits;
            }
        }
        appendOverflowDigit(input_digits);
        return input_digits;        
    }
};