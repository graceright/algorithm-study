#define LOCAL

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    int n, acc(0), answer(0);
    cin >> n;
    cin.ignore();
    string line = "";

    for(int i = 0; i < n; i++) {
        getline(cin, line);
        for(char c : line) {
            if(c == 'O') {
                answer += ++acc;
            } else {
                acc = 0;
            }
        }

        cout << answer << endl;
        answer = 0; 
        acc = 0;
        line = "";
    }
    
}