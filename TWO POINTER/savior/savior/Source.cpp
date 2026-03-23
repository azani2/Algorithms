#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;

double x1, x2, y, y2, v1, v2;
int t;

double time(double x)
{
	return sqrt(y * y + (x1 - x) * (x1 - x)) * (1.0 / v1) +
		sqrt(y2 * y2 + (x2 - x) * (x2 - x)) * (1.0 / v2);
}

void solve() {
	cin >> x1 >> y >> x2 >> y2 >> v1 >> v2;

	double l, r, m1, m2, c1, c2;
	l = min(x1, x2);
	r = max(x1, x2);

	for (int i = 0; i < 100; i++) //ternary search
	{
		m1 = l + (1.0 / 3) * (r - l);
		m2 = l + (2.0 / 3) * (r - l);

		c1 = time(m1);
		c2 = time(m2);

		if (c1 > c2)
		{
			l = m1;
		}
		else
		{
			r = m2;
		}
	}
	cout << fixed << setprecision(5) << time(l) << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	for (int i = 0; i < t; i++) solve();

	cout << endl;
	return 0;
}