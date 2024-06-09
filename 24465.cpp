#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

//해당 날짜가 어느 별자리에 속하는지 그 물병자리부터 0으로 숫자를 매겨 반환
int zodiacCheck(int month, int day)
{
    if ((month == 1 && day >= 20) || (month == 2 && day <= 18)) return 0;
    if ((month == 2 && day >= 19) || (month == 3 && day <= 20)) return 1;
    if ((month == 3 && day >= 21) || (month == 4 && day <= 19)) return 2;
    if ((month == 4 && day >= 20) || (month == 5 && day <= 20)) return 3;
    if ((month == 5 && day >= 21) || (month == 6 && day <= 21)) return 4;
    if ((month == 6 && day >= 22) || (month == 7 && day <= 22)) return 5;
    if ((month == 7 && day >= 23) || (month == 8 && day <= 22)) return 6;
    if ((month == 8 && day >= 23) || (month == 9 && day <= 22)) return 7;
    if ((month == 9 && day >= 23) || (month == 10 && day <= 22)) return 8;
    if ((month == 10 && day >= 23) || (month == 11 && day <= 22)) return 9;
    if ((month == 11 && day >= 23) || (month == 12 && day <= 21)) return 10;
    return 11;
}

int main()
{
    //get Aloha member's zodiac
    vector<bool> isMemeberAstro(12, false);
    for(int i = 0; i < 7; i++)
    {
        int month, day;
        scanf("%d %d", &month, &day);
        isMemeberAstro[zodiacCheck(month,day)] = true;
    }
    //get candidate's birthday
    int n; scanf("%d", &n);
    vector<pair<int,int>> success;
    while(n--)
    {
        int month, day;
        scanf("%d %d", &month, &day);
        if(isMemeberAstro[zodiacCheck(month,day)] == false) //합격
        {
            success.push_back(make_pair(month,day));
        }
    }

    if(success.empty())
    {
        printf("ALL FAILED");
    }
    else
    {
        sort(success.begin(), success.end());
        for(auto a : success)
        {
            printf("%d %d\n",a.first, a.second);
        }
    }
}