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
    if(r < 0 || c < 0)  //범위 밖
        return 0;
    if(dp[r][c] >= 0)   //dp에 이미 저장되어 있는 값
        return dp[r][c];
    dp[r][c] = max(dfs(r-1,c), dfs(r,c-1)) + candyMap[r][c];
    return dp[r][c];
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    candyMap.resize(n,vector<int>(m));
    dp.resize(n,vector<int>(m,-1));

    for(int r = 0; r < n; r++)
    {
        for(int c = 0; c < m; c++)
        {
            scanf("%d", &candyMap[r][c]);
        }
    }

    cout << dfs(n-1,m-1) << endl;
}