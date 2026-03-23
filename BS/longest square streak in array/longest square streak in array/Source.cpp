#include <iomanip>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 100005

int n, a[MAXN], c, maxLen;
bool taken[MAXN];

void take(int idx, int& currLen) {
	taken[idx] = true;
	currLen++;
	c++;
	int target = a[idx] * a[idx];
	int l = idx +1, r = n - 1;

	while (l <= r) {
		int mid = (l + r) / 2;
		if (a[mid] > target) r = mid - 1;
		else if (a[mid] < target) l = mid + 1;
		else {
			take(mid, currLen);
			break;
		}
	}

	maxLen = max(maxLen, currLen);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);

	for (int i = 0; i < n; i++) {
		if (c == n) break;
		if (taken[i]) continue;
		int currLen = 0;
		take(i, currLen);
	}

	cout << (maxLen >= 2 ? maxLen : -1 )<< endl;
	return 0;
}