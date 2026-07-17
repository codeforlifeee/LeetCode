class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int max_val = 0;
        for(int num : nums){
            if(num > max_val){
                max_val = num;
            }
        }

        vector<long long> val_freq(max_val + 1, 0);

        for(int num : nums){
            val_freq[num]++;
        }

        vector<long long> exact_gcd_count(max_val+1,0);

        for(int g = max_val; g >= 1; g--){
            long long multiples_count = 0;

            for(int multiple = g ; multiple <= max_val; multiple += g){
                multiples_count += val_freq[multiple];
            }

            long long total_pairs = (multiples_count* (multiples_count -1))/2;

            for(int multiple = 2*g; multiple <= max_val; multiple += g){
                total_pairs -= exact_gcd_count[multiple];
            }
            exact_gcd_count[g] = total_pairs;
        }

        vector<long long> prefix_gcd_counts(max_val +1, 0);

        for(int g = 1; g <= max_val;g++){
            prefix_gcd_counts[g] = prefix_gcd_counts[g-1] + exact_gcd_count[g];
        }

        vector<int> results;

        results.reserve(queries.size());

        for(long long query : queries){

            auto it = upper_bound(prefix_gcd_counts.begin(), prefix_gcd_counts.end(), query);

            results.push_back(distance(prefix_gcd_counts.begin(), it));
        }
        return results;
        
    }
};