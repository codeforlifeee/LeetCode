class Solution {
public:
    
    int t[366];
    int solve(vector<int>& days, vector<int>& costs, int index) {
        int n = days.size();
        
         if(t[index] != -1) return t[index];
        
        if(index >= n) return 0;
        
       

        int cost1 = costs[0] + solve(days, costs, index + 1);
        

        int i = index;
        
        
        while (i < n && days[i] < days[index] + 7) {
            i++;
        }
        
        
        int cost2 = costs[1] + solve(days, costs, i);

        i = index;
        
        
        while (i < n && days[i] < days[index] + 30) {
            i++;
        }
        
        
        int cost3 = costs[2] + solve(days, costs, i);
        

        return t[index] = min({cost1, cost2, cost3});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        memset(t,-1,sizeof(t));
        
        return solve(days, costs, 0); 
    }
};
