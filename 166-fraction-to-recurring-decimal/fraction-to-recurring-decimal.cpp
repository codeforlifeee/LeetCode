class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
            if (numerator == 0) return "0";
    
    string result;

    // Check for negative result
    if ((numerator < 0) ^ (denominator < 0)) {
        result += "-";
    }

    // Convert to long to handle overflow
    long long num = abs((long long)numerator);
    long long den = abs((long long)denominator);

    // Add integer part
    result += to_string(num / den);
    long long remainder = num % den;

    // If no remainder, return result
    if (remainder == 0) return result;

    result += ".";

    // Map to store previously seen remainders and their positions
    unordered_map<long long, int> remainder_map;

    while (remainder != 0) {
        // If the remainder is already seen, repeating part found
        if (remainder_map.find(remainder) != remainder_map.end()) {
            result.insert(remainder_map[remainder], "(");
            result += ")";
            break;
        }

        // Store the position of the remainder
        remainder_map[remainder] = result.length();

        remainder *= 10;
        result += to_string(remainder / den);
        remainder %= den;
    }

    return result;

    }
};