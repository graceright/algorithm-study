//https://www.acmicpc.net/problem/12738
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(0); cout.tie(0);
    int n;  cin >> n;
    vector<int> lessVal;
    while(n--)
    {
        int a; cin >> a;
        auto it = lower_bound(lessVal.begin(), lessVal.end(), a);
        if(it == lessVal.end()) //갱신가능한 위치
        {
            lessVal.push_back(a);
        }
        else
        {
            *it = a;
        }
        // for(auto a : lessVal)
        //     cout << a << " ";
        // cout << "\n";
    }
    cout << lessVal.size() << "\n";
}