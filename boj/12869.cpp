//https://www.acmicpc.net/problem/12869
using namespace std;

#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <algorithm>

int attackPower[3] = {9,3,1};
bool dp[61][61][61][61]; // 횟수, scv1, scv2, scv3

int main()
{
    int N;  scanf("%d", &N);
    vector<int> scv(3);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &scv[i]);
    }
    sort(scv.begin(), scv.end());
    dp[0][scv[0]][scv[1]][scv[2]] = true;
    for(int cnt = 1; cnt <= 60; cnt++)
    {
        for(int scv1 = 0; scv1 <= 60; scv1++)
        {
            for(int scv2 = 0; scv2 <= 60; scv2++)
            {
                for(int scv3 = 0; scv3 <= 60; scv3++)
                {
                    if(dp[cnt-1][scv1][scv2][scv3] == true)
                    {
                        vector<int> scv = {scv1,scv2,scv3};
                        do
                        {
                            vector<int> nextSCV(scv);
                            for(int i = 0; i < 3; i++)
                            {
                                nextSCV[i] -= attackPower[i];
                                if(nextSCV[i] < 0)
                                    nextSCV[i] = 0;
                            }
                            //SCV 체력 검사
                            if((nextSCV[0] | nextSCV[1] | nextSCV[2]) == 0)
                            {
                                // printf("%d %d %d -> %d %d %d\n",scv1,scv2,scv3,nextSCV[0],nextSCV[1],nextSCV[2]);
                                printf("%d", cnt);
                                return 0;
                            }
                            sort(nextSCV.begin(),nextSCV.end());
                            dp[cnt][nextSCV[0]][nextSCV[1]][nextSCV[2]] = true;
                        } while (next_permutation(scv.begin(), scv.end()));
                        
                    }
                }
            }
        }
    }
}