#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

#define MAXQ 500005

int q, type, x, n;
vector<long> v;
vector<long double> res;

long double calcMax(long k) {
	if (!k) return 0.0;

	long double maxValue = 0.0;
	long biggestIdx = n - 1;
	long double s = (k >= 2 ? v[k - 2] : 0);
	while (biggestIdx >= 0 && biggestIdx >= k-1) {
		long double biggest = (biggestIdx > 0 ? 
			v[biggestIdx] - v[biggestIdx - 1] :
			v[biggestIdx]);
		long double val = biggest - (long double)(biggest + s) * (1.0 / k);
		maxValue = max(val, maxValue);
		biggestIdx--;
	}
	return maxValue;
}

void solve() {
	long double ans = 0.0;
	long l = 1, r = n;
	while (l <= r) {
		long m1 = l + (r - l) / 3;
		long m2 = r - (r - l) / 3;
		long double f1 = calcMax(m1);
		long double f2 = calcMax(m2);
		if (f1 > f2) {
			r = m2 - 1;
			ans = max(ans, f1);
		}
		else {
			l = m1 + 1; 
			ans = max(ans, f2);
		}
	}
	res.push_back(ans);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> q;
	for (int i = 0; i < q; i++) 
	{
		cin >> type;
		if (type == 1) {
			cin >> x;
			if (!v.empty()) x += v[v.size() - 1];
			v.push_back(x);
			n = v.size();
		}
		else {
			solve();
		}
	}
	for (int i = 0; i < res.size(); i++) 
		cout <<fixed << setprecision(11) << res[i] << endl;
	
	return 0;
}

/*

6
1 3
2
1 4
2
1 8
2
---
.:
0.0000000000
0.5000000000
3.0000000000

4
1 1
1 4
1 5
2
---
.:
2.0000000000
*/

