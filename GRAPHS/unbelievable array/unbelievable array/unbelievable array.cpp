#include <iostream>
#include <queue>
using namespace std;

#define MAX 100100

int n, m, q, t, x, y, a[MAX], par[MAX], d[MAX], repres[MAX], toBecome, was, br;
queue<pair<int, int>> ans;

int find(int a)
{
	if (par[a] == -1)return a;
	return par[a] = find(par[a]);
}

void uni(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b)return;
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

void solve(int idx) {
	fill(par, par + MAX, -1);
	fill(d, d + MAX, 0);
	fill(repres, repres + MAX, 0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (repres[a[i]] == 0) repres[a[i]] = i;
		uni(repres[a[i]], i);
	}

	br = n + 1;
	for (int i = 0; i < m; i++) {

		cin >> t;
		if (t == 1) {
			cin >> x >> y;
			was = x;

			if (repres[x] == 0) continue;

			x = repres[x];
			repres[was] = 0;
			if (repres[y] == 0) repres[y] == br++;

			toBecome = y;
			y = repres[y];
			uni(x, y);
			a[find(x)] = toBecome;
		}
		else {
			cin >> x;
			ans.push({ idx, a[find(x)] });
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> q;
	for (int i = 1; i <= q; i++) solve(i);

	q = 0;
	while (!ans.empty()) {
		if (ans.front().first != q) {
			q = ans.front().first;
			cout << "Case " << q << ":\n";
		}
		cout << ans.front().second << endl;
		ans.pop();
	}

	return 0;
}