class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<pair<int,int>> events;

        for (auto &log : logs) {
            events.push_back({log[0], +1}); // birth
            events.push_back({log[1], -1}); // death
        }

        //Sort events
        sort(events.begin(), events.end());

        int curr = 0, maxPop = 0, result = 0;

        for (auto &e : events) {
            curr += e.second;
            if (curr > maxPop) {
                maxPop = curr;
                result = e.first;
            }
        }

        return result;
    }
};

