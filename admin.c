/*
    Functions for the Admin user - creating, updating and deleting user login details
*/

#include "admin.h"
#include "userIO.h"

void addUser(user newUser)
{
   FILE* userFile;

    if((userFile = fopen("users.txt", "rb+")) == NULL) // Error checking - unable to open file
    {
        outputError(5); // Outputs: "Error 5: File could not be opened."
    }
    else
    {
        fseek(userFile, 0, SEEK_END);
        fwrite(&newUser, sizeof(user), 1, userFile);
        fclose(userFile);
    }

}

void deleteUser()
{

}

void editUserLogin()
{

}




