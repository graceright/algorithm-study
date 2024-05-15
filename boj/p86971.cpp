#define LOCAL

#include <string>
#include <vector>

#include <iostream>

using namespace std;

int count = 0;

void bfs_count(int n, int m, vector<vector<int>> wires) {
    //wires[n][m]과 이어지는 node 탐색
    int index = wires[n][m];
    for(int i = 0; i < wires.size() && i != n; i++) {
        if(wires[i][0] == index) {   //find connected node
            cout << wires[i][0] << "->";
            count++;
            bfs_count(i, 0, wires);
        } else if(wires[i][1] == index) {    //find connected node
            cout << wires[i][1] << "->";
            count++;
            bfs_count(i,1,wires);
        }
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;

    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    #endif
    
    for(int i = 0; i < n; i++) {
        //wires[i][0] 이어지는 노드까지 탐색(BFS)
        count = 0;
        bfs_count(i, 0, wires);
        // count, n-count answer = abs(n-count*2)
    }
    return answer;
}

/*


*/