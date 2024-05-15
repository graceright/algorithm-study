//https://www.acmicpc.net/problem/10816
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

long long test = 500000 * log(500000) + 500000 * log(500000) * 2;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);   cout.tie(0);
    int N,M;
    cin >> N;
    vector<int> card(N);
    for(int i = 0; i < N; i++)  cin >> card[i];
    sort(card.begin(),card.end());
    cin >> M;
    while(M--)
    {
        int element;    cin >> element;
        int left(0), right(N-1);
        int upper(0), lower(0);
        //1. upper bound 구하기
        while(left<=right)
        {
            int mid = (left+right)/2;
            if(card[mid] == element)
            {   //일치하는 경우를 구했지만, 더 큰 상한을 찾기 위해 left를 변경
                upper = mid+1;
                left = mid+1;
            }
            else if(card[mid] < element)
            {
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }
        }
        left = 0;
        right = N-1;
        //2. lower bound 구하기
        while(left <= right)
        {
            int mid = (left+right)/2;
            if(card[mid] == element)
            {   //일치하는 경우를 구했지만, 더 작은 하한을 찾기 위해 right를 변경
                lower = mid;
                right = mid-1;
            }
            else if(card[mid] < element)
            {
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }
        }
        // cout << upper_bound(card.begin(), card.end(),element) - lower_bound(card.begin(), card.end(), element) << " ";
        cout << upper - lower << " ";
    }
}