#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXNM = 1000005;
const int MAXR = 1000;
int p[MAXNM], l[MAXNM];
int n, m, cnt;
int i = 1, j = 1;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= m; i++) cin >> l[i];

    sort(p + 1, p + 1 + n);
    sort(l + 1, l + 1 + m);

    while (i <= n && j <= m) {
        if (p[i] <= l[j]) {
            cnt++;
            i++;
            j++;
        }
        else {
            j++;
        }
    }

    cout << cnt;
}
