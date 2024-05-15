//https://www.acmicpc.net/problem/16909
using namespace std;

#include <iostream>
#include <set>
#include <utility>

int main()
{
    int N, result {};
    scanf("%d", &N);
    multiset<int> cards;
    for(int i = 0; i < N; i++)
    {
        int temp; scanf("%d", &temp);
        cards.insert(temp);
        pair<int,int> minVal, maxVal;   //first : card능력치 second : min/max 유지한 횟수
        if(i == 0)  //처음이면 그냥 넣기
        {
            minVal = make_pair(*cards.begin(), 0);
            maxVal = make_pair(*cards.rbegin(), 0);
        }
        else
        {   
            //값을 하나 넣었는데 최대/최소가 동시 갱신되는 경우는 맨 처음밖에 없으므로 하나씩 처리
            if(minVal.first != *cards.begin())  //최소값 갱신
            {
                result -= minVal.first * minVal.second;
                minVal = make_pair(*cards.begin(), 0);
            }
            else if(maxVal.first != *cards.rbegin())    //최대값 갱신
            {
                result += maxVal.first * maxVal.second;
                maxVal = make_pair(*cards.rbegin(), 0);
            }
        }
        minVal.second++;
        maxVal.second++;
    }

    printf("%d", result);
}