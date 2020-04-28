#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
int main(void) {
  int id = shmget(IPC_CREAT, 4* sizeof (int), IPC_CREAT | 0666);
  int *ptr = shmat(id, NULL, 0);
  pid_t childpid = fork();
  
  if (childpid < 0) {
    perror("Failed to fork");
  return 1;
  }
  if (childpid == 0){ /* child code */
    sleep(5);
    *ptr = 5;
    printf("I am child %ld, ID = %d\n", (long)getpid(), *ptr);
  }
  else{ /* parent code */
    sleep(10);
    *ptr = *ptr + 5;
    printf("I am parent %ld, ID = %d\n", (long)getpid(), *ptr);
  }
  sleep(15);
  return 0;
}
