//https://www.acmicpc.net/problem/1495
using namespace std;

#include <stdio.h>
#include <vector>
#include <set>

int main()
{
    int N,S,M;
    scanf("%d %d %d", &N, &S, &M);
    vector<int> vol(N+1);
    for(int i = 1; i <= N; i++)
        scanf("%d", &vol[i]);
    vector<set<int>> dp(N+1);
    dp[0].insert(S);
    for(int i = 1; i <= N; i++)
    {
        if(dp[i-1].empty())
        {
            printf("-1");
            return 0;
        }

        for(auto ele : dp[i-1])
        {   //이전 가능한 모든 볼륨 경우의 수에 대해서
            //높이기
            if(ele+vol[i] <= M)
            {
                // printf("%d : %d + %d = %d\n", i, ele, vol[i], ele+vol[i]);
                dp[i].insert(ele+vol[i]);
            }
            //낮추기
            if(ele-vol[i] >= 0)
            {
                // printf("%d : %d - %d = %d\n", i, ele, vol[i], ele-vol[i]);
                dp[i].insert(ele-vol[i]);
            }
        }
    }
    if(dp[N].empty())
        printf("-1");
    else
        printf("%d", *dp[N].rbegin());

}