#include <iostream>
#include <algorithm>
#define MAX 1000005

using namespace std;

int arr[MAX], a[MAX], b[MAX];
int n, k;

long long merge(int l1, int r1, int l2, int r2)
{
    int i = l1, j = l2, idx = 0;
    long long ans = 0;
    while (i <= r1 && j <= r2)
    {
        if (a[i] >= a[j])
        {
            b[idx] = a[j];
            j++;
            ans += (r1 - i + 1);
        }
        else
        {
            b[idx] = a[i];
            i++;
        }
        idx++;
    }
    for (; i <= r1; i++)
    {
        b[idx] = a[i];
        idx++;
    }
    for (; j <= r2; j++)
    {
        b[idx] = a[j];
        idx++;
    }

    for (int i = l1; i <= r2; i++)a[i] = b[i - l1];
    return ans;
}

long long inversions(int l, int r)
{
    if (l >= r)
    {
        return 0;
    }
    int mid = (l + r) / 2; // l + (r - l) / 2
    long long inv1 = inversions(l, mid);
    long long inv2 = inversions(mid + 1, r);
    return inv1 + inv2 + merge(l, mid, mid + 1, r);

}

//min amount of swaps is inversion count -> 
        // 1. make vector and count inversions (quickly? merqe sort?)
        // 2. sort in nlogn
        // 3. see if its sorted

long long maybeSort() {
	long long ans = 0;
	for (int i = 0; i < k; i++) {

        int sz = 0;
        for (int j = i; j < n; j += k) {
            a[sz] = arr[j];
            sz++;
        }

        ans += inversions(0, sz -1);
        sort(a, a + sz );

        int x = 0;
        for (int j = i; j < n; j += k) {
            arr[j] = a[x];
            x++;
        }
	}

	if (k == 1) return ans;

	for (int i = 0; i < n - 1; i++) 
		if (arr[i] > arr[i + 1]) return -1;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];

	cout << maybeSort() << endl;

	return 0;
}
