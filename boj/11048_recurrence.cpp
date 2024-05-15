//https://www.acmicpc.net/problem/11048
using namespace std;

#include <iostream>
#include <vector>

vector<vector<int>> candyMap;
vector<vector<int>> dp;

// dp[r][c]의 최대값을 반환
// 값이 -1이면 재귀적으로 계산
int dfs(int r, int c)
{
    // printf("%d %d\n",r,c);
    if(r < 0 || c < 0)  //범위 밖
        return 0;
    return max(dfs(r-1,c), dfs(r,c-1)) + candyMap[r][c];
}

int getdp(int r, int c)
{
    if(r < 0 || c < 0)
        return 0;
    else
        return dp[r][c];
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    candyMap.resize(n,vector<int>(m));
    dp.resize(n,vector<int>(m));

    for(int r = 0; r < n; r++)
    {
        for(int c = 0; c < m; c++)
        {
            scanf("%d", &candyMap[r][c]);
        }
    }

    for(int r = 0; r < n; r++)
    {
        for(int c = 0; c < m; c++)
        {
            dp[r][c] = max(getdp(r-1,c),getdp(r,c-1)) + candyMap[r][c];
        }
    }

    // for(auto a : dp)
    // {
    //     for(auto b : a)
    //         cout << b << "\t";
    //     cout << endl;
    // }
    printf("%d\n",dp[n-1][m-1]);

}