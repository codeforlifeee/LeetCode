class Solution {
public:
    string numberToWords(int num) {
        
        if (num == 0) return "Zero";

        const vector<string> below_20{"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
                                       "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
                                       "Seventeen", "Eighteen", "Nineteen"};
        
        const vector<string> below_100{"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        
        const vector<string> thousands{"", "Thousand", "Million", "Billion"};

        // Helper function to convert numbers less than 1000 into words
        auto convert_less_than_1000 = [&](int num) -> string {
            string result;
            if (num >= 100) {
                result += below_20[num / 100] + " Hundred ";
                num %= 100;
            }
            if (num >= 20) {
                result += below_100[num / 10] + " ";
                num %= 10;
            }
            if (num > 0) {
                result += below_20[num] + " ";
            }
            return result;
        };

        // Main function to convert the number into words
        string result;
        int i = 0;

        while (num > 0) {
            if (num % 1000 != 0) {
                result = convert_less_than_1000(num % 1000) + thousands[i] + " " + result;
            }
            num /= 1000;
            i++;
        }

        // Remove any extra spaces at the end
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }

        return result;
    }
    

        
        
    
};