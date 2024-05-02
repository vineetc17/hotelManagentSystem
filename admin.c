#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include<sys/shm.h>
#include<sys/ipc.h>

int main(){
    char choice;
    key_t admin_id='A';
    int key = ftok(&admin_id,'A');

    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    int *flag = (int *)shmat(shmid, NULL, 0);

    while(1){
        printf("Do you want to close the hotel? Enter Y for Yes and N for No.");
        scanf(" %c", &choice);

        if(choice=='Y' || choice=='y'){
            *flag=1;
                printf("Informing hotel manager to close the hotel...\n");
                while (*flag != 0) {
                    // Wait for acknowledgment
            }
                break;
            }
            else if (choice=='N' || choice=='n') {
                printf("Continuing operation...\n");
                break;
            }
            else{
                printf("Invalid input. Please enter Y or N.\n");
                continue;
            }
        }

    shmdt(flag);
    return 0;

}
