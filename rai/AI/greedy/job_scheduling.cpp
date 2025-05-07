#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Sort jobs by deadline (ascending)
bool compareJobs(const vector<int> &job1, const vector<int> &job2) {
    return job1[2] < job2[2]; // Index 2 = deadline
}

// Greedy job scheduling function
pair<int, vector<vector<int>>> greedyJobScheduling(vector<vector<int>> &jobs) {
    sort(jobs.begin(), jobs.end(), compareJobs);

    int current_time = 0, total_profit = 0;
    vector<vector<int>> scheduled_jobs;

    for (auto &job : jobs) {
        int processing_time = job[0];
        int profit = job[1];
        int deadline = job[2];

        if (current_time + processing_time <= deadline) {
            current_time += processing_time;
            scheduled_jobs.push_back(job);
            total_profit += profit;
        }
    }

    return {total_profit, scheduled_jobs};
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    vector<vector<int>> jobs;
    cout << "Enter jobs as [processing_time profit deadline] for each job:\n";
    for (int i = 0; i < n; i++) {
        int pt, p, d;
        cin >> pt >> p >> d;
        jobs.push_back({pt, p, d});
    }

    pair<int, vector<vector<int>>> result = greedyJobScheduling(jobs);

    cout << "\nTotal profit earned: " << result.first << endl;
    cout << "Scheduled jobs:\n";
    for (vector<int>& job : result.second) {
        cout << "Processing time: " << job[0]
             << ", Profit: " << job[1]
             << ", Deadline: " << job[2] << endl;
    }

    return 0;
}


