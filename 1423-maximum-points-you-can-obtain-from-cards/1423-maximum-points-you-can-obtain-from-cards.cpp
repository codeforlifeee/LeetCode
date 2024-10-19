class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n= cardPoints.size();
        int totalSum = 0;
        for(int i = 0; i<k; i++){
            totalSum += cardPoints[i];
        }
        int maxScore = totalSum;
        int currentSum = totalSum;
        
        for(int i = 0; i<k; i++){
            currentSum -= cardPoints[k-1-i];
            currentSum += cardPoints[n-1-i];
            
            maxScore = max(maxScore, currentSum);
        
        }
        return maxScore;
        
    }
};