#include <iostream>
using namespace std;

long long a, b;
long long k, m;
long long x;
long long d;

long long tiles(long long d) {
	long long breaks1 = d / k;
	long long breaks2 = d / m;
	return (d - breaks1) * a + (d - breaks2) * b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> a >> k >> b >> m >> x;

	long long l = 1;
	long long r = 2 * x / (a + b) + 1;

	while (l < r) {
		d = l + (r - l) / 2;
		long long t = tiles(d);
		if (t >= x) r = d;
		else l = d + 1;
	}

	cout << l;
}