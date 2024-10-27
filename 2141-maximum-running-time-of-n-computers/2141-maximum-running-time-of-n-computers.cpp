#define ll long long
class Solution {
public:
  
    
     bool canRunFor(ll t, int n, vector<int>& batteries) {
        ll totalPower = 0;
        for (int battery : batteries) {
            totalPower += min((long long)battery, t);
        }
        return totalPower >= t * n;
    }
    
    
    ll maxRunTime(int n, vector<int>& batteries) {
        ll left = 1, right = accumulate(batteries.begin(), batteries.end(), 0LL) / n;
        ll result = 0;

        while (left <= right) {
            ll mid = left + (right - left) / 2;
            
            if (canRunFor(mid, n, batteries)) {
                result = mid;  
                left = mid + 1;  
            } else {
                right = mid - 1;  
            }
        }

        return result;
    }
};
