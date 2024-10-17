class Solution {
public:
    void backtrack(const string& digits, int index, const unordered_map<char, string>& phoneMap, string& current, vector<string>& result){
    if(index == digits.length()){
        result.push_back(current);
        return;
    }
        char digit = digits[index];
        const string& letters = phoneMap.at(digit);
        
        for(char letter : letters){
            current.push_back(letter);
            backtrack(digits, index+1, phoneMap, current, result);
            current.pop_back();
        }
    
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        unordered_map<char, string>phoneMap = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };
        vector<string> result;
        string current;
        backtrack(digits, 0, phoneMap, current, result);
        return result;
    }
};