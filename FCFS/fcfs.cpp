#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Process {
public:
  int arrival;
  int burst;
  int completion;
  int turnaround;
  int waiting;

  Process(int a, int b)
      : arrival(a), burst(b), completion(0), turnaround(0), waiting(0) {}
};

struct cmp {
  bool operator()(Process &a, Process &b) {
    if (a.arrival != b.arrival)
      return a.arrival < b.arrival;
    return a.burst < b.burst;
  }
};

void fcfs(vector<Process> &processes) {
  int t = processes[0].arrival;
  float wait = 0, turnaround = 0;

  for (int i = 0; i < processes.size(); i++) {
    if (t < processes[i].arrival) {
      t = processes[i].arrival;
    }

    processes[i].completion = t + processes[i].burst;
    processes[i].turnaround = processes[i].completion - processes[i].arrival;
    processes[i].waiting = processes[i].turnaround - processes[i].burst;
    t = processes[i].completion;
  }
}

int main() {
  int n;
  cout << "No of processes:" << endl;
  cin >> n;
  vector<Process> processes;
  for (int i = 0; i < n; i++) {
    int arrival, burst;
    cout << "Process " << i + 1 << " -\n";
    cout << "Arrival time: ";
    cin >> arrival;
    cout << "Burst time: ";
    cin >> burst;
    processes.emplace_back(arrival, burst);
  }
  sort(processes.begin(), processes.end(), cmp());

  fcfs(processes);

  cout << "\nProcess\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n";
  for (int i = 0; i < n; i++) {
    cout << "P" << i + 1 << "\t\t" << processes[i].arrival << "\t\t"
         << processes[i].burst << "\t\t" << processes[i].completion << "\t\t\t"
         << processes[i].turnaround << "\t\t\t\t" << processes[i].waiting
         << "\t\n";
  }

  return 0;
}
