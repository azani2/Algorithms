#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 110000

int n, m, x, y, p;
int current, ans[MAX];

struct point {
	int x, type, idx;

	bool operator<(const point& other) {
		if (x != other.x) {
			return x < other.x;
		}
		return type > other.type;
	}
};

vector<point> v;


int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		if (x > y) swap(x, y);
		v.push_back(point{ x, 1, 0 });
		v.push_back(point{ y, -1, 0 });
	}

	for (int i = 0; i < m; i++)
	{
		cin >> p;
		v.push_back(point{ p , 0, i });
	}

	sort(v.begin(), v.end());

	for (point pt : v) {
		current += pt.type;
		if (pt.type == 0) ans[pt.idx] = current;
	}

	for (int i = 0; i < m; i++) cout << ans[i] << " ";
	cout << endl;
}
