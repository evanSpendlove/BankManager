/*
    Header file for user authentication (regarding login details) functions

    User enters a username and password.

    These are compared to a saved file of usernames and password.

    If they match one of these entries, the user is validated and logged in.
*/

#include "bankStructs.h"

/*
    login() function:
        --> Request user to enter their login details.
        --> Stores their log in details and calls parseLoginDetails() to authenticate.
*/
void login();

/*
    parseLoginDetails() function:
        --> Parses a .dat file for the user's log in details.
        --> Returns true if the user is found.
        --> Returns false if they are not found.
*/
bool parseLoginDetails();

/*
    saveUserDetails() function:
        --> Used when a new user is created.
        --> Saves the user's details to the users.dat file.
        --> 
*/
void saveUserDetails();