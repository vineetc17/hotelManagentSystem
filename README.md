# Hotel Management System

This project aims to simulate a simplified hotel management system using POSIX compliant C programs. The system comprises several components, each serving a specific role in managing the hotel's operations efficiently.
It utilizes POSIX-compliant APIs for inter-process communication and shared memory management to ensure robust and standardized communication between processes.

## Description

### 1. admin.c

- **Description**: admin.c acts as the interface for the hotel administrator, providing functionality to close the hotel operations if necessary.
- **Functionality**: It prompts the administrator to decide whether to close the hotel. Upon closure request, it communicates with the hotel manager to initiate the shutdown process.

### 2. hotelmanager.c

- **Description**: hotelmanager.c serves as the central management component of the hotel, overseeing various aspects of its operation.
- **Functionality**: It calculates the total earnings, wages, and profit for the hotel based on table-wise data received from table processes. Additionally, it handles the coordination of operations during hotel closure initiated by the administrator.

### 3. table.c

- **Description**: table.c represents individual tables within the hotel's dining area, responsible for managing customer orders and calculating the total bill.
- **Functionality**: It interacts with customers to take orders, processes them, and computes the total bill for the table. Each table operates as an independent process, ensuring parallel processing and efficient resource utilization.

### 4. waiter.c

- **Description**: waiter.c simulates the role of waiters within the hotel, responsible for serving customers and processing orders.
- **Functionality**: It receives orders from tables, computes the total bill for each waiter, and contributes to the overall earnings of the hotel. Similar to tables, each waiter operates as an independent process, enabling concurrent order processing.

## How to Use
1. Compile each C file separately using a C compiler like gcc.
2. Run each executable in separate terminal windows.
3. Follow the prompts in each component to interact with the system.

## Requirements
- POSIX compliant system (Linux, Unix, macOS)
- C compiler (gcc recommended)

---
