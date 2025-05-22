class Solution {
public:
    typedef long long ll;

const int BASE1 = 31, BASE2 = 37;
const int MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;
const int WINDOW = 10;

// Compute powers of base modulo mod
vector<ll> computePower(int base, int mod, int n) {
    vector<ll> p(n + 1, 1);
    for (int i = 1; i <= n; ++i)
        p[i] = (p[i - 1] * base) % mod;
    return p;
}

// Compute prefix hashes
vector<ll> computeHash(const string& s, int base, int mod) {
    int n = s.size();
    vector<ll> h(n + 1, 0);
    for (int i = 0; i < n; ++i)
        h[i + 1] = (h[i] * base + (s[i] - 'A' + 1)) % mod;
    return h;
}

// Substring hash from l to r-1
ll subHash(int l, int r, const vector<ll>& h, const vector<ll>& p, int mod) {
    return (h[r] - h[l] * p[r - l] % mod + mod) % mod;
}

vector<string> findRepeatedDnaSequences(string s) {
    int n = s.length();
    if (n < WINDOW) return {};

    // Precompute powers
    vector<ll> p1 = computePower(BASE1, MOD1, n);
    vector<ll> p2 = computePower(BASE2, MOD2, n);

    // Precompute hashes
    vector<ll> h1 = computeHash(s, BASE1, MOD1);
    vector<ll> h2 = computeHash(s, BASE2, MOD2);

    // Store seen and repeated pairs of hashes
    unordered_set<ll> seen, repeated;
    vector<string> result;

    for (int i = 0; i <= n - WINDOW; ++i) {
        ll hashA = subHash(i, i + WINDOW, h1, p1, MOD1);
        ll hashB = subHash(i, i + WINDOW, h2, p2, MOD2);
        
        // Combine the two hashes into a single 64-bit integer
        ll combined = (hashA << 32) | hashB;

        if (seen.count(combined)) {
            if (!repeated.count(combined)) {
                result.push_back(s.substr(i, WINDOW));
                repeated.insert(combined);
            }
        } else {
            seen.insert(combined);
        }
    }

    return result;
}


};