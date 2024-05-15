//https://www.acmicpc.net/problem/10422
using namespace std;

#include <iostream>
#include <vector>

const int modVal {1000000007};
vector<int> dp(5001,-1);    //주의 : modulo 연산한 값 넣을 것

//dfs+dp로 괄호 문자열의 개수 반환(mod modVal한 값)
long long getLen(int L)
{
    if(dp[L] != -1)
        return dp[L];
    if(L % 2 == 1)  //홀수는 무조건 0
        dp[L] = 0;

    
    //점화식
    dp[L] = 0;
    for(int i = 1; i < L; i+=2) //홀수 체크할필요 x
    {
        // printf("getLen(i-1=%d) x genLen(L-1-i=%d)=",i-1,L-1-i);
        dp[L] += (getLen(i-1) * getLen(L-1-i)) % modVal;
        // printf("%d ",getLen(i-1) * getLen(L-1-i));
        // printf("curans : %d\n", answer);
        dp[L] %= modVal;
    }
    return dp[L];
}

int main()
{
    dp[0] = 1;  //괄호 내 아무것도 없는경우 1로 처리해야 곱이 제대로 수행되므로 초기화 진행 
    int testCase;   scanf("%d",&testCase);
    while(testCase--)
    {
        int L;  scanf("%d", &L);
        printf("%d\n", getLen(L));
    }
}