//https://www.acmicpc.net/problem/12969
#include <cstdio>

using namespace std;

int dp[31][31][31][31*30/2];    //[len][A][B][Pair]
char answer[31];
int N, K;

bool go(int l, int a, int b, int p)
{
    if(l == N)  //탈출조건
    {
        if(p == K)  //answer
        {
            return dp[l][a][b][p] = true;
        }
        else
        {
            return dp[l][a][b][p] = false;
        }
    }
    if(dp[l][a][b][p])    //memoization
    {
        return false;
    }
    dp[l][a][b][p] = true;

    // calculation
    //add a
    // dp[l+1][a+1][b][p] = true;
    if(go(l+1,a+1,b,p))   //답인 루트에 해당함
    {
        // printf("l:%d,a:%d,b:%d,p:%d : A\n",l,a,b,p);
        answer[l+1] = 'A';
        return true;
    }

    //add b
    // dp[l+1][a][b+1][p+a] = true;
    if(go(l+1,a,b+1,p+a))
    {
        // printf("l:%d,a:%d,b:%d,p:%d : B\n",l,a,b,p);
        answer[l+1] = 'B';
        return true;
    }

    //add c
    // dp[l+1][a][b][p+a+b] = true;
    if(go(l+1,a,b,p+a+b))
    {
        // printf("l:%d,a:%d,b:%d,p:%d : C\n",l,a,b,p);
        answer[l+1] = 'C';
        return true;
    }

    return false;
}

int main()
{
    scanf("%d %d", &N, &K);
    if(go(0,0,0,0))
    {
        for(int i = 1; i <= N; i++)
        {
            printf("%c",answer[i]);
        }
    }
    else
    {
        printf("-1");
    }
}