#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    int start;
    int finish;
};

bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

int main() {

    int n;

    cout << "Enter number of activities: ";
    cin >> n;

    vector<Activity> activities(n);

    cout << "Enter start and finish time of each activity:\n";

    for (int i = 0; i < n; i++) {
        cin >> activities[i].start >> activities[i].finish;
    }

    sort(activities.begin(), activities.end(), compare);

    cout << "\nSelected activities:\n";

    int lastFinish = activities[0].finish;

    cout << "(" << activities[0].start << ", "
         << activities[0].finish << ")\n";

    int count = 1;

    for (int i = 1; i < n; i++) {

        if (activities[i].start >= lastFinish) {

            cout << "(" << activities[i].start << ", "
                 << activities[i].finish << ")\n";

            lastFinish = activities[i].finish;
            count++;
        }
    }

    cout << "\nMaximum number of activities = " << count << endl;

    return 0;
}