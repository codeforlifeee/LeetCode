#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(int n) {
        int maxi = -1;
        string str = to_string(n);

        for (int i = 0; i < str.length(); i++) {
            for (int j = i + 1; j < str.length(); j++) {
                int d1 = str[i] - '0';
                int d2 = str[j] - '0';
                maxi = max(maxi, d1 * d2);
            }
        }

        return maxi;
    }
};
