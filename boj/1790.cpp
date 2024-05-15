//https://www.acmicpc.net/problem/1790
#include <cstdio>
// #include <iostream>
#include <vector>
#include <math.h>
using namespace std;


#define     BOUNDCNT(x)     x*(int)pow(10,x-1)*9
int N,K;

int main()
{
    scanf("%d %d",&N,&K);
    //N이 몇자리수까지 가는지, 자리수마다의 누적으로 몇번째 자리인지 vector에 삽입
    long long totalCnt(0), cnt(0);
    vector<long long> v;
    long long temp(N);
    while(temp > 0)
    {
        temp /= 10;
        totalCnt += BOUNDCNT(cnt);
        v.push_back(totalCnt);
        cnt++;
    }
    //남은 자리수에 대해 추가하기
    totalCnt += cnt * (N-pow(10,cnt-1)+1);
    v.push_back(totalCnt);
    if(K > totalCnt)
    {   //수의 길이가 더 작은 경우
        printf("-1\n");
        return 0;
    }
    // for(auto a : v) cout << a << " ";
    // cout << endl;
    //vector v에 대해 K의 Lower Bound 찾기
    int start(0), end(v.size()-1);
    do
    {
        int mid = (start+end)/2;
        if(K < v[mid])
        {
            end = mid;
        }
        else if(K > v[mid])
        {
            start = mid;
        }
        else    //same
        {
            start = mid;
            end = mid;
            break;
        }
        // printf("%d %d\n",start,end);
    }while(end-start > 1);

    if(start == end)
    {   //해당 자리수의 맨 마지막이라서 무조건 9
        printf("9\n");
    }
    else
    {   //start < end 형식으로 start부터 K까지의 자리수를 계산하여 도출
        int restCnt = K - v[start]; //남은 자리수의 총 합
        int n1 = restCnt/cnt;       // 숫자로 쳤을때 몇번째 수인지,
        int n2 = restCnt%cnt;      // 해당 숫자의 몇번째 자리인지,
        if(n2 != 0) n1++;           //올림 필요해서
        int realNum = v[start] + n1;    //실제 숫자
        // printf("%d\n",realNum);
        //숫자 판독
        if(n2 == 0)
        {
            printf("%d\n",realNum%10);
            return 0;
        }
        for(int i = 1; i <= cnt-n2; i++)
        {
            realNum/=10;
        }
        printf("%d\n",realNum%10);
    }
}