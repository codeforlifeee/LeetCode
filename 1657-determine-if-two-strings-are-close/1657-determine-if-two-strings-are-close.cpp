class Solution {
public:
    bool closeStrings(string str1, string str2) {

        if (str1.length() != str2.length()) {
            return false;
        }

        set<char> set1, set2; 
        unordered_map<char, int> freq1, freq2; 

        for (char ch : str1) {
            set1.insert(ch);
            freq1[ch]++;
        }

        for (char ch : str2) {
            set2.insert(ch);
            freq2[ch]++;
        }

        if (set1 != set2) {
            return false;
        }

        vector<int> vec1, vec2;
        for (char ch : set1) {
            vec1.push_back(freq1[ch]);
            vec2.push_back(freq2[ch]);
        }

        sort(vec1.begin(), vec1.end());
        sort(vec2.begin(), vec2.end());

        return vec1 == vec2;
        
    }
};