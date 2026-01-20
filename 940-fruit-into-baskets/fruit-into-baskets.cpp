#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> count;
        int left = 0, maxFruits = 0;

        for (int right = 0; right < fruits.size(); right++) {
            count[fruits[right]]++;

            // Shrink window if more than 2 types
            while (count.size() > 2) {
                count[fruits[left]]--;
                if (count[fruits[left]] == 0) count.erase(fruits[left]);
                left++;
            }

            // Window size = sum of frequencies of top 2 types (all types in window)
            maxFruits = max(maxFruits, right - left + 1);
        }

        return maxFruits;
    }
};
