#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define HOTEL_MANAGER_SHM_NAME "hotel_manager_memory"

typedef struct {
    int table_number;
    int total_bill;
} WaiterData;

void write_earnings(int table_number, int total_bill) {
    FILE *fp = fopen("earnings.txt", "a");
    if (fp == NULL) {
        perror("Error opening earnings file");
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "Earning from Table %d: %d INR\n", table_number, total_bill);
    fclose(fp);
}

void write_message(const char *message) {
    FILE *fp = fopen("earnings.txt", "a");
    if (fp == NULL) {
        perror("Error opening earnings file");
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "%s\n", message);
    fclose(fp);
}

int main() {
    int total_tables;

    int totalAmt;
    WaiterData *waiter_data;

    key_t admin_id = 'A';             //Connect To Admin
    int key2 = ftok("/tmp", 'A');
    int shmid = shmget(key2, sizeof(int), 0666 | IPC_CREAT);
    int *flag = (int *)shmat(shmid, NULL, 0);

    printf("Enter the Total Number of Tables at the Hotel: ");
    scanf("%d", &total_tables);

    if (*flag == 1) {
        // Read totalAmt from shared memory
        key_t waiter_id;
        int waiter_key = ftok("/tmp", 'B');
        int waiter_shmid = shmget(waiter_key, total_tables* sizeof(WaiterData), 0666);
        waiter_data = (WaiterData *)shmat(waiter_shmid, NULL, 0);
        
        totalAmt = waiter_data[total_tables - 1].total_bill;

        for (int i = 0; i < total_tables; ++i) {
            write_earnings(waiter_data[i].table_number, waiter_data[i].total_bill); 
        }
        
        char earnings_message[100];
        sprintf(earnings_message, "Total Earnings of Hotel: %d INR", totalAmt);
        write_message(earnings_message);

        int wages = totalAmt * 0.4;
        int profit = totalAmt - wages;
        char wages_message[100];
        sprintf(wages_message, "Total Wages of Waiters: %d INR", wages);
        write_message(wages_message);

        char profit_message[100];
        sprintf(profit_message, "Total Profit: %d INR", profit);
        write_message(profit_message);

        *flag = 0;
    }

    printf("Thank you for visiting the Hotel!\n");

    shmdt(flag);
    return 0;
}
