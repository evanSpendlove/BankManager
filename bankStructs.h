/*

username: sawal   password:maskey
username: SAGAR  password:sharma
username: RAVI     password:agrawal
The tasks that admin can perform in this program is listed below:
1.Add user
2.Delete user
3.Edit username/password
4.View user log
The tasks that staff can perform in this program is listed below:
1.Create new account
2.Cash Deposit
3.Cash withdrawl
4.Fund Transfer
5.Account information
6.Transaction information
7.Log out

Structs we need:
- User struct (username, password)
- user log
- Account
    -> Function: Cash withdrawl
    -> Function: Fund Transfer
    -> Account info
    -> Transaction info

*/

/* # INCLUDES FOR INCLUDING STANDARD C LIBRARIES */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#ifndef bankStructs_h
    #define bankStructs_h

        /* PRINT COLOURS */
        #define PRINT_RED     "\x1b[31m" // Escape code to print text in red
        #define PRINT_BLUE    "\x1b[34m" // Escape code to print text in blue
        #define PRINT_GREEN   "\x1b[32m" // Escape code to print text in green
        #define PRINT_MAGENTA "\x1b[35m" // Escape code to print text in magenta
        #define PRINT_CYAN    "\x1b[36m" // Escape code to print text in cyan
        #define PRINT_YELLOW  "\x1b[33m" // Escape code to print text in yellow
        #define PRINT_RESET   "\x1b[0m" // Resets print colour to white
        
        /* User struct - for storing a username/password pair */
        typedef struct user
        {   
            char userID[4]; // Unique user ID
            char username[20]; // Username string
            char password[20]; // Password string
        }user;

        typedef struct account//Structure for storing account information
        {
            char accountNumber[8];
            char firstName[30], lastName[30];
            float currentBalance;
        }account;

#endif