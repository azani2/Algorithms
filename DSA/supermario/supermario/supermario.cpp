#include <iostream>
#include <algorithm>
#include <deque>
#include <math.h>
using namespace std;
#define MAX 10100000
#define PA pair<long long, long long>

long long n, k,f,a, b, m, sum, p, acc;

deque<PA> d;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k >> f >> a >> b >> m;

	d.push_back({ 0,0 });

	d.push_back({ f,1 });
	p = f;

	for (int i = 2; i <= n; i++) {

		p = (p * a + b) % m;

		while (i - d.front().second > k)
			d.pop_front();

		acc = p + d.front().first;

		while (!d.empty() && d.back().first >= acc)
			d.pop_back();

		d.push_back({ acc, i });
	}

	while (n + 1 - d.front().second > k)
		d.pop_front();

	cout << d.front().first << endl;
}