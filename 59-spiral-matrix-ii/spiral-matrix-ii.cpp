#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> spiral_grid(n, std::vector<int>(n, 0));
        
        int top_row = 0;
        int bottom_row = n - 1;
        int left_column = 0;
        int right_column = n - 1;
        
        int current_val = 1;
        
        while (top_row <= bottom_row && left_column <= right_column) {
            // Fill the top row from left to right
            for (int col = left_column; col <= right_column; ++col) {
                spiral_grid[top_row][col] = current_val++;
            }
            top_row++;
            
            // Fill the right column from top to bottom
            for (int row = top_row; row <= bottom_row; ++row) {
                spiral_grid[row][right_column] = current_val++;
            }
            right_column--;
            
            // Fill the bottom row from right to left
            if (top_row <= bottom_row) {
                for (int col = right_column; col >= left_column; --col) {
                    spiral_grid[bottom_row][col] = current_val++;
                }
                bottom_row--;
            }
            
            // Fill the left column from bottom to top
            if (left_column <= right_column) {
                for (int row = bottom_row; row >= top_row; --row) {
                    spiral_grid[row][left_column] = current_val++;
                }
                left_column++;
            }
        }
        
        return spiral_grid;
    }
};
