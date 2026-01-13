class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double total = 0.0;
        double lo = 1e18, hi = -1e18;

        for (auto &s : squares) {
            total += 1.0 * s[2] * s[2];
            lo = min(lo, (double)s[1]);
            hi = max(hi, (double)s[1] + s[2]);
        }

        double half = total / 2.0;

        auto areaBelow = [&](double y) {
            double area = 0.0;
            for (auto &s : squares) {
                double yi = s[1], l = s[2];
                double h = min(max(y - yi, 0.0), l);
                area += h * l;
            }
            return area;
        };

        for (int i = 0; i < 80; i++) {
            double mid = (lo + hi) / 2.0;
            if (areaBelow(mid) < half)
                lo = mid;
            else
                hi = mid;
        }

        return lo;
    }
};
