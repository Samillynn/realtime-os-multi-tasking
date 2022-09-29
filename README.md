# Authors
- Hongyu Ding (20838222)
- Renhang Liu (21049351)

# project
https://git.uwaterloo.ca/h44ding/cs452_k1/-/tree/renhang

Note that we tend to use branch *renhang* as our final submission.

# Build Instructions
## build
```bash
cd cs452_k1
make clean && make
```
## run
put Pi number as the parameter for the ./upload.sh

for example, CS017542 (Pi No.2):
```bash
./upload.sh 2
```

# Kernel Descriptions
## Algorithms & Data Structures
- *priority queue*: 
The task scheduler uses a priority queue. Our priority queue is an array of queues. Since there is a fixed range for the priority (0-9), we create 10 queues with each queue represents a task queue for its corresponding priority. We enforce the priority nature of the queue by traversing the array in the order of their index (which is the priority). This kind of implementation keeps it simple and straightforward.

- *bool table*: 
The user stacks are fixed length memory blocks. There is a preallocated pool of memory blocks and a bool table for them for indicating whether each block has been allocated already. Whenever we want to allocate a new user stack, we go through the bool table to find a free memory block, and update the bool table. When we want to free the stack, we reset all the data in that memory block to zeros and reset the bool value.

- *task descriptor*: 
The task descriptor is stored as a struct which stores the task id, the parent task id, as well as the priority of the task. We also store the registers of the task and the corresponding task stack's address. We store all the registers here in the task descriptor so that the user will not be able to accidentally modify those register copies which might lead to undefined errors.

- *function pointer array*:
The exception handlers are stored in a function pointer array. This way we do not need to implicitly call the function but we can call the desired function with the specified array index. This makes it easier to connect with Assembly code.

## Kernel Primitives
- `int Create(int priority, void (*function))`: 
   It creates a new task; the new task is waiting in the task queue and ready for executing when it is scheduled; the return value will be the task id of the newly created task. When creating with priority we clamp it to a valid value (0-9) so that the priority will always be valid.

- `int MyTid()`:
   It returns the task id.

- `int MyParentTid()`:
   It returns the parent task's id.

- `void Yield()`:
   It pauses the task and moves the task to the end of the task queue.

- `void Exit()`:
   It terminates the task.

## Limitations
- *kernel stack size*: 0x10000 bytes
- *user stack size*: 0x10000 bytes
- *max user stacks*: 64
- *max user tasks*: 64

## Bugs
`int Create(int priority, void (*function))` only returns the task id of the newly created task. It will not return -1 if priority is not valid and it will not return -2 if kernel is out of task descriptors.

# Output Descriptions
```console
Boot successfully
Start Program
Created: 1

Created: 2

Tid: 3, ParentTid: 0

Tid: 3, ParentTid: 0

Created: 3

Tid: 4, ParentTid: 0

Tid: 4, ParentTid: 0

Created: 4

FirstUserTask: exiting

Tid: 2, ParentTid: 0

Tid: 2, ParentTid: 0

Tid: 1, ParentTid: 0

Tid: 1, ParentTid: 0

All user tasks have finished, exit elegantly
```
The first two lines indicate that it boots to the kernel. The first task will have a task id of 0 with priority 5, which will then call `Create()` 4 times. The first spawned task will have a task id of 1 with priority 3. Since it has a lower priority than the first task, the first task continues spawning after printing "Created: 1". Then the second spawned task will have a task id of 2 with priority 4. Similar to the first spawned task, it will not be executed right away since it has a priority 4 < 5. Then task 0 prints "Created: 2". After task 1 and task 2 are created, the third spawned task will have a task id of 3 with priority 6. Now since 6 is greater than 5, it will be executed first. It then prints its information "Tid: 3, ParentTid: 0". After that task 3 will call `Yield()` but since currently there's no task with higher priority than it, it continues executing. Then task 3 prints its information again "Tid: 3, ParentTid: 0". After it is done, it exits back to task 0 where it will print "Created: 3". Then task 4 will be spawned with task id 4 and priority 6. Similar to task 3 it will be executing first and print its information. It prints its information twice because when it calls `Yield()` in between the prints it falls back to it self as it has the highest priority. After task 4 is done, it exits back to task 0. Now task 0 has the highest priority 5 so it continues and prints "FirstUserTask: existing" before existing. After task 0 is done, the task with the highest priority will be task 2 who has priority 4. After task 2 is done, then task 1 will run and in the end all the tasks are done. In the end the kernel will print "All user tasks have finished, exit elegantly".
