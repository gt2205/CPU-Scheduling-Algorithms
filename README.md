# CPU Scheduling Algorithms

This repository contains implementations of various CPU scheduling algorithms in C++. The algorithms covered include:

- First-Come, First-Served (FCFS)
- Shortest Job First (SJF) Non-Preemptive
- Shortest Job First (SJF) Preemptive
- Round Robin (RR)

## Description

CPU scheduling is a fundamental concept in operating systems, where the scheduler determines the order in which processes run on the CPU. Different scheduling algorithms can have a significant impact on the performance of a system. This repository provides implementations of some of the most common scheduling algorithms, with detailed comments to explain the logic behind each algorithm.

### First-Come, First-Served (FCFS)

FCFS is the simplest scheduling algorithm, where the process that arrives first gets executed first. It's a non-preemptive scheduling algorithm, meaning once a process starts execution, it runs to completion.

### Shortest Job First (SJF) Non-Preemptive

SJF selects the process with the shortest burst time for execution next. It's a non-preemptive algorithm, so once a process starts execution, it runs to completion. This algorithm can reduce the average waiting time compared to FCFS.

### Shortest Job First (SJF) Preemptive

Preemptive SJF, also known as Shortest Remaining Time First (SRTF), selects the process with the shortest remaining burst time for execution. This means that if a new process arrives with a shorter burst time than the remaining time of the current process, the current process is preempted, and the new process is executed.

### Round Robin (RR)

Round Robin scheduling algorithm assigns a fixed time quantum to each process in the ready queue in a cyclic manner. If a process's burst time is greater than the time quantum, it is preempted and placed back in the queue with its remaining burst time. This algorithm ensures fair CPU time distribution among all processes.

## Getting Started

### Prerequisites

- A C++ compiler (e.g., g++)
- Standard C++ library

### Running the Code

Each algorithm is implemented in its respective file. To compile and run the code for each algorithm, follow the instructions below:

1. **Clone the repository:**

   ```bash
   git clone https://github.com/gt2205/CPU-Scheduling-Algorithms.git
   cd CPU-Scheduling-Algorithms
