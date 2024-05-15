//https://www.acmicpc.net/problem/9019
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;
char dslrchar[4] {'D','S','L','R'};

int dslr(int start, char c)
{
    int result, temp;
    switch (c)
    {
    case 'D':
        result = (start<<1)%10000;
        break;
    case 'S':
        result = start == 0 ? 9999 : start-1;
        break;
    case 'L':
        result = (start%1000)*10 + start/1000;
        break;
    case 'R':
        result = start/10 + (start%10)*1000;
        break;
    default:
        break;
    }
    return result;
}
string bfs(int start, int goal)
{
    vector<string> numLog(10000, "");
    queue<int> q;
    //시작값 입력
    int answer;
    for(int i = 0; i < 4; i++)
    {
        answer = dslr(start, dslrchar[i]);
        numLog[answer] = dslrchar[i];
        if(answer == goal)
        {
            return numLog[answer];  //첫 시도만으로 답을 찾은 경우
        }
        q.push(answer);
    }

    while(!q.empty())
    {
        int qStart = q.front();    q.pop();
        string calcLog = numLog[qStart];
        // cout << qStart << ":" << calcLog << "\n";
        //doing dslr
        for(int i = 0; i < 4; i++)
        {
            //경우의 수 줄이기 : L<->R은 수행하지 않는다.
            if((i == 3 && *(calcLog.end()-1) == dslrchar[2]) || (i == 2 && *(calcLog.cbegin()-1) == dslrchar[3]))    continue;
            answer = dslr(qStart, dslrchar[i]);
            if(answer == start || !numLog[answer].empty())  continue;   //이미 이전 탐색으로 연산 기록이 있다면 스킵
            numLog[answer] = calcLog + dslrchar[i];
            // cout << dslrchar[i] << "=>" << answer << ":" << numLog[answer] << "\n";
            if(answer == goal)
            {
                return numLog[answer];
            }
            q.push(answer);
        }
    }
    return "";  //답은 무조건 존재하므로 여기까지 도달하지 않음
    
}
int main()
{
    int N;
    cin >> N;
    vector<int> start(N);
    vector<int> goal(N);
    for(int i = 0; i < N; i++)
    {
        cin >> start[i] >> goal[i];
    }
    //==============================
    for(int i = 0; i < N; i++)
    {
        cout << bfs(start[i], goal[i]) << "\n";
    }
}