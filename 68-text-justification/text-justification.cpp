class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;
        
        while (i < n) {
            int j = i + 1;
            int lineLength = words[i].length();
            
            // Find how many words fit in the current line
            while (j < n && lineLength + 1 + words[j].length() <= maxWidth) {
                lineLength += 1 + words[j].length();
                j++;
            }
            
            int numWords = j - i;
            int numSpaces = maxWidth - (lineLength - (numWords - 1));
            string line = "";
            
            // Case 1: Last line or only one word in the line -> Left-justify
            if (j == n || numWords == 1) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) line += " ";
                }
                line += string(maxWidth - line.length(), ' ');
            } 
            // Case 2: Standard line -> Fully-justify (distribute spaces evenly)
            else {
                int baseSpaces = numSpaces / (numWords - 1);
                int extraSpaces = numSpaces % (numWords - 1);
                
                for (int k = i; k < j - 1; k++) {
                    line += words[k];
                    line += string(baseSpaces + (k - i < extraSpaces ? 1 : 0), ' ');
                }
                line += words[j - 1]; // Append the last word without trailing spaces
            }
            
            result.push_back(line);
            i = j; // Move to the next line of words
        }
        
        return result;
    }
};
