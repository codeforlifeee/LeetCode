class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        vector<int> result = {-1, -1};
        int maxQuality = -1;
        
        for (auto& tower : towers) {
            int x = tower[0];
            int y = tower[1];
            int quality = tower[2];
            
            // Calculate Manhattan distance
            int distance = abs(x - center[0]) + abs(y - center[1]);
            
            // Check if tower is reachable
            if (distance <= radius) {
                // Update result if this tower is better
                if (quality > maxQuality || 
                    (quality == maxQuality && (x < result[0] || (x == result[0] && y < result[1])))) {
                    result = {x, y};
                    maxQuality = quality;
                }
            }
        }
        
        return result;
    }
};