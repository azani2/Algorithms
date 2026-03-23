#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1010
int n, m, par[MAX], d[MAX], k;

struct edge {
    int a, b, w;
    bool operator<(const edge& other) {
        return w > other.w;
    }
};

vector<edge> edges;
vector<int> ans;
vector<pair<int, int>> queries;

int find(int x) {
    if (par[x] == -1) return x;
    return par[x] = find(par[x]);
}

void uni(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (d[x] < d[y]) {
        par[x] = y;
    }
    else {
        par[y] = x;
        if (d[x] == d[y]) d[x]++;
    }
}

void Kruskal() {
    sort(edges.begin(), edges.end());
    
    for (int i = 0; i < m; i++) {
        if (find(edges[i].a) == find(edges[i].b)) continue;
        uni(edges[i].a, edges[i].b);
        for (int j = 0; j < k; j++) {
            if (ans[j] == -1 && find(queries[j].first) == find(queries[j].second)) {
                ans[j] = edges[i].w;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    int a, b, w;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        edges.push_back({ a, b, w });
    }

    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        queries.push_back({ a, b });
        ans.push_back(-1);
    }
    fill(par, par + n + 2, -1);
    Kruskal();

    for (int i = 0; i < k; i++) cout << ans[i] << endl;
    return 0;
}