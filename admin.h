/*
    Functions for the Admin user.
*/

#include "bankStructs.h"

/*
    addUser() function:
        --> Opens the user data file
        --> Searches for the end of the file
        --> Writes the new user to the end of the file
        --> Closes the file
*/
void addUser();

/*
    deleteUser() function:
        --> Opens the user data file
        --> Searches for the selected user
        --> Deletes that entry and sets the end pointer to that point.
        --> Closes the file
*/
void deleteUser();

/*
    editUserLogin() function:
        --> Opens the user data file
        --> Searches for the selected user
        --> Modifies their details
        --> Closes the file
*/
void editUserLogin();// To edit user name and/or password of existing user