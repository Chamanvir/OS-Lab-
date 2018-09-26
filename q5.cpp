#include <stdio.h>
#include <pthread.h>
#include <unistd.h>



bool lock = false; // shared variable

void acquire(bool lock) {
while (lock) {printf("Lock: Some work is going on...");};
lock = true;
}

void release(bool lock) {
lock = false;
printf("Lock has been released");
}

int main()
{
        acquire(lock);
        release(lock);
        return 0;
}