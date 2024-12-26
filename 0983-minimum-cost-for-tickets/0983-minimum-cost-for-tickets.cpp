class Solution {
public:    
    int bottomUp(vector<int>& days, vector<int>& costs) {
        unordered_set<int> st(begin(days), end(days));
        int last_day = days.back();
        
        vector<int> t(last_day+1, 0);
        //t[i] = min cost to reach till day i of your travel plan
        t[0] = 0; //since, on day 0, we spend cost = 0
        
        for(int i = 1; i<=last_day; i++) {
            if(st.find(i) == st.end()) {
                t[i] = t[i-1]; //skip
                continue;
            }
            //you need to filter those days from 1 to 30 which are not in days vector
            t[i] = INT_MAX;
            
            //I come to i either by taking a 1-day pass from jth day
            int day_1_pass = t[max(0, i-1)] + costs[0];

            //I come to i either by taking a 7-day pass from jth day
            int day_7_pass = t[max(0,i-7)] + costs[1];

            //I come to i either by taking a 30-day pass from jth day
            int day_30_pass = t[max(0, i-30)] + costs[2];
            
            t[i] = min({day_1_pass, day_7_pass, day_30_pass});
        }
        
        return t[last_day]; //minimum cost to travel till my last planned day
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return bottomUp(days, costs);     
    }
};
