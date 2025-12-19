# OS Lab - Scheduling Algorithms

This repository contains C++ implementations of various Operating System scheduling algorithms.

## Directory Structure

### Disk Scheduling (`/DiskScheduling`)
- **FCFS** (First Come First Serve)
- **SSTF** (Shortest Seek Time First)
- **SCAN**
- **C-SCAN** (Circular SCAN)
- **LOOK**
- **C-LOOK**
- **CLOOK+CSCAN**

### Task Scheduling (`/TaskScheduling`)
- **FCFS** (First Come First Serve)
- **SJF** (Shortest Job First)
- **Priority Scheduling**
- **Round Robin**

## Usage
Each algorithm is a standalone C++ file. You can compile and run them using any C++ compiler (e.g., g++).

```bash
g++ TaskScheduling/FCFS_Task.cpp -o FCFS_Task
./FCFS_Task
```
