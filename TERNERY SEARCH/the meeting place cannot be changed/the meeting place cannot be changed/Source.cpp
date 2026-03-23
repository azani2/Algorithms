#include <iomanip>
#include <math.h>
#include <iostream>
using namespace std;

#define MAXN 60005

int n;
double l = INT_MAX, r, m1, m2, t1, t2;
long x[MAXN], v[MAXN];

double calc(double p) {
	long double maxT = 0.0;
	for (int i = 0; i < n; i++) {
		long double t = abs(x[i] - p) * (1.0 / v[i]);
		maxT = max(maxT, t);
	}
	return maxT;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i];
	for (int i = 0; i < n; i++) cin >> v[i];
	for (int i = 0; i < n; i++) {
		r = max(r, (double)(x[i]));
		l = min(l, (double)(x[i]));
	}
	
	for (int i = 0; i < 100; i++) {
		m1 = l + (r - l) * (1.0 / 3);
		m2 = l + (r - l) * (2.0 / 3);
		t1 = calc(m1);
		t2 = calc(m2);
		if (t1 < t2) r = m2;
		else l = m1;
	}

	cout << fixed << setprecision(9) << t1 << endl;
	return 0;
}