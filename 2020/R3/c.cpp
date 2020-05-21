#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

using LL = unsigned long long;

bool is_prime(LL x) {
    if (x == 0) return false;
    if (x == 1) return false;
    for (LL d = 2; d * d <= x; d++) {
        if (x % d == 0) return false;
    }
    return true;
}

LL str_to_LL(const std::string &str) {
    LL res = 0;
    for (char ch: str) {
        res *= 10;
        res += ch - '0';
    }
    return res;
}

bool is_splitable(char ch) {
    switch (ch) {
        case '0':
        case '2':
        case '4':
        case '5':
        case '6':
        case '8':
            return true;
    }
    return false;
}

void split(const string &str, vector<string> &vec) {
    int pre = -1;
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        if (is_splitable(ch)) {
            if (pre + 1 < i) {
                vec.push_back(str.substr(pre + 1, i - pre - 1));
            }
            pre = i;
        }
    }
}

bool check(string s) {
    int n = s.length();
    for (int i = 0; i < n; i++) {
        std::rotate(s.begin(), s.begin() + 1, s.end());
        LL res = str_to_LL(s);
        if (!is_prime(res)) {
            return false;
        }
    }
    return true;
}

string ans;
LL llans;
void test(const string &s) {
    if (ans.length() > s.length()) return;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int len = j - i + 1;
            if (len < ans.length()) continue;
            string ss = s.substr(i, len);
            LL llss = str_to_LL(ss);
            if (llss <= llans) continue;
            if (check(ss)) {
                llans = llss;
                ans = ss;
            }
        }
    }
}

int main() {
    string str;
    cin >> str;
    str += '0';
    ans = "";
    llans = 0;
    for (char ch: str) {
        LL x = ch - '0';
        if (is_prime(x) && (ans.empty() || x > str_to_LL(ans))) {
            ans = ch;
            llans = x;
        }
    }
    vector<string> vec;
    split(str, vec);
    for (const auto &s: vec) {
        test(s);
    }

    if (ans.empty()) {
        ans = "-1";
    }
    cout << ans << endl;
    return 0;
}
