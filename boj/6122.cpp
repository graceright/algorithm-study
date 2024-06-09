#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct cow
{
    int start{}, total{};  //min
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N, T;
    cin >> N >> T;
    vector<cow> cows(N+1);   //time(min)

    while(T--)
    {
        int cowNum, h, m;
        string op;
        cin >> cowNum >> op >> h >> m;
        if(op == "START")
        {
            cows[cowNum].start = h*60+m;
        }
        else if(op == "STOP")
        {
            cows[cowNum].total += h*60+m - cows[cowNum].start;
        }
    }
    //정산
    for(int i = 1; i <= N; i++)
    {
        cout << cows[i].total/60 << " " << cows[i].total%60 << "\n";
    }
}