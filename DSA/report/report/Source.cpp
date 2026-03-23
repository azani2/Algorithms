#include <iostream>
#include <vector>
using namespace std;

int n;
long long p;
vector<pair<long long, int>> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	cin >> p;
	v.push_back({ 0,0 });
	v.push_back({ p,0 });

	for (int i = 1; i < n; i++) {
		cin >> p;
		if (p > v[v.size() - 1].first) {
			v.push_back({ p,i });
		}
		else {
			int j = v[v.size() - 1].second;
			while (p <= v[j].first) {
				j = v[j].second;
			}
			v.push_back({ p,j });
		}
	}

	for (int i = 1; i <= n; i++) cout << v[i].second << " ";
	
}