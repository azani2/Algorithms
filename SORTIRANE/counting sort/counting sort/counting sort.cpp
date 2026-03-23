#include <iostream>
using namespace std;

#define  MAXN 2000005

const long long MAXA = 1024;
int n, cnt[MAXA];
long long a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++)  cnt[a[i]]++;

    for (int i = 0; i < MAXA; i++) {
        for (int j = 0; j < cnt[i]; j++)
            cout << i << " ";
    }

    return 0;
}