class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
            int n = fruits.size();
    vector<bool> used(n, false);
    int unplaced = 0;

    for (int i = 0; i < n; i++) {          // fruits left to right
        bool placed = false;

        for (int j = 0; j < n; j++) {      // baskets left to right
            if (!used[j] && baskets[j] >= fruits[i]) {
                used[j] = true;
                placed = true;
                break;                     // leftmost basket
            }
        }

        if (!placed) unplaced++;
    }

    return unplaced;

    }
};