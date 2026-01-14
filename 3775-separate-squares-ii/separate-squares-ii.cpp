#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Event {
        long long y;
        int type;
        int l, r;
    };

    vector<long long> xs;
    vector<int> cnt;
    vector<long long> segLen;

    void pull(int node, int l, int r) {
        if (cnt[node] > 0) {
            segLen[node] = xs[r + 1] - xs[l];
        } else if (l == r) {
            segLen[node] = 0;
        } else {
            segLen[node] = segLen[node * 2] + segLen[node * 2 + 1];
        }
    }

    void update(int node, int l, int r, int ql, int qr, int val) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            cnt[node] += val;
            pull(node, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(node * 2, l, mid, ql, qr, val);
        update(node * 2 + 1, mid + 1, r, ql, qr, val);
        pull(node, l, r);
    }

    double separateSquares(vector<vector<int>>& squares) {
        int n = squares.size();
        vector<Event> events;

        for (auto &s : squares) {
            xs.push_back(s[0]);
            xs.push_back((long long)s[0] + s[2]);
        }

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        auto xid = [&](long long x) {
            return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
        };

        for (auto &s : squares) {
            long long x = s[0], y = s[1], l = s[2];
            int L = xid(x);
            int R = xid(x + l) - 1;
            events.push_back({y, +1, L, R});
            events.push_back({y + l, -1, L, R});
        }

        sort(events.begin(), events.end(), [](auto &a, auto &b) {
            return a.y < b.y;
        });

        int m = xs.size() - 1;
        cnt.assign(4 * m, 0);
        segLen.assign(4 * m, 0);

        // ---------- First sweep: total area ----------
        long long prevY = events[0].y;
        long double totalArea = 0;
        int i = 0;

        while (i < events.size()) {
            long long curY = events[i].y;
            long long dy = curY - prevY;
            if (dy > 0) {
                totalArea += (long double)segLen[1] * dy;
                prevY = curY;
            }
            while (i < events.size() && events[i].y == curY) {
                update(1, 0, m - 1, events[i].l, events[i].r, events[i].type);
                i++;
            }
        }

        long double half = totalArea / 2.0;

        // ---------- Second sweep: find y ----------
        fill(cnt.begin(), cnt.end(), 0);
        fill(segLen.begin(), segLen.end(), 0);

        prevY = events[0].y;
        long double currArea = 0;
        i = 0;

        while (i < events.size()) {
            long long curY = events[i].y;
            long long dy = curY - prevY;

            if (dy > 0 && segLen[1] > 0) {
                long double slab = (long double)segLen[1] * dy;
                if (currArea + slab >= half) {
                    return (double)(prevY + (half - currArea) / segLen[1]);
                }
                currArea += slab;
            }

            prevY = curY; // ✅ CRITICAL FIX

            while (i < events.size() && events[i].y == curY) {
                update(1, 0, m - 1, events[i].l, events[i].r, events[i].type);
                i++;
            }
        }

        return (double)prevY;
    }
};
