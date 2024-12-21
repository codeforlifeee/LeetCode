class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char,int>firstoccur;
        int maxi = -1;

        for(int i = 0;i<s.length();i++){
            char c = s[i];

            if(firstoccur.find(c) != firstoccur.end()){
                int length = i - firstoccur[c]-1;
                maxi = max(maxi, length);
            } else {
                firstoccur[c] = i;
            }
        }
        return maxi;
    }
};