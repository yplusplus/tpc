#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        vector<pair<char, int> > vec;
        for (int i = 0; i < str.length(); i++) {
            char ch = str[i];
            if (vec.empty()) {
                vec.push_back({ch, i + 1});
            } else if (vec.back().first == ch) {
                vec.push_back({ch, i + 1});
            } else {
                vec.pop_back();
            }
        }

        if (vec.empty()) {
            cout << 1 << " " << str.length() << endl;
        } else {
            int len = vec.size();
            int t = len / 2;
            while (t > 0) {
                vec.pop_back();
                t--;
            }
            cout << vec.front().second << " " << vec.back().second << endl;
        }
    }
    return 0;
}
