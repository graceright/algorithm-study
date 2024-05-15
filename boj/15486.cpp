//https://www.acmicpc.net/problem/15486
#include <iostream>
#include <vector>

using namespace std;
vector<int> schedule;
vector<int> pay;
vector<int> dp;


int main()
{
    int n;  scanf("%d", &n);
    schedule.resize(n+1,0);
    pay.resize(n+1,0);
    dp.resize(n+2,0);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d %d",&schedule[i], &pay[i]);
    }

    for(int i = 1; i <= n; i++)
    {
        //상담을 한다면
        if(i+schedule[i] <= n+1)
            dp[i+schedule[i]] = max(dp[i+schedule[i]], dp[i]+pay[i]);
        //상담을 하지 않는다면
        dp[i+1] = max(dp[i+1],dp[i]);
    }

    printf("%d",dp[n+1]);
    return 0;
}