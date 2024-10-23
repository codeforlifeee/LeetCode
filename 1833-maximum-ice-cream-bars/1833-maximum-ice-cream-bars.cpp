class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
         sort(costs.begin() , costs.end());
         if(costs[0] > coins){
            return 0;
        }
        
        int sum = 0;
        int count =0 ;
        for(int i = 0; i<costs.size(); i++){
            sum = sum + costs[i];
            
            if(sum<= coins){
              count++;
                
            }else{
                break;
            }
        }
       return count;
       
        
    }
};