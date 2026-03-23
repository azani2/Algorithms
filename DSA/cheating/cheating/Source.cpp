#include <iostream>
#include <stack>
using namespace std;

long n, a, c;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n;

    stack<pair<long long, long long>> s1;
    stack<pair<long long, long long>> s2;

    for (long long i = 0; i < n; i++) {
        cin >> a;

        while (!s1.empty() && s1.top().first < a) {
            s1.pop();
            s2.pop();
        }

        if (s1.empty()) {
            c += i;
            s1.push({ a, i });
            s2.push({ -1, 0 });
        }
        else {
            if (s1.top().first == a) {
                c += i - s2.top().first - 1;
                c += s2.top().second;
                s1.push({ a, i });
                s2.push(s2.top());
            }
            else {
                c += i - s1.top().second - 1;
                c += s1.size();
                s2.push({ s1.top().second, s1.size() });
                s1.push({ a, i });
            }
        }
    }
	cout << c << endl;
}
