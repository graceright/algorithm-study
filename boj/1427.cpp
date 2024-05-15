#define LOCAL

#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    #endif
    cin.tie(0) -> sync_with_stdio(0);

    string num = "";

    getline(cin,num);

    vector<int> vec;

    for(char c : num) {
        vec.push_back(c-'0');
    }

    sort(vec.begin(),vec.end(),greater<int>());

    for(int item : vec) {
        cout << item;
    }
    cout << endl;

}