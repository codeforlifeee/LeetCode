class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;

        vector<int> rem1;
        vector<int> rem2;

        for (int &num : nums) {
            sum += num;
            if (num % 3 == 1) {
                rem1.push_back(num);
            } else if (num % 3 == 2) {
                rem2.push_back(num);
            }
        }

        if (sum % 3 == 0) return sum;

        sort(rem1.begin(), rem1.end());
        sort(rem2.begin(), rem2.end());

        int rem = sum % 3;
        int res = 0;

        if (rem == 1) {
            // Option 1: remove one element of remainder 1
            int remove1 = (rem1.size() >= 1 ? rem1[0] : INT_MAX);

            // Option 2: remove two elements of remainder 2
            int remove2 = (rem2.size() >= 2 ? rem2[0] + rem2[1] : INT_MAX);

            res = sum - min(remove1, remove2);
        } 
        else { // rem == 2
            // Option 1: remove one element of remainder 2
            int remove1 = (rem2.size() >= 1 ? rem2[0] : INT_MAX);

            // Option 2: remove two elements of remainder 1
            int remove2 = (rem1.size() >= 2 ? rem1[0] + rem1[1] : INT_MAX);

            res = sum - min(remove1, remove2);
        }

        return res;
    }
};
