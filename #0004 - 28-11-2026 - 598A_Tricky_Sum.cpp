#include <bits/stdc++.h>

using namespace std;

#define NAME "practice"
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define EXIT(x) cerr << "Time elapsed: " << TIME << "s\n"; return x
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for(int i = (b), _a = (a); i >= _a; i--)
#define FORE(i, v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define REP(i, n) for(int i = 0, _n = (n); i < _n; i++)
#define ALL(v) (v).begin(), (v).end()
#define COMPACT(v) sort(ALL(v)), v.erase(unique(ALL(v)), v.end())
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define el '\n'
#define fi first
#define se second
#define int long long
#define __Road_To_VOI_Season2027__ main(void)
#define pii pair<int, int>

void debug_out(void) { cerr << "]" << el; }
template<typename Head, typename... Tail>
    void debug_out(Head H, Tail... T) {
        cerr << H;
        if (sizeof...(T)) cerr << ", ";
        debug_out(T...);
    }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] = [", debug_out(__VA_ARGS__)

template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        if (x > y) {
            x = y; return true;
        } else return false;
    }

template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        if (x < y) {
            x = y; return true;
        } else return false;
    }

template <class T>
    T abs(const T &x) {
        return (x < 0 ? -x : x);
    }

// -------------------- END OF TEMPLATE --------------------

void solve() {
    int n; cin >> n;
    int s = (n * (n + 1)) / 2;
    int pw = 1;
    while (pw <= n)
        s -= pw * 2, pw *= 2;
    cout << s << el;
}

signed __Road_To_VOI_Season2027__ {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    } int o = 1; cin >> o;
    while (o --> 0) solve();
    cerr << "Time elapsed: " << TIME << "s\n";
    return 0;
}

/* -------------------- THE END OF CODE --------------------
May your algorithms be correct, your code bug-free,
and your efforts rewarded. Best of luck in VOI and
the national team selection exam!
---------------------------------------------------------- */
