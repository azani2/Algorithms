#include <iostream>
#include <vector>
using namespace std;

#define MAX 500005

int n, m, par[MAX], sz[MAX], d[MAX],s , x, ans;
bool ingroup[MAX];

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
        sz[y] += sz[x];
    }
    else if (d[x] > d[y]) {
        par[y] = x;
        sz[x] += sz[y];
    }
    else {
        par[y] = x;
        sz[x] += sz[y];
        d[x]++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    fill(par, par + n + 1, -1);
    fill(sz, sz + n + 1, 1);

    for(int k = 0;k<m;k++) {
        vector<int> group;
        cin >> s;
        for (int i = 0; i < s; i++) {
            cin >> x;

            if (m == 1) {
                ans++;
                ingroup[x] = 1;
                continue;
            }

            group.push_back(x);
            for (int j = 0; j < group.size() - 1; j++) uni(x, group[j]);
        }
    }

    if (m == 1) {
        for (int i = 1; i <= n; i++) {
            if (ingroup[i]) cout << ans << " ";
            else cout << 1 << " ";
        }
        cout << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++) cout << sz[find(i)] << " ";
    cout << endl;
    return 0;
}