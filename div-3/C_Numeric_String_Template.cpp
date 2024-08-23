#include <bits/stdc++.h>
using namespace std;
constexpr int64_t inf = (int64_t)1e+18;
constexpr int mod = 1000000007;

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
#endif

// @author: ZhockDen

void runCase(int &testCase) {
    // cout << "#Case " << testCase << ": \n";

    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &e : v) cin >> e;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (s.size() != n) {
            cout << "NO\n";
            continue;
        }
        map<int, char> mp;
        map<char, int> mp1;
        for (int j = 0; j < n; j++) {
            if (mp.count(v[j]) == 0) mp[v[j]] = s[j];
            if (mp1.count(s[j]) == 0) mp1[s[j]] = v[j];
        }
        bool flag = false;
        for (int j = 0; j < n; j++) {
            if (mp[v[j]] != s[j]) {
                cout << "NO\n";
                flag = true;
                break;
            }
            if (mp1[s[j]] != v[j]) {
                cout << "NO\n";
                flag = true;
                break;
            }
        }
        if (flag) continue;
        cout << "YES\n";
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int tests = 1;
    cin >> tests;
    for (int i = 1; i <= tests; i++) runCase(i);

    return 0;
}