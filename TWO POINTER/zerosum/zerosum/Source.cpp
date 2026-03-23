#include <iostream>
#include <algorithm>
using namespace std;

const long MAXN = 10005;

long n, a[MAXN], ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);

	for (int i = 0; i < n; i++) {
		long l = i + 1;
		long r = n - 1;
		long s = -a[i];
		while (l < r) {
			if (a[l] + a[r] < s) {
				l++;
			}
			else if (a[l] + a[r] > s) {
				r--;
			}
			else {
				if (a[l] == a[r]) {
					long c = r - l + 1;
					long combs = c * (c - 1L) / 2;
					ans += combs;
					break;
				}
				long lc = 1;
				while (l < r && a[l] == a[l + 1]) {
					lc++;
					l++;
				}
				long rc = 1;
				while (r > l && a[r] == a[r - 1]) {
					rc++;
					r--;
				}
				ans += lc * rc;
				l++;
				r--;
			}
		}
	}

	cout << ans << endl;
	return 0;
}