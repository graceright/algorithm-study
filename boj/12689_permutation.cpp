//https://www.acmicpc.net/problem/12869
using namespace std;

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>

int dp[61][61][61]; //scp1,2,3 체력일때의 공격횟수 최소값 저장

//scv1.2.3의 체력이 주어질 때의 최소 공격을 반환하는 재귀함수
int minAttack(vector<int> scv)
{
    if(dp[scv[0]][scv[1]][scv[2]] != -1)
        return dp[scv[0]][scv[1]][scv[2]];
    if((scv[0] | scv[1] | scv[2]) == 0)   //답이 나옴
        return 0;   //개수를 하나씩 올려가면서 count하는 것이기 때문

    vector<int> attack = {1,3,9};   //next_permutation에 넣기 위해 오름차순 정렬
    int &answer = dp[scv[0]][scv[1]][scv[2]];   //후에 scv vector에 직접 변경하니까 미리 referece 할당
    answer = 9e8;   //minimum 갱신 편하게 하려고
    do
    {
        vector<int> nextSCV(scv);
        for(int i = 0; i < 3; i++)
            nextSCV[i] = max(0, nextSCV[i]-attack[i]);
        sort(nextSCV.begin(), nextSCV.end());
        answer = min(answer, minAttack(nextSCV));
    } while (next_permutation(attack.begin(), attack.end()));
    answer++;   //공격한번 더했으니까
    return answer;
}

int main()
{
    int N;  scanf("%d", &N);
    memset(dp,-1,sizeof(dp));
    vector<int> scv(3);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &scv[i]);
    }
    sort(scv.begin(), scv.end());
    printf("%d", minAttack(scv));
}