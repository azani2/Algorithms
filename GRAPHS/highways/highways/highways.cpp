#include <iostream>
#include <vector>
using namespace std;
#define MAX 50005

int n, m, v, w, d, par[MAX], sz[MAX], ans;
vector<pair<int, int>> hard;
bool used[MAX];

int find(int a) {
	if (par[a] == 0)return a;
	return par[a] = find(par[a]);
}

void uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (sz[a] < sz[b])
	{
		sz[b] += sz[a];
		par[a] = b;
	}
	else
	{
		sz[a] += sz[b];
		par[b] = a;
	}
	return;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> v >> w >> d;
		if (d == 0) uni(v, w);
		else hard.push_back({ v, w });
			
    }

	for (int i = 0; i < hard.size(); i++) {
		if (find(hard[i].first) != find(hard[i].second)) {
			uni(hard[i].first, hard[i].second);
			ans++;
		}
	}

	cout << ans << endl;
	return 0;
}
