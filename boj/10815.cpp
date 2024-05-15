//https://www.acmicpc.net/problem/10815
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(0); cout.tie(0);
    int N, M;  cin >> N;
    vector<int> card(N);
    for(int i = 0; i < N; i++)
    {
        cin >> card[i];
    }
    cin >> M;
    vector<int> check(M);
    for(int i = 0; i < M; i++)
    {
        cin >> check[i];
    }
    sort(card.begin(), card.end());
    for(auto ele : check)
    {
        bool isFind(false);
        int left(0), right(N-1);
        while(left<=right)
        {
            int mid = (left+right)/2;
            if(card[mid] == ele)
            {
                isFind = true;
                break;
            }
            else if(card[mid] < ele)
            {
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }
        }
        cout << isFind << " ";
    }
    cout << "\n";
}