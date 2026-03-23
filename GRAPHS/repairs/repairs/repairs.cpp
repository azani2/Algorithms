#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 10010

int n, m, par[MAX], depth[MAX], a, b, d, ans, cnt;

struct edge{
    int a, b, d;
    bool operator<(const edge& other) {
        return d < other.d;
    }
};
vector<edge> edges;

int find(int x) {
    if (par[x] == 0) return x;
    return par[x] = find(par[x]);
}

void uni(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (depth[x] < depth[y]) {
        par[x] = y;
    }
    else {
        par[y] = x;
        if (depth[x] == depth[y]) depth[x]++;
    }
}

void Kruskal() {
    sort(edges.begin(), edges.end());
    for (int i = 0; i < m; i++) {
        if (find(edges[i].a) != find(edges[i].b)) {
            uni(edges[i].a, edges[i].b);
            cnt++;
        }
        else {
            ans += edges[i].d;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> d;
        edges.push_back({ a, b, d });
    }

    Kruskal();

    if (cnt != n - 1) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}