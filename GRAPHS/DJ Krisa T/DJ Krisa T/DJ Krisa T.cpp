#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#define MAX 101000

using namespace std;
int l, r = INT_MAX / 3, mid, ans = -1;
long long n, m, k, a, b, p, t;

struct neighbour{
    long long node, price, t;
};

bool used[MAX];
long long dist[MAX];
vector<neighbour> g[MAX];

using InversedPQ = priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;

long long dijkstra(int s, int f, int maxEdgePrice) {
    InversedPQ pq;
    pq.push({ 0, s });
    dist[s] = 0;

    while (!pq.empty()) {
        int x = pq.top().second;
        pq.pop();
        if (used[x]) continue;
        used[x] = 1;

        for (auto p : g[x]) {
            if (p.price <= maxEdgePrice && dist[p.node] > dist[x] + p.t) {
                dist[p.node] = dist[x] + p.t;
                pq.push({ dist[p.node], p.node });
            }
        }
    }

    return dist[f];
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> p >> t;
        g[a].push_back({ b, p, t });
    }

    while (l <= r) {
        mid = (l + r) / 2;
        fill(dist, dist + n + 2, LLONG_MAX / 123);
        fill(used, used + n + 2, 0);

        if (dijkstra(1, n, mid) <= k) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    cout << ans << endl;
}


/*

7 11 42
1 3 7 11
3 1 7 13
1 2 3 3
1 4 13 1
6 1 14 8
4 6 1 7
2 4 1 13
2 6 4 20
3 5 2 5
5 6 6 4
6 7 5 20

------------
.: 7


2 2 3
1 2 3 5
1 2 1 9

-------
.: -1

*/