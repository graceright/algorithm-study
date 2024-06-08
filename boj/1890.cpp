//https://www.acmicpc.net/problem/1890
#include <stdio.h>
#include <vector>
#include <stack>
#include <utility>

using namespace std;
#define LIMIT  100
vector<vector<int>> board(LIMIT,vector<int>(LIMIT));
vector<vector<long long>> dp(LIMIT,vector<long long>(LIMIT,-1));   //경로 기록이 완료되지 않은 경우 -1
int N;

//(r,c)의 가능한 모든 경로수를 dp[r][c]에 기록하고 반환하는 재귀함수
long long dps(int r, int c)
{
    if(r < 0 || c < 0)  return 0;
    if(r == 0 && c == 0) return 1;
    if(dp[r][c] != -1)  return dp[r][c];

    //board[r][c]의 값만큼 왼쪽,위의 경로값 더해서 저장 후 반환
    dp[r][c] = 0;
    //col 검사 : r 고정
    for(int i = 0; i < c; i++)
    {
        if(i + board[r][i] == c)
        {
            // printf("(%d,%d) ",r,i);
            dp[r][c] += dps(r,i);
        }
    }
    //row 검사 : c 고정
    for(int i = 0; i < r; i++)
    {
        if(i + board[i][c] == r)
        {
            // printf("(%d,%d) ",i,c);
            dp[r][c] += dps(i,c);
        }
    }
    // printf("\n");
    return dp[r][c];
}
int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }
    long long answer {};
    // 맨 마지막 위치 dp[N-1][N-1]은 맨 마지막 r와 c에 대해 도달이 가능한 부분들에 한해 경로 가능한 수를 더해 반환

    printf("%lld\n", dps(N-1,N-1));
    // for(int i = 0; i < N; i++)
    // {
    //     for(int j = 0; j < N; j++)
    //         printf("%d\t", dp[i][j]);
    //     printf("\n");
    // }

}