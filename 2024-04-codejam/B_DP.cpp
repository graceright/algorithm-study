#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
int T, N, B, LIMIT;
vector<int> charge_v, use_v, feeperuse_v;
vector<vector<long long>> dp;
//day일째 battery를 갖고 있을 때 최소 지불 비용 return
long long solve(int day, int battery) {
    if (day == N) {
        if (battery >= B) return 0; 
        else return INF;
    }
    if (dp[day][battery] != -1) return dp[day][battery];

    long long res = INF;
    // 배터리를 사용하는 경우
    if (battery >= use_v[day]) {
        res = min(res, solve(day + 1, battery - use_v[day]));
    }
    // 배터리를 충전하는 경우
    res = min(res, solve(day + 1, min(LIMIT, battery + charge_v[day])) + 1LL * use_v[day] * feeperuse_v[day]);

    dp[day][battery] = res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);   cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--)
    {
        cin >> N >> B >> LIMIT;
        charge_v.resize(N);
        use_v.resize(N);
        feeperuse_v.resize(N);
        for (int i = 0; i < N; i++) cin >> charge_v[i];
        for (int i = 0; i < N; i++) cin >> feeperuse_v[i];
        for (int i = 0; i < N; i++) cin >> use_v[i];

        dp = vector<vector<long long>>(N, vector<long long>(LIMIT + 1, -1));
        long long answer = solve(0, B);
        cout << answer << '\n';
    }

    return 0;
}