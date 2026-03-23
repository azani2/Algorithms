#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 1e4 + 5;

vector <int> g[MAXN];
int doBefore[MAXN];
vector <int> ans;

int n, m;

/*

Topological sorting for DAG is 
a linear ordering of vertices such that 

for every directed edge u->v, vertex u comes before v in the ordering.

*/

int main() {

    cin >> n >> m;
    int i, j, u, v;
    for (i = 1; i <= m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        doBefore[v]++;
    }

    priority_queue <int> pq;
    for (i = 1; i <= n; i++) {
        if (doBefore[i] == 0) pq.push(-i);
    }

    while (!pq.empty()) {
        int curr = -pq.top();
        pq.pop();
        ans.push_back(curr);
        for (int u : g[curr]) {
            doBefore[u]--;
            if (doBefore[u] == 0) pq.push(-u);
        }
    }

    if (ans.size() == n) {
        for (int v : ans) cout << v << " ";
        cout << endl;
    }
    else {
        cout << "Sandro fails.\n";
    }

}