/*
    Function for user input/output functions.
*/

#include "bankStructs.h"

void outputError(int errorCode);

void printInstruction(const char *format, ...);

void printError(const char *format, ...);

void adminMenu();

void staffMenu();//Main program for STAFF portion to manage accounts

void viewAccountTransactions();// To view all the trasactions of an A/C

void getAccountInfo();// To view informations about the A/C and account holder

void viewUserLog();// To view log history of user
