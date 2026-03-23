#include <iomanip>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 10005

int l, g, w[4], s[4];

double ternery(int idx, double y) {
	if (idx == 3) return (l - y) / g;

	double lo = y, hi = l, m1, m2, t1, t2;

	for (int i = 0; i < 100; i++) {
		m1 = lo + (1.0 / 3) * (hi - lo);
		m2 = lo + (2.0 / 3) * (hi - lo);

		t1 = ternery(idx + 1, m1) + sqrt((m1 - y) * (m1 - y) + w[idx] * w[idx]) / s[idx];
		t2 = ternery(idx + 1, m2) + sqrt((m2 - y) * (m2 - y) + w[idx] * w[idx]) / s[idx];
		 
		if (t1 < t2) {
			hi = m2;
		}
		else {
			lo = m1;
		}
	}

	return ternery(idx + 1, lo) + sqrt((lo - y) * (lo - y) + w[idx] * w[idx]) / s[idx];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> l >> g;
	for (int i = 0; i < 3; i++) cin >> w[i] >> s[i];

	cout << setprecision(15) << ternery(0, 0) << endl;
	return 0;
}