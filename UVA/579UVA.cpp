#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl;

using namespace std;


int main()
{
    float hours_angle = 360/12, minute_angle = 360 / 60, hours_angle_per_minute = 30.0 / 60.0;
    // debug(hours_angle); debug(minute_angle); debug(hours_angle_per_minute);
    int hours, minutes;
    while(scanf("%d:%d", &hours, &minutes), !(hours == 0 && minutes == 0)){
        float degree_hours = hours_angle * hours + hours_angle_per_minute * minutes, degree_minutes = minute_angle * minutes;
        // debug(degree_hours); debug(degree_minutes);
        float ans = min(min(fabs(degree_hours - degree_minutes), fabs(360 - degree_hours + degree_minutes)), fabs(360 - degree_minutes + degree_hours));
        // debug(fabs(degree_hours - degree_minutes)); debug(fabs(360 - degree_hours + degree_minutes));
        cout << fixed << setprecision(3) << ans << endl;
    }

    return 0;
}