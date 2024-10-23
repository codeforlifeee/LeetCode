class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int score = 0;
        int n = tokens.size();
        int i = 0;
        int j = n-1;
        
        int maxScore = 0;
        while(i  <= j){
            if(power>=tokens[i]){
                    power = power- tokens[i];
                score = score + 1;
            
                i++;
                maxScore = max(score, maxScore);
            }else if( score >= 1){
                score = score -1;
                power = power + tokens[j];
                j--;
            }else{
                return maxScore;
            }
        }
        return maxScore;
        
    }
};