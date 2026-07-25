#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(int n) {
        int max1 = -1, max2 = -1;
        vector<int> hashTable(10, 0);

        while (n != 0) {
            int digit = n % 10;
            hashTable[digit]++;
            n /= 10;
        }

        for (int i = 9; i >= 0; i--) {
            if (hashTable[i] >= 2 && max1 == -1 && max2 == -1) {
                max1 = i;
                max2 = i;
                break;
            }

            if (hashTable[i] > 0) {
                if (max1 == -1)
                    max1 = i;
                else if (max2 == -1 && max1 != i)
                    max2 = i;
            }
        }

        return max1 * max2;
    }
};