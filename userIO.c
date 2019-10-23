
#include "userIO.h"
#include <stdarg.h>

#ifdef _WIN32
    #include <windows.h>
#endif

/* UTILITY PRINT FUNCTIONS */

void printInstruction(const char *format, ...)
{   
    #ifdef _WIN32
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
    #else
        printf(PRINT_MAGENTA); // Sets the print colour to Magenta (for instructions)
    #endif

    va_list argList; // Initialises a list of variable arguments

    va_start(argList, format); // Initialises argList to be used for printing variable arguments

    vprintf(format, argList); // Prints the format string and its arguments using vprintf()
    #ifdef _WIN32
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    #else
        printf(PRINT_RESET); // Sets the print colour back to white
    #endif
    va_end(argList); // Ends the variable argument macro
}

void printError(const char *format, ...)
{
    #ifdef _WIN32
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    #else
        printf(PRINT_RED); // Sets the print colour to Magenta (for instructions)
    #endif
    
    va_list argList; // Initialises a list of variable arguments

    va_start(argList, format); // Initialises argList to be used for printing variable arguments

    vprintf(format, argList); // Prints the format string and its arguments using vprintf()

    #ifdef _WIN32
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    #else
        printf(PRINT_RESET); // Sets the print colour back to white
    #endif

    va_end(argList); // Ends the variable argument macro
}

void outputError(int errorCode)
{
    switch(errorCode)
    {
        case 3:
            printError("You have exceeded your login attempts.\n-- Exiting Software ---\n\n");
            break;
        case 5:
            printError("Error 5: File could not be opened.\n");
            break;
        default:
            printError("Error -1: Invalid Error Code.\n");
            break;
    }
}