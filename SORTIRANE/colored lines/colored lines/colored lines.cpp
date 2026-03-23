#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, x, y, cnt, maxlen, current, bgn;

struct cline {
	int a, type;

	bool operator<(const cline& other) {
		if (a != other.a) return a < other.a;
		return type > other.type;
	}
};

vector<cline> v;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back(cline{ x, 1 });
		v.push_back(cline{ y, -1 });
	}

	sort(v.begin(), v.end());

	for (cline l : v)
	{
		current += l.type;
		if (l.type == 1 && current == 1)
		{
			cnt++;
			bgn = l.a;
		}
		if (current == 0)
		{
			maxlen = max(maxlen, l.a - bgn);
		}
	}
	cout << cnt << " " << maxlen << endl;
	
}
