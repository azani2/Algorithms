#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 100

int n, k, c[MAXN], q;
long ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}

	sort(c + 1, c + n + 1, [](int a, int b) {return b < a; });
	for (int i = 1; i <= n; i++) {
		if (i % k == 1) q++;
		ans += q * c[i];
	}
		
	cout << ans << endl;
	return 0;
}