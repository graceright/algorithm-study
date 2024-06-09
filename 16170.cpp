#include <chrono>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    auto now = chrono::system_clock::now();
    time_t now_c = chrono::system_clock::to_time_t(now);
    struct tm* now_tm = gmtime(&now_c);

    cout << put_time(now_tm, "%Y\n%m\n%d");
}