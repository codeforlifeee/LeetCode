

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prevDeviceCount = 0; 
        int result = 0;

        for (string& row : bank) {
            int currDeviceCount = 0;
            
            for (char ch : row) {
                if (ch == '1') {
                    currDeviceCount++;
                }
            }

            if (currDeviceCount > 0) {
                result += prevDeviceCount * currDeviceCount;
                prevDeviceCount = currDeviceCount;
            }
        }

        return result;
    }
};
