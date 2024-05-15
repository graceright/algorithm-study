#define LOCAL

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    #endif
    string str = "";
    vector<int> alphabet(26, -1);
    getline(cin,str);
    for(int i = 0; i < str.length(); i++) {
        int n = str[i] - 'a';
        if(alphabet[n] == -1) {
            alphabet[n] = i;
        }
    }

    for(auto i : alphabet) {
        cout << i << " ";
    }
}