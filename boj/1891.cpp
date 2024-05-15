//https://www.acmicpc.net/problem/1891
#include <cstdio>

using namespace std;
int d;
long long r,c;
long long limitLen;
int start[50];
int end[50];
int main()
{
    scanf("%d", &d);
    limitLen = 1LL<<d;    //사분면을 d의 단위로 나누었을때의 길이 제한(유효하지 않은 경우도 있기 때문에 체크용)
    for(int i = 0; i < d; i++)
    {
        scanf("%1d", &start[i]);
    }
    scanf("%lld %lld",&c, &r);
    r *= -1;
    //=====================================
    //사분면->array r,c 변환
    long long startR(0), startC(0), size(limitLen);
    for(int i = 0; i < d; i++)
    {
        // printf("%d\n", start[i]);
        size /= 2;
        //row 결정 - 1,2(0) 3,4(size)
        if(start[i] == 3 || start[i] == 4)
        {
            // printf("[row]%d += %d\n",startR, size);
            startR += size;
        }
        //col 결정 - 2,3(0) 1,4(size)
        if(start[i] == 1 || start[i] == 4)
        {
            // printf("[col]%d += %d\n", startC, size);
            startC += size;
        }
    }
    // printf("%lld %lld\n",startR, startC);
    long long endR(startR+r),endC(startC+c);
    // printf("%lld %lld\n", endR, endC);
    //범위 체크
    if(endR < 0 || endC < 0 || endR >= limitLen || endC >= limitLen)
    {
        printf("-1");
        return 0;
    }
    else
    {
        long long size(limitLen);

        for(int i = 0; i < d; i++)
        {
            size /= 2;
            //사방면 분리
            if(endR >= size)
            {
                if(endC >= size)
                {   //4방면
                    end[i] = 4;
                }
                else
                {   //3방면
                    end[i] = 3;
                }
            }
            else
            {
                if(endC >= size)
                {   //1방면
                    end[i] = 1;
                }
                else
                {   //2방면
                    end[i] = 2;
                }
            }
            // printf("%dst : %d\n",i,end[i]);
            endR %= size;
            endC %= size;
        }
    }
    for(int i = 0; i < d; i++)
        printf("%d",end[i]);
}