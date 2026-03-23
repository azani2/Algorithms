#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define MAXN 3005

struct passenger {
	int t, type, natID;

	bool operator<(const passenger& other) {
		if (t != other.t) return t < other.t;
		return type > other.type;
	}
};

int n, a, b, c, ans;
vector<passenger> v;
int currNat[MAXN];
int maxNats[MAXN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		v.push_back(passenger{ a, 1, c});
		v.push_back(passenger{ b, 0, c});
	}

	sort(v.begin(), v.end());

	for (passenger p : v)
	{
		currNat[p.natID] += p.type;
		maxNats[p.natID] = max(currNat[p.natID], maxNats[p.natID]);
		if (p.type == 0) currNat[p.natID]--;
	}
	
	ans = maxNats[0];
	for (int i = 1; i < MAXN; i++) {
		ans = max(ans, maxNats[i]);
	}

	cout << ans;
}
