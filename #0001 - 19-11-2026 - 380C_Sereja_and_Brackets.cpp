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

struct Node {
    int ma, op, cl;

    Node(int _ma = 0, int _op = 0, int _cl = 0) {
        ma = _ma, op = _op; cl = _cl;
    }
};

struct SegmentTree {
    vector <Node> tree;
    int n;

    SegmentTree(int _n = 0) {
        n = _n;
        tree.resize(4 * n + 5);
    }

    Node Merge(const Node &l, const Node &r) {
        Node res;
        int t = min(l.op, r.cl);
        res.ma = l.ma + r.ma + 2 * t;
        res.op = l.op + r.op - t;
        res.cl = l.cl + r.cl - t;
        return res;
    }

    void build(int id, int l, int r, const string &s) {
        if (l == r) {
            if (s[l] == '(') return void(tree[id] = Node(0, 1, 0));
            else return void(tree[id] = Node(0, 0, 1));
        } int mid = (l + r) >> 1;
        build(id << 1, l, mid, s);
        build(id << 1 | 1, mid + 1, r, s);
        tree[id] = Merge(tree[id << 1], tree[id << 1 | 1]);
    }

    Node get(int id, int l, int r, int u, int v) {
        if (v < l || r < u) return Node();
        if (u <= l && r <= v) return tree[id];
        int mid = (l + r) >> 1;
        return Merge(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
    }
};

void solve() {
    string s; cin >> s;
    int n = s.size();
    s = ' ' + s;
    SegmentTree st(n);
    st.build(1, 1, n, s);
    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        cout << st.get(1, 1, n, l, r).ma << el;
    }
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
