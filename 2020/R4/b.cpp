#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100000 + 100;
int a[N];
int b[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b, b + n);
        int x = b[n / 2];
        int cnt = 0;
        const int m = n / 2;
        //cout << m << " " << x  << endl;
        for (int i = 0; i < m; i++) {
            if (b[i] == x) {
                cnt++;
            }
        }
        //cout << cnt << endl;
        long long ans = 0;
        for (int i = 0; i < n / 2; i++) {
            if (a[i] > x) {
                ans += m - i; 
                //cout << i << " " << endl;
            } else if (a[i] == x) {
                if (cnt > 0) {
                    cnt--;
                } else {
                    ans += m - i; 
                    //cout << i << " " << endl;
                }
            }
        }
        cnt = 0;
        for (int i = m; i < n; i++) {
            if (b[i] == x) cnt++;
        }
        for (int i = n - 1; i >= n / 2; i--) {
            if (a[i] < x) {
                ans += i - m;
                //cout << i << " " << endl;
            } else if (a[i] == x) {
                if (cnt > 0) cnt--;
                else {
                    ans += i - m;
                    //cout << i << " " << endl;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
