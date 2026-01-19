class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int a = 1; a < n; a++) {
            int b = n - a;
            if (noZero(a) && noZero(b)) {
                return {a, b};
            }
        }
        return {};
    }

    bool noZero(int x) {
        string s = to_string(x);
        return s.find('0') == string::npos;
    }
};
