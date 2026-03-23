#include <iostream>
#define MAX 5005

using namespace std;

long long n, k, x , y, mod, ans;
int a[MAX][MAX], s[MAX][MAX];

void prep() {
	for (int i = 1;  i <= n; i++) {
		s[i][1] = a[i][1] + s[i - 1][1];
		for (int j = 2; j <= n; j++) {
			s[i][j] = a[i][j] + s[i][j - 1] + s[i - 1][j] - s[i-1][j-1];
		}
	}
}

bool f(long long m) {
	for (int i = m; i <= n; i++) {
		for (int j = m; j <= n; j++) {
			if (s[i][j] + s[i - m][j - m] - s[i - m][j] - s[i][j - m] < k) return false;
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> a[i][1];
		cin >> x >> y >> mod;
		for (int j = 2; j <= n; j++) {
			a[i][j] = (a[i][j - 1] * x + y) % mod;
		}
	}
	
	prep();

	long long l = 1;
	long long r = n;

	while (l <= r) {
		long long mid = l + (r - l) / 2;
		if (f(mid)) {
			r = mid - 1;
			ans = mid;
		}
		else {
			l = mid + 1;
		}
	}

	cout << l << endl;
	return 0;
}
