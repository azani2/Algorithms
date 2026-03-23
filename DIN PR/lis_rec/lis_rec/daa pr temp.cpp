#include <iostream>
#define MAX 10010
using namespace std;
int n, a[MAX], d[MAX];

int calc(int i) {
	if (d[i] > 0) return d[i];
	int ans = 1;
	for (int j = i + 1; j <= n; j++) {
		if (a[i] < a[j])
			ans = max(ans, 1 + calc(j));
	}
	return d[i] = ans;
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];

	int ans = 0;
	for (int i = 1; i <= n; i++) ans = max(ans, calc(i));
	cout << ans << endl;

	return 0;
}
