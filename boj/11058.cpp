//https://www.acmicpc.net/problem/11058
#include <stdio.h>
#include <vector>

using namespace std;

vector<long long int> dp(101);

//idx 위치의 최대값을 반환
long long int dppermutation(int idx)
{
    //탈출 조건
    if(idx < 0) return 0;   //idx minus 초과의 경우 0으로 처리
    if(dp[idx] != 0) return dp[idx];
    
    dp[idx] = idx;  //출력만 했을 때를 base로 비교
    for(int k = 3; idx - k > 0; k++)
    {   //ACVVVV... 에 대한 max 계산 
        //(k-1)D[idx-k]
        dp[idx] = max(dp[idx], (k-1)*dppermutation(idx-k));
    }
    return dp[idx];
}

int main()
{
    int n;  scanf("%d",&n);
    printf("%lld", dppermutation(n));
}