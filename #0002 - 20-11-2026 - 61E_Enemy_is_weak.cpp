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

const int MAX = 1001001;
int n; int a[MAX], f[MAX];

struct SegmentTree {
    vector <int> tree;
    int n;

    SegmentTree(int _n = 0) {
        n = _n;
        tree.resize(4 * n + 5);
    }

    void update(int id, int l, int r, int pos, int val) {
        if (l == r) return void(tree[id] += val);
        int mid = (l + r) >> 1;
        if (pos <= mid) update(id << 1, l, mid, pos, val);
        else update(id << 1 | 1, mid + 1, r, pos, val);
        tree[id] = tree[id << 1] + tree[id << 1 | 1];
    }

    int get(int id, int l, int r, int u, int v) {
        if (v < l || r < u) return 0;
        if (u <= l && r <= v) return tree[id];
        int mid = (l + r) >> 1;
        int r1 = get(id << 1, l, mid, u, v);
        int r2 = get(id << 1 | 1, mid + 1, r, u, v);
        return r1 + r2;
    }
};

void solve() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i], f[i] = a[i];
    sort(f + 1, f + n + 1);
    FOR(i, 1, n) a[i] = lower_bound(f + 1, f + n + 1, a[i]) - f;
    SegmentTree st(n);
    int res = 0;
    FOR(j, 1, n) {
        int t = st.get(1, 1, n, 1, a[j] - 1);
        int L = (j - 1) - t;
        int R = (a[j] - 1) - t;
        res += L * R;
        st.update(1, 1, n, a[j], 1);
    } cout << res << el;
}

signed __Road_To_VOI_Season2027__ {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    } int o = 1; // cin >> o;
    while (o --> 0) solve();
    cerr << "Time elapsed: " << TIME << "s\n";
    return 0;
}

/* -------------------- THE END OF CODE --------------------
May your algorithms be correct, your code bug-free,
and your efforts rewarded. Best of luck in VOI and
the national team selection exam!
---------------------------------------------------------- */
