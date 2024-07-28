# CPU Scheduling - Shortest Job First (SJF) Preemptive Algorithm

This project demonstrates the Shortest Job First (SJF) Preemptive CPU scheduling algorithm. The SJF algorithm schedules processes based on their burst times, selecting the process with the shortest burst time first. This implementation takes user input for the number of processes and their respective arrival and burst times, then calculates and displays the completion, turnaround, and waiting times for each process.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Usage](#usage)
- [Example](#example)

## Introduction
The Shortest Job First (SJF) Preemptive scheduling algorithm is a type of CPU scheduling algorithm that selects the process with the shortest burst time first. It operates by selecting the next process to run from the list of processes that have arrived and have the shortest burst time, with the added feature of preemption based on a time quantum. This implementation sorts processes by their arrival time and uses a priority queue to manage the processes.

## Features
- Input the number of processes along with their arrival and burst times.
- Calculate completion time for each process.
- Calculate turnaround time for each process.
- Calculate waiting time for each process.
- Display the scheduling results in a tabular format.

## Usage
To use this implementation, follow these steps:

1. Compile the program using a C++ compiler.
2. Run the executable.
3. Enter the number of processes.
4. Enter the arrival time and burst time for each process.
5. View the calculated completion, turnaround, and waiting times for each process.

## Example
Here's an example of how to use the program:

```sh
$ g++ sjf_preemptive.cpp -o sjf_preemptive
$ ./sjf_preemptive
Number of processes:
3
Process 1 -
Arrival time: 0
Burst time: 5
Process 2 -
Arrival time: 2
Burst time: 2
Process 3 -
Arrival time: 4
Burst time: 1

Process    Arrival   Burst    Completion    Turnaround    Waiting
P1         0         5        8             8             3
P2         2         2        4             2             0
P3         4         1        5             1             0
