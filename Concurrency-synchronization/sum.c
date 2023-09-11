#include "thread.h"

#define N 100000000

long sum = 0;

void Tsum() {
  for (int i = 0; i < N; i++) {
    // sum++;
    asm volatile(
        "incq %0" : "+m"(sum)
    );
  }
}

int main() {
  spawn(Tsum);
  spawn(Tsum);
  join();
  printf("sum = %ld\n", sum);
}