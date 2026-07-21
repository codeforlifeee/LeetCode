class Solution {
public:
    int maxActiveSectionsAfterTrade(string S) {
            int n = S.size();
    int original_count = 0;
    for (char ch : S) {
        if (ch == '1') {
            original_count++;
        }
    }
    
    int best = original_count;

    int i = 0;
    while (i < n) {
        if (S[i] == '1') {

            int j = i;
            while (j < n && S[j] == '1') {
                j++;
            }
 
            if (i > 0 && j < n && S[i - 1] == '0' && S[j] == '0') {
       
                int left_zeros = 0;
                int k = i - 1;
                while (k >= 0 && S[k] == '0') {
                    left_zeros++;
                    k--;
                }
                
         
                int right_zeros = 0;
                k = j;
                while (k < n && S[k] == '0') {
                    right_zeros++;
                    k++;
                }


                
            
                int candidate = original_count + left_zeros + right_zeros;
                candidate = min(candidate, n); 
                best = max(best, candidate);
            }


            
            i = j;
        } else {
            i++;

            
        }
    }
    
    return best;
    }
};
