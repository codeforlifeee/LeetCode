class Solution {
public:
    int pivotInteger(int n) {
        if(n == 1){
            return 1;
        }
        
        int totalSum = n*(n+1)/2;
        
        for(int pivot = 1; pivot<=n;pivot++) {
            
            int leftSum  = pivot*(pivot+1)/2;
            int rightSum = totalSum - leftSum + pivot;
            
            if(leftSum == rightSum){
                return pivot;
            }
        }
        
        return -1;
    }
};
