class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        heights.push_back(0); // Add a zero height to ensure stack is emptied at the end
        int maxArea = 0;
        
        for (int i = 0; i < heights.size(); ++i) {
            while (!s.empty() && heights[i] < heights[s.top()]) {
                int h = heights[s.top()];
                s.pop();
                int w = s.empty() ? i : i - s.top() - 1;
                maxArea = max(maxArea, h * w);
            }
            s.push(i);
        }
        
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> height(cols, 0);
        int maxArea = 0;
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    height[j]++;
                } else {
                    height[j] = 0;
                }
            }
            maxArea = max(maxArea, largestRectangleArea(height));
        }
        
        return maxArea;
        
    }
};