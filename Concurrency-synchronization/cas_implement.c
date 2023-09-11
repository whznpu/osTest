#include <stdio.h>

static inline int cas_function(int *ptr, int old_val, int new_val) {
    int result;
    asm volatile (
        "lock cmpxchg %2, %1\n\t"
        "setz %0"
        : "=q"(result), "+m"(*ptr)
        : "r"(new_val), "a"(old_val)
        : "memory"
    );
    return result;
}

int main() {
    int value = 42;
    int old_value = 42;
    int new_value = 24;

    int result = cas_function(&value, old_value, new_value);

    if (result == 1) {
        printf("CAS succeeded. New value: %d\n", value);
    } else {
        printf("CAS failed. Current value: %d\n", value);
    }

    return 0;
}
