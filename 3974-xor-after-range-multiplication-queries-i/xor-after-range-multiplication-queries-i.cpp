using ll = long long;
const ll MOD = 1e9 +7 ;
class Solution {
public:
    // static ll modpower(ll a, ll e){
    //     ll r = 1;
    //     while(e > 0){
    //         if(e& 1) r = r *1%MOD;
    //         a = a*a %MOD;
    //         e >>= 1;
    //     }
    //     return r;
    // }
    // static ll inv(ll x){
    //     return modpower(x, MOD - 2);
    // }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries){
        for(auto &q : queries){
            int l = q[0], r = q[1], k = q[2];

            ll v = q[3];

            if(k <=  0) continue;

            for(int idx =l; idx<=r; idx += k){

                nums[idx] = (nums[idx]*v)%MOD;
            }
        }
        ll ans = 0;
        for(ll x : nums) ans = ans^x;
        return ans;
        
    }
};