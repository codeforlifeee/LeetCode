#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximizeSquareArea(long long m, long long n, vector<int>& hFences, vector<int>& vFences) {
        const long long MOD = 1e9 + 7;

        vector<long long> H, V;
        H.push_back(1);
        H.push_back(m);
        V.push_back(1);
        V.push_back(n);

        for (int x : hFences) H.push_back(x);
        for (int x : vFences) V.push_back(x);

        sort(H.begin(), H.end());
        sort(V.begin(), V.end());

        unordered_set<long long> vDiffs;
        for (int i = 0; i < (int)V.size(); i++) {
            for (int j = i + 1; j < (int)V.size(); j++) {
                vDiffs.insert(V[j] - V[i]);
            }
        }

        long long best = 0;
        for (int i = 0; i < (int)H.size(); i++) {
            for (int j = i + 1; j < (int)H.size(); j++) {
                long long d = H[j] - H[i];
                if (vDiffs.count(d)) {
                    best = max(best, d);
                }
            }
        }

        if (best == 0) return -1;
        return (int)((best % MOD) * (best % MOD) % MOD);
    }
};
