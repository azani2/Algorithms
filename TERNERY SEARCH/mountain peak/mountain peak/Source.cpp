#include <iomanip>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 100005

long n, arr[MAXN], lo = 1, hi, m1, m2, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (long i = 1; i <= n; i++) cin >> arr[i];

	hi = n;

	while (lo + 2 < hi) {
		m1 = lo + (hi - lo) / 3;
		m2 = hi - (hi - lo) / 3;

		if (arr[m1] < arr[m2])
		{
			lo = m1;
		}
		else {
			hi = m2;
		}
	}

	ans = lo;
	for (long i = lo + 1; i <= hi; i++) 
		if (arr[i] > arr[ans]) ans = i; 

	cout << "[" << ans << "] = " << arr[ans] << endl;
	return 0;
}