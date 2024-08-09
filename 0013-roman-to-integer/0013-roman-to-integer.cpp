class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanValues = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int total = 0;
    int n = s.size();

    for (int i = 0; i < n; ++i) {
        int currentVal = romanValues[s[i]];
//---------------------------------------------------------------------------------------//
        // Check if the next symbol exists and its value is greater
        if (i + 1 < n && romanValues[s[i]] < romanValues[s[i + 1]]) {
            total -= currentVal;//subract
        } else {
            total += currentVal;//add
        }
//----------------------------------------------------------------------------------------//
    }

    return total;
        
    }
};