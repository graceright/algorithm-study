#include <stdio.h>
#include <vector>
#include <cmath>

using namespace std;

#define GRAVITY_ACC     (double)9.81

struct rocketStage
{
    double weight, time, force;
    rocketStage(double weight=0, double time=0, double force=0) : weight(weight), time(time), force(force) {}
};

int main()
{
    int K;  scanf("%d", &K);
    for(int s = 1; s <= K; s++)
    {
        int stage{};
        double rocketW{}, result{}, velocity{};
        scanf("%d %lf", &stage, &rocketW);
        vector<rocketStage> rocket(stage);
        for(int i = 0; i < stage; i++)
        {
            scanf("%lf %lf %lf", &rocket[i].weight, &rocket[i].time, &rocket[i].force);
            rocketW += rocket[i].weight;
        }

        for(auto r : rocket)
        {
            double a = r.force/rocketW - GRAVITY_ACC;
            result += velocity*r.time + (double)0.5 * a * r.time * r.time;
            velocity += a * r.time;
            rocketW -= r.weight;
        }
        printf("Data Set %d:\n%.2lf\n\n", s, round(result*100)/100);
    }
}