//https://www.acmicpc.net/problem/7785
#include <iostream>
// #include <limits.h>
// #include <math.h>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    // int maxLog = 1000000;
    // int sortMax = maxLog * log(maxLog)+maxLog*2;
    // cout << sortMax;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;  cin >> n;
    unordered_map<string,bool> log;
    while(n--)
    {
        string name;
        string enter;
        cin >> name >> enter;
        if(enter == "enter")
            log[name] = 1;
        else
            log[name] = 0;
    }
    set<string,greater<string>> name;
    for(auto ele : log)
    {
        if(ele.second)
            name.insert(ele.first);

    }
    for(auto ele : name)
        cout << ele << "\n";
    cout << "\n";
}