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

const int oo = 1e18;
const int MAX = 1010;
int n, m, k, comp; string grid[MAX];
int dist[MAX][MAX], compID[MAX][MAX], visStar[MAX][MAX], res[MAX * MAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int x, int y) {
    comp++;
    queue <pii> q; q.push({x, y});
    dist[x][y] = 0; compID[x][y] = comp;
    while (q.size()) {
        int u = q.front().fi, v = q.front().se; q.pop();
        REP(i, 4) {
            int nu = u + dx[i], nv = v + dy[i];
            if (nu < 1 || nu > n || nv < 1 || nv > m) continue;
            if (grid[nu][nv] == '*') { res[comp]++; continue; }
            if (dist[nu][nv] == oo) {
                dist[nu][nv] = dist[u][v] + 1;
                compID[nu][nv] = comp;
                q.push({nu, nv});
            }
        }
    }
}

void solve() {
    cin >> n >> m >> k;
    FOR(i, 1, n) cin >> grid[i], grid[i] = ' ' + grid[i];
    FOR(i, 1, n) FOR(j, 1, m) dist[i][j] = oo;
    FOR(i, 1, n) FOR(j, 1, m) {
        if (grid[i][j] == '.' && dist[i][j] == oo)
            bfs(i, j);
    } while (k--) {
        int x, y; cin >> x >> y;
        cout << res[compID[x][y]] << el;
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
