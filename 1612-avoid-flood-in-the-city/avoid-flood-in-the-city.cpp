class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, -1);

        unordered_map<int, int> lastRain;  // lake -> last rainy day
        set<int> dryDays;                  // indices of dry days

        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                dryDays.insert(i);
            } else {
                int lake = rains[i];

                // If lake already full → must dry it before today
                if (lastRain.count(lake)) {
                    int last = lastRain[lake];

                    // find earliest dry day > last rain
                    auto it = dryDays.upper_bound(last);
                    if (it == dryDays.end()) {
                        return {}; // flood unavoidable
                    }

                    ans[*it] = lake;   // dry this lake
                    dryDays.erase(it);
                }

                lastRain[lake] = i;
                ans[i] = -1;
            }
        }

        // remaining dry days → dry any lake (doesn't matter)
        for (int day : dryDays) {
            ans[day] = 1;
        }

        return ans;
    }
};
