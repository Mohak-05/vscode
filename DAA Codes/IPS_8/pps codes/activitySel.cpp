#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int start, finish;
};


bool compare(Activity a1, Activity a2) {
    return a1.finish < a2.finish;
}

void activitySelection(vector<Activity>& activities) {
    sort(activities.begin(), activities.end(), compare); 
    
    cout << "Selected activities: ";
    int last_finish = 0;

    for (const auto& act : activities) {
        if (act.start >= last_finish) {
            cout << "(" << act.start << ", " << act.finish << ") ";
            last_finish = act.finish;
        }
    }
    cout << endl;
}

int main() {
    vector<Activity> activities = {
        {1, 3}, {2, 5}, {4, 6}, {6, 8}, {5, 7}, {8, 9}
    };

    activitySelection(activities);
    return 0;
}
