#include <iostream>

using namespace std;
#define MAX 11000

int n, m, t, a, b, q, depth[MAX], parent[MAX];

int find(int v) {
	if (parent[v] == 0) return v;
	return parent[v] = find(parent[v]);
}

void uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	if (depth[a] > depth[b]) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
		if (depth[a] == depth[b]) depth[b]++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		uni(a, b);
	}

	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> t >> a >> b;

		if (t==2) {
			uni(a, b);
		}
		else if (t==1){
			cout << (find(a) == find(b));
		}
	}
	cout << endl;
	return 0;
}