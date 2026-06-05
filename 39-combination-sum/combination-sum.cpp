class Solution {
public:

void findCombinations(int index, const vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(current);
        return;
    }
    if (target < 0 || index >= candidates.size()) {
        return;
    }

    // Recurse: index, not index+1, because we can reuse same element unlimited times
    // Include the current candidate
    current.push_back(candidates[index]);
    findCombinations(index, candidates, target - candidates[index], current, result); // Allow same element to be used again

    // Exclude the current candidate
    current.pop_back();
    findCombinations(index + 1, candidates, target, current, result); // Move to the next candidate
} // TC: O(2^n) worst, SC: O(target)


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int>> result;
    vector<int> current;
    findCombinations(0, candidates, target, current, result);
    return result;

        
    }
};