class Solution {
public:
    string reverseWords(string s){
          stringstream ss(s);  // Step 1: Create an input string stream object
        string word, result;   // Step 2: Variables to store individual words and the final result
        
        while(ss>>word){       // Step 3: Extract each word from the input string
            reverse(word.begin(),word.end());  // Step 4: Reverse the extracted word
            if (!result.empty()) result += " ";  // Step 5: Add a space if result is not empty
            result+=word;        // Step 6: Append the reversed word to the result string
        }
        return result;  // Step 7: Return the final result string with all words reversed
    }
};