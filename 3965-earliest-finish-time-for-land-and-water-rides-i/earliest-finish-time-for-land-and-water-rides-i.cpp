#include <bits/stdc++.h>
using namespace std;

class Solution {
    using ll = long long;

    ll solveOrder(const vector<pair<ll,ll>>& A,
                  vector<pair<ll,ll>>& B) {
        int m = B.size();
        sort(B.begin(), B.end(),
             [](auto &x, auto &y){ return x.first < y.first; });

        vector<ll> starts(m), prefMinDur(m), suffMinFinish(m);
        for(int i = 0; i < m; i++) {
            starts[i] = B[i].first;
            ll dur = B[i].second;
            prefMinDur[i] = (i == 0 ? dur : min(prefMinDur[i-1], dur));
        }

        for(int i = m-1; i >= 0; i--) {
            ll finish = B[i].first + B[i].second;
            suffMinFinish[i] = (i == m-1
                                ? finish
                                : min(suffMinFinish[i+1], finish));
        }

        ll best = LLONG_MAX;
        for(auto &a : A) {
            ll tA = a.first + a.second;
            int idx = int(upper_bound(starts.begin(), starts.end(), tA)
                          - starts.begin()) - 1;

            if(idx >= 0) {
                best = min(best, tA + prefMinDur[idx]);
            }
            if(idx + 1 < m) {
                best = min(best, suffMinFinish[idx+1]);
            }
        }
        return best;
    }

public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        vector<pair<ll,ll>> land(n), water(m);
        for(int i = 0; i < n; i++) {
            land[i] = {landStartTime[i], landDuration[i]};
        }
        for(int j = 0; j < m; j++) {
            water[j] = {waterStartTime[j], waterDuration[j]};
        }

        ll ans1 = solveOrder(land, water);
        ll ans2 = solveOrder(water, land);
        return int(min(ans1, ans2));
    }
};