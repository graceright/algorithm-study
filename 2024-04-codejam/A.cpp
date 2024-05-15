#include <bits/stdc++.h>
using namespace std;

int room;
vector<int> damage;
vector<int> potion;
string s;

//전역변수 초기화
void clearVariable()
{
    room = 0;
    damage.clear();
    potion.clear();
    s.clear();
}

//생존여부 판단
bool isAlive(int64_t health)
{
    for(int round = 0; round < room; round++)
    {
        //fight with monster!
        health -= damage[round];
        if(health <= 0) return false;
        //get health!
        if(s[round] == '+') health += potion[round];
        else health *= potion[round];
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(0); cout.tie(0);
    int T; cin >> T;
    for(int i = 0; i < T; i++)
    {
        if(i!=0)
            clearVariable();
        cin >> room;
        int64_t end(1);
        for(int j = 0; j < room; j++)   
        {
            int temp;
            cin >> temp;
            damage.push_back(temp);
            end += temp;
        }
        cin >> s;
        for(int j = 0; j < room; j++)   
        {
            int temp;
            cin >> temp;
            potion.push_back(temp);
        }
        //이분탐색으로 용사 체력의 최소값 구하기
        int64_t start = 1;
        int64_t answer(0);
        while(start<=end)
        {
            int64_t mid = (start+end)/2;
            if(isAlive(mid))   //체력이 더 낮은곳으로 탐색
            {
                answer = mid;
                end = mid-1;
            }
            else
            {   //체력이 더 높은곳으로 탐색
                start = mid+1;
            }
        }
        cout << answer << "\n";
    }
}