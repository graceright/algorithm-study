//https://www.acmicpc.net/problem/11049
#include <stdio.h>
#include <vector>
using namespace std;
vector<vector<int>> dp;
vector<pair<int,int>> m;

int go(int l, int r)
{
    //탈출 조건
    if(dp[l][r] != 0)
    {
        return dp[l][r];
    }
    if(r-l == 1)    //조건이 없으므로 값이 하나뿐
    {
        return dp[l][r] = m[l].first * m[l].second * m[r].second;
    }
    if(r==l)    return 0;
    
    dp[l][r] = 9e8;
    for(int i = l; i < r; i++)
    {
        dp[l][r] = min(dp[l][r], go(l,i) + go(i+1, r) + m[l].first*m[i].second*m[r].second);
    }
    return dp[l][r];
}


int main()
{
    int N;  scanf("%d", &N);
    dp.resize(N,vector<int>(N));
    m.resize(N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d %d", &m[i].first, &m[i].second);
    }

    printf("%d\n", go(0, N-1));
}