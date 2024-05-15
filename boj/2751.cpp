//https://www.acmicpc.net/problem/2751
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N;  cin >> N;
    set<int> s;
    vector<int> v;
    while(N--)
    {
        int temp;   cin >> temp;
        s.insert(temp);
        v.push_back(temp);
    }
    // for(auto ele : s)
        // cout << ele << "\n";
    sort(v.begin(), v.end());
    for(auto ele : v)
        cout << ele << "\n";
}