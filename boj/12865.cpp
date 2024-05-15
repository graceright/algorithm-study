//https://www.acmicpc.net/problem/12865
using namespace std;

#include <stdio.h>
#include <cstring>
#include <vector>
#include <utility>
int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    int dp[K+1][N];
    memset(dp,-1,sizeof(dp));
    vector<pair<int,int>> things(N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d %d", &things[i].first, &things[i].second);  //W, V
    }
    //처음 처리
    dp[0][0] = 0;
    dp[things[0].first][0] = things[0].second;
    for(int i = 1; i < N; i++)
    {
        for(int j = 0; j <= K; j++)
        {
            if(dp[j][i-1] != -1)    //이전단계에서 기록된 값 확인
            {
                int curVal {dp[j][i-1]};
                //i번째 물건을 넣지 않음
                dp[j][i] = max(dp[j][i], curVal);
                //i번째 물건을 넣음
                //무게 초과 확인
                int nextWeight = j + things[i].first;
                if(nextWeight <= K)
                {
                    int nextValue = curVal + things[i].second;
                    dp[nextWeight][i] = max(dp[nextWeight][i], nextValue);
                }
            }
        }

    }

    // for(int i = 0; i <= K; i++)
    // {
    //     for(int j = 0; j < N; j++)
    //         printf("%d\t",dp[i][j]);
    //     printf("\n");
    // }
    int answer {-1};
    for(int i = 0; i <= K; i++)
    {
        answer = max(answer, dp[i][N-1]);
    }
    printf("%d\n", answer);
}