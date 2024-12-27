class Solution {
public:
    typedef long long ll;
    ll n;
    ll t[1000001];
    ll solve(vector<vector<int>>& questions, ll i) {
        if (i >= n) return 0;
        
        if(t[i] != -1) return t[i];

        ll take = questions[i][0] + solve(questions, i + questions[i][1] + 1);
        ll skip = solve(questions, i + 1);

        return t[i] = max(take, skip);
    }

    ll mostPoints(vector<vector<int>>& questions) {
        n = questions.size();
        memset(t,-1,sizeof(t));
        return solve(questions, 0);
    }
};
