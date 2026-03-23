#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
#define MAX 1024

vector<pair<int, int>> wg[MAX];
bool used[MAX];
int d[MAX];
priority_queue<pair<int, int>> pq;

int n, m, a, b, c, start;

void dijkstra(int from) {
    fill(d, d + n + 1, INT_MAX / 2);
    d[from] = 0;
    pq.push({ d[from], from });
    
    while (!pq.empty()) {
        int x = pq.top().second;
        pq.pop();

        if (used[x]) continue;
        used[x] = 1;

        for (auto p : wg[x]) {
            int y = p.first;
            int w = p.second;
            if (d[y] > d[x] + w) {
                d[y] = d[x] + w;
                pq.push({ -d[y], y });
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        wg[a].push_back({ b, c });
        wg[b].push_back({ a, c });
    }

    cin >> start;
    dijkstra(start);
    for (int i = 0; i < n; i++) cout << d[i] << " ";
    cout << endl;

    return 0;
}