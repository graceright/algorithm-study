//https://www.acmicpc.net/problem/7662
#include <iostream>
#include <set>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;  cin >> T;
    while(T--)
    {
        int K;  cin >> K;
        multiset<int> list;
        while(K--)
        {
            //1. I : 삽입, 중복가능
            //2. D 1 : 최댓값 삭제
            //3. D -1 : 최솟값 삭제
            //비어있을 경우 무시
            char command;   cin >> command;
            int val;    cin >> val;
            if(command == 'I')
            {
                list.insert(val);
            }
            else    // 'D'
            {
                if(list.empty())
                    continue;
                if(val == 1)    //최댓값 삭제
                {
                    multiset<int>::iterator min = list.end();
                    // cout << "pop min " << *(--min) << "\n"; ++min;
                    list.erase(--min);
                }
                else    //최솟값 삭제
                {
                    multiset<int>::iterator max = list.begin();
                    // cout << "pop max " << *max << "\n";
                    list.erase(max);

                }
            }
        }
        if(list.empty())  cout << "EMPTY\n";
        else    cout << *list.rbegin() << " " << *list.begin() << "\n";
    }
}