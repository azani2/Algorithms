#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;
#define MAX 101000

int n, m, f, t, s, par[MAX], d[MAX], cnt;
int ans = INT_MAX;
int l, r;

struct edge {
	int a, b, s;
	bool operator<(const edge& other) {
		return s < other.s;
	}
};
vector<edge> edges;

int find(int a)
{
	if (par[a] == -1) return a;
	return par[a] = find(par[a]);
}

void uni(int a, int b)
{
	cnt++;
	a = find(a);
	b = find(b);
	if (d[a] > d[b])
	{
		par[b] = a;
	}
	else
	{
		par[a] = b;
		if (d[a] == d[b])d[b]++;
	}
	return;
}

//we want the difference between edge weights to be minimal
//there are exactly m - n 
void BuildTree(int i) {
	fill(par, par + n + 2, -1);
	fill(d, d + n + 2, 0);
	cnt = 0;
	for (int j = i; j < m; j++) {
		if (find(edges[j].a) != find(edges[j].b))
			uni(edges[j].a, edges[j].b);

		if (cnt == n - 1) {
			if (ans > edges[j].s - edges[i].s) {
				ans = edges[j].s - edges[i].s;
				l = edges[i].s;
				r = edges[j].s;
			}
			break;
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
        cin >> f >> t >> s;
		edges.push_back(edge{ f, t, s });
    }

	sort(edges.begin(), edges.end());
	for (int i = 0; i < m; i++) {
		BuildTree(i);
	}

	cout << l << " " << r << endl;
	return 0;
}