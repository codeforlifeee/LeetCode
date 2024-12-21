class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        
        string con = "";
        
        for(string s : words){
            con = con + s;
        }
        
        sort(con.begin(), con.end());
        unordered_map<char, int>freq_map;
        for (char c : con){
            freq_map[c]++;
        }
        
        for(const auto& entry : freq_map){
            if(entry.second%n != 0){
                return false; 
            }
        }
        return true; 
    }
};