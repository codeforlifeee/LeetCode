class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int rows = points.size(), cols = points[0].size();
        vector<long long> prev_Row(cols);

        for (int col = 0; col < cols; ++col) {
            prev_Row[col] = points[0][col];
        }

        // Process each row
        for (int row = 0; row < rows - 1; ++row) {
            vector<long long> leftMax(cols);
            vector<long long> rightMax(cols);
            vector<long long> currentRow(cols);

            leftMax[0] = prev_Row[0];
            for (int col = 1; col < cols; ++col) {
                leftMax[col] = max(leftMax[col - 1] - 1, prev_Row[col]);
            }
            rightMax[cols - 1] = prev_Row[cols - 1];
            for (int col = cols - 2; col >= 0; --col) {
                rightMax[col] = max(rightMax[col + 1] - 1, prev_Row[col]);
            }
            for (int col = 0; col < cols; ++col) {
                currentRow[col] =
                    points[row + 1][col] + max(leftMax[col], rightMax[col]);
            }
            prev_Row = currentRow;
        }

        long long maxPoints = 0;
        for (int col = 0; col < cols; ++col) {
            maxPoints = max(maxPoints, prev_Row[col]);
        }

        return maxPoints;
    }
};