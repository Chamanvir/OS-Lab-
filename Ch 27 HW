# Questions

1. First build `main-race.c`. Examine the code so you can see the (hopefully obvious) data race in the code. Now run `helgrind` (by typing `valgrind --tool=helgrind main-race`) to see how it reports the race. Does it point to the right lines of code? What other information does it give to you?
    - Yes, it points to the right lines of code. At first I was confused by the appearance of two error messages, pointing to line 15 of the `c` source file. Then I realised that one is for the write, the other for the read (and that is also reflected in the instruction address). 

2. What happens when you remove one of the offending lines of code? Now add a lock around one of the updates to the shared variable, and then around both. What does helgrind report in each of these cases?
    - Removing one of the offending lines makes `helgrind` stop complaining.
    - Lock around 1: `helgrind` reports the locks/threads, and also points out the race conditions that still exist. 
    - Lock around both: `helgrind` stops complaining.

3. Now let’s look at `main-deadlock.c`. Examine the code. This code has a problem known as deadlock (which we discuss in much more depth in a forthcoming chapter). Can you see what problem it might have?
    - the dealock will occur when each thread executes the first lock in the if/else block. Eg. T1 obtains a lock on `m1`, then T2 obtains a lock on `m2`. Neither of them will able to get the subsequent lock, since each is holding it and waiting for the other to release. 

4. Now run `helgrind` on this code. What does `helgrind` report?
    - `helgrind` reports that the lock ordering is wrong. i.e. If both threads obtain the locks in the same order then no deadlock will occur. 

5. Now run `helgrind` on `main-deadlock-global.c`. Examine the code; does it have the same problem that `main-deadlock.c` has? Should `helgrind` be reporting the same error? What does this tell you about tools like `helgrind`?
    - `main-deadlock-global` uses a coarse-grained lock to solve the lock-ordering problem, so no, it (crudely) solves the prior problem. `helgrind` still reports the issue. I am not sure if this implies that `helgrind` is smart enough to see through the suboptimal fix, or if the leson to be learnt is that sometimes `helgrind` gets it wrong, and sees deadlock where none exists. Either way - good to know!
