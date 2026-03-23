#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 1e5 + 5;

int n, m, c[MAXN];
vector<pair<int, pair<int, int>>> deals;

/*

Type alias, alias template
--------------------------
template<class T>
struct Alloc {};

template<class T>
using Vec = vector<T, Alloc<T>>; // type-id is vector<T, Alloc<T>>

Vec<int> v; // Vec<int> is the same as vector<int, Alloc<int>>

*/

using InvertedPrirityQueue = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
vector<pair<int, pair<int, int>>> productsToDeals[MAXN];

void useProduct(int x, InvertedPrirityQueue& pq) {
	for (auto& deal : productsToDeals[x]) {
		if (c[deal.first] > c[deal.second.first] + c[deal.second.second]) {
			c[deal.first] = c[deal.second.first] + c[deal.second.second];
			pq.push({ c[deal.first], deal.first });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n>> m;
	for (int i = 1; i <= n; i++) cin >> c[i];

	for (int i = 0; i < m; i++) {
		int a, x, y;
		cin >> a >> x >> y;
		deals.push_back({ a, {x, y} });
		productsToDeals[x].push_back(deals.back());
		productsToDeals[y].push_back(deals.back());
	}

	InvertedPrirityQueue pq;
	for (int i = 1; i <= n; i++) pq.push({ c[i], i });

	while (!pq.empty()) {
		pair<int, int> x = pq.top();
		pq.pop();
		if (x.second == 1)break;
		if (x.first != c[x.second])continue;
		useProduct(x.second, pq);
	}

	cout << c[1] << endl;
}