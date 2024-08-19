class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        long long area1 = (long long)(ax2 - ax1) * (ay2 - ay1);
        long long area2 = (long long)(bx2 - bx1) * (by2 - by1);

        int x_dist = min(ax2, bx2) - max(ax1, bx1);
        int y_dist = min(ay2, by2) - max(ay1, by1);

        int toSub = 0;
        if (x_dist > 0 && y_dist > 0) {
            toSub = (long long)x_dist * y_dist;
        }

        return (int)(area1 + area2 - toSub);   
    }
};