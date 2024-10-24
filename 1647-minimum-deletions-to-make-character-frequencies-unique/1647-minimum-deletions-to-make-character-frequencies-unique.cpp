class Solution {
public:
    int minDeletions(string s) {
           unordered_map<char, int> freq;  // Frequency map

    // Step 1: Count the frequency of each character
    for (char c : s) {
        freq[c]++;
    }

    set<int> usedFreq;  // Set to store unique frequencies
    int deletions = 0;

    // Step 2: Iterate through each character's frequency
    for (auto& entry : freq) {
        int currentFreq = entry.second;

        // Keep reducing the frequency until it's unique
        while (currentFreq > 0 && usedFreq.find(currentFreq) != usedFreq.end()) {
            currentFreq--;
            deletions++;  // Increment the number of deletions
        }

        // Store the unique frequency in the set
        if (currentFreq > 0) {
            usedFreq.insert(currentFreq);
        }
    }

    return deletions;
    }
};