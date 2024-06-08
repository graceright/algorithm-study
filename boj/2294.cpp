// https://www.acmicpc.net/problem/2294
#include <stdio.h>
#include <set>
#include <vector>
using namespace std;

int main()
{
    int coinCnt, value;
    scanf("%d %d", &coinCnt, &value);
    set<int> coin;
    vector<int> dp(value+1);
    for (int i = 0; i < coinCnt; i++)
    {
        int temp;
        scanf("%d", &temp);
        if(temp <= value)
            coin.insert(temp);
    }

    for (auto ele : coin)
    {
        dp[ele] = 1;    //min이니까
        for(int i = ele+1; i <= value; i++)
        {   //이전 dp값에서 현재 coin만큼 더한 값(+1 횟수) 중 최소값으로 업데이트
            if(dp[i-ele] != 0)
            {   // 이전에 가져오려는 동전의 조합이 최소한 가능해야 비교 가능
                int curCount = dp[i-ele] + 1;
                if(dp[i] == 0 || curCount < dp[i])
                {
                    dp[i] = curCount;
                }
            }
        }
    }

    // for(auto a : dp)
        // printf("%d ", a);
    if(dp[value] == 0)
        printf("-1");
    else
        printf("%d", dp[value]);
}