class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxDiag = 0.0;
        int maxArea = 0;

        for (auto &d : dimensions) {
            int l = d[0], w = d[1];
            double diag = hypot(l, w);
            int area = l * w;

            if (diag > maxDiag) {
                maxDiag = diag;
                maxArea = area;
            } 
            else if (diag == maxDiag) {
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};
