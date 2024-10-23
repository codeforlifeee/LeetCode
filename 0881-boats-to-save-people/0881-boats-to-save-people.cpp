class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();
        int boat = 0;
        
        int i = 0;
        int j = n - 1;
        
        while(i <= j){
            if(people[i] + people [j] <= limit ){
                boat = boat + 1;
                i = i + 1;
                j = j - 1;
            }else{
                j--;
                boat = boat + 1;
            }
    
        }
        return boat;
    } 
    
};