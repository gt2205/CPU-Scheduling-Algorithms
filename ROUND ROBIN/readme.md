# CPU Scheduling - Round Robin (RR) Algorithm

This project demonstrates the Round Robin (RR) CPU scheduling algorithm. The RR algorithm schedules processes in a cyclic order with a fixed time quantum, ensuring that each process gets an equal share of the CPU time. This implementation takes user input for the number of processes and their respective arrival and burst times, then calculates and displays the completion, turnaround, and waiting times for each process.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Usage](#usage)
- [Example](#example)

## Introduction
The Round Robin (RR) scheduling algorithm is a type of CPU scheduling algorithm that assigns a fixed time quantum to each process in a cyclic order. It operates by switching between processes at the end of each time quantum, ensuring that no process is starved of CPU time. This implementation sorts processes by their arrival time and uses a deque to manage the process queue.

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
$ g++ rr.cpp -o rr
$ ./rr
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
P1         0         5        9             9             4
P2         2         2        4             2             0
P3         4         1        5             1             0
