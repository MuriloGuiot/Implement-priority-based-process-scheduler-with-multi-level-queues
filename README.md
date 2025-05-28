Implementation of a Priority-Based Process Scheduler in C

- Developed three singly linked queues to manage processes with High (0), Normal (1), and Low (2) priorities.
- Initialized 20 processes with unique PIDs, randomly assigned priorities, and execution times between 10 and 20 seconds.
- Designed a scheduling algorithm that executes processes in cycles, adhering to the priority ratio: 3 High, 2 Normal, and 1 Low priority processes per cycle.
- Assigned random time slices within priority-specific ranges:
  - High priority: 8 to 10 seconds
  - Normal priority: 5 to 8 seconds
  - Low priority: 2 to 5 seconds
- Simulated process execution duration using Windows Sleep function.
- Removed and deallocated processes upon completion (zero or negative remaining time).
- Re-queued processes with remaining execution time for subsequent cycles.
- Provided comprehensive console output detailing total elapsed time, process PID, priority, time slice duration, remaining time, and completion notifications.
- Program terminates gracefully when all process queues are empty, confirming completion of all scheduled processes.

Files included:
- main.c: Core scheduling logic and queue management.
- utils.c / utils.h: Auxiliary functions for queue operations and process creation.
