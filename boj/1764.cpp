#define LOCAL
#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    #endif
    cin.tie(0) -> sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    cin.ignore();

    map<string,int> map;
    vector<string> both_str;
    for(int i = 0 ; i < n+m; i++) {
        string str;
        getline(cin,str);
        map[str]++;
    }

    for(auto item : map) {
        if(item.second == 2) {
            both_str.push_back(item.first);
        }
    }

    cout << both_str.size() << '\n';
    for(auto str : both_str) {
        cout << str << '\n';
    }

}