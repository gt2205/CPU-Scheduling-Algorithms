# CPU Scheduling - First-Come, First-Served (FCFS) Algorithm

This project demonstrates the First-Come, First-Served (FCFS) CPU scheduling algorithm. The FCFS algorithm schedules processes in the order of their arrival times. This implementation takes user input for the number of processes and their respective arrival and burst times, then calculates and displays the completion, turnaround, and waiting times for each process.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Usage](#usage)
- [Example](#example)

## Introduction
The First-Come, First-Served (FCFS) scheduling algorithm is one of the simplest types of CPU scheduling algorithms. It operates by servicing the processes in the order in which they arrive. This implementation sorts processes by their arrival time and computes various metrics such as completion time, turnaround time, and waiting time for each process.

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
$ g++ fcfs.cpp -o fcfs
$ ./fcfs
No of processes:
3
Process 1 -
Arrival time: 0
Burst time: 4
Process 2 -
Arrival time: 1
Burst time: 3
Process 3 -
Arrival time: 2
Burst time: 1

Process    Arrival   Burst    Completion    Turnaround    Waiting
P1         0         4        4             4             0
P2         1         3        7             6             3
P3         2         1        8             6             5

