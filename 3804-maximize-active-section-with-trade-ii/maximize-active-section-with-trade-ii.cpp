#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    struct SparseTable {
        vector<vector<int>> st;
        vector<int> lg;
        void build(const vector<int>& arr) {
            int n = arr.size();
            if (n == 0) return;
            lg.assign(n + 1, 0);
            for (int i = 2; i <= n; i++) {
                lg[i] = lg[i/2] + 1;
            }
            int K = lg[n] + 1;
            st.assign(n, vector<int>(K));
            for (int i = 0; i < n; i++) {
                st[i][0] = arr[i];
            }
            for (int j = 1; j < K; j++) {
                for (int i = 0; i + (1 << j) <= n; i++) {
                    st[i][j] = max(st[i][j-1], st[i + (1 << (j-1))][j-1]);
                }
            }
        }
        int query(int L, int R) {
            if (L > R) return 0;
            int j = lg[R - L + 1];
            return max(st[L][j], st[R - (1 << j) + 1][j]);
        }
    };

public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int total_ones = 0;
        for (char c : s) {
            if (c == '1') total_ones++;
        }

        vector<pair<int, int>> P;
        for (int i = 0; i < n; ) {
            if (s[i] == '0') {
                int j = i;
                while (j < n && s[j] == '0') {
                    j++;
                }
                P.push_back({i, j - 1});
                i = j;
            } else {
                i++;
            }
        }

        int M = P.size();
        vector<int> L_coords(M), R_coords(M);
        vector<int> len(M);
        for (int i = 0; i < M; i++) {
            L_coords[i] = P[i].first;
            R_coords[i] = P[i].second;
            len[i] = P[i].second - P[i].first + 1;
        }

        vector<int> D;
        if (M >= 2) {
            D.resize(M - 1);
            for (int i = 0; i < M - 1; i++) {
                D[i] = len[i] + len[i+1];
            }
        }

        SparseTable rmq;
        rmq.build(D);

        vector<int> ans(queries.size());
        for (int q = 0; q < queries.size(); q++) {
            int l = queries[q][0];
            int r = queries[q][1];

            int a = lower_bound(R_coords.begin(), R_coords.end(), l) - R_coords.begin();
            int b = upper_bound(L_coords.begin(), L_coords.end(), r) - L_coords.begin() - 1;

            if (b < a) {
                ans[q] = total_ones;
                continue;
            }

            int m = b - a + 1;
            if (m < 2) {
                ans[q] = total_ones;
            } else {
                int len_1 = P[a].second - max(P[a].first, l) + 1;
                int len_m = min(P[b].second, r) - P[b].first + 1;

                if (m == 2) {
                    ans[q] = total_ones + len_1 + len_m;
                } else {
                    int cand1 = len_1 + len[a+1];
                    int cand2 = len[b-1] + len_m;
                    int max_cand = max(cand1, cand2);
                    if (b - a >= 3) {
                        int internal_max = rmq.query(a + 1, b - 2);
                        max_cand = max(max_cand, internal_max);
                    }
                    ans[q] = total_ones + max_cand;
                }
            }
        }

        return ans;
    }
};
