class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int>mp;
        for(string word: words){
            mp[word]++;
        }
        
        bool centerused =false;
        int result = 0;
        
        for(string word : words){
            string rev = word;
            reverse(rev.begin(), rev.end());
            if(rev != word){
                if(mp[word]>0 && mp[rev]>0){
                    mp[word]--;
                    mp[rev]--;
                    result  = result + 4;
                }
            }else{
                if(mp[word] >= 2){
                    mp[word] = mp[word] - 2;
                    result = result + 4;
                }else if(mp[word] == 1 && centerused == false){
                    mp[word]--;
                    result = result + 2;
                    centerused = true;
                }
            }
        }
        return result;
    }
};