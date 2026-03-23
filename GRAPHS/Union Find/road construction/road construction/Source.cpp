#include <iostream>
#include <queue>
#define MAX 100100
using namespace std;

int n, m, q, d[MAX], par[MAX], sz[MAX], a, b, t, compcnt, mx;
//find sa  korenite na durvetata
// sz e broq vurhove vuv vsqko durvo
// d e visochinata na vsqko durvo
// par za vseki vruh sudurja roditelq mu ili korena na durvoto mu (Ako e vikana find vurhu tozi vruh)
// mx e razmera na nai golqmoto durvo

queue<pair<int, int>> ans;
int find(int a)
{
	if (par[a] == -1) return a;
	return par[a] = find(par[a]);
}

void uni(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) return;
	compcnt--;

	if (d[a] > d[b]) { // Ta e po dulboko i si ostava s dulbochina d[a]
		par[b] = a;
		sz[a] += sz[b];
		mx = max(mx, sz[a]);
	} 
	else if (d[a] > d[b]) {
		par[a] = b;
		sz[b] += sz[a];
		mx = max(mx, sz[b]);
	}
	else {
		par[a] = b;
		d[b]++;
		sz[b] += sz[a];
		mx = max(mx, sz[b]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	fill(par, par + n + 1, -1);
	fill(sz, sz + n + 1, 1);
	mx = 1;
	compcnt = n;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		uni(a, b);
		ans.push({ compcnt,mx });
	}

	while (!ans.empty()) {
		int c = ans.front().first;
		int m = ans.front().second;
		cout << c << " " << m << endl;
		ans.pop();
	}
}