
#include "userAuth.h"

bool compareUserDetails(user user1, user user2)
{
    if(strcmp(user1.username, user2.username) == 0 && strcmp(user1.password, user2.password) == 0) // Compares both user's login details to see if they match
    {
        printf("User matches!\n");
        return true; // If they do, the user's details are valid.
    }
    else
    {   
        printf("%s != %s, %s != %s.\n", user1.username, user2.username, user1.password, user2.password);
        return false; // If not, they differ so return false.
    }
};

bool parseLoginDetails(user loginAttempt)
{
    FILE* userFile;

    if((userFile = fopen("users.txt", "rb")) == NULL) // Error checking - unable to open file
    {
        outputError(5); // Outputs: "Error 5: File could not be opened."
    }
    else
    {
        printf("File opened successfully!");

        user blankUser = {"", "", ""}; // Blank user for reading a user into and comparing
        bool userDetailsFound = false; // Flag for tracking if the user exists in the file

        while(!feof(userFile) && userDetailsFound == false) // Loop through the users in the file until you find the current user or reach the end of the file
        {  
            fread(&blankUser, sizeof(user), 1, userFile);
            printf("%s %s %s", blankUser.userID, blankUser.username, blankUser.password);

            if(compareUserDetails(blankUser, loginAttempt))
            {
                userDetailsFound = true;
            }
        }

        if(userDetailsFound)
        {
            return true;
        }
        else
        {
            return false;
        }
        

        fclose(userFile);
    }

    return false;
};

void newLogin(void)
{
    user newLoginAttempt = { "", "", ""};
    int invalidLoginAttempt = 0; // Initialise counter to 0;
    bool validLogin = false;

    while(invalidLoginAttempt < 3 && validLogin == false)
    {
        printInstruction("Username: ");
        scanf("%s", &newLoginAttempt.username);

        printInstruction("Password: ");
        scanf("%s", &newLoginAttempt.password);

        // addUser(newLoginAttempt);

        printInstruction("Thank you!\n");

        if(parseLoginDetails(newLoginAttempt))
        {
            printInstruction("You have successfully logged in.");
            validLogin = true;
            continue;
        }
        else
        {
            invalidLoginAttempt++; // Increment counter for number of invalid login attempts
            printError("Invalid Login Details, you have %d tries remaining.\n", (3 - invalidLoginAttempt)); // Need number of attempts, so not using outputError()
        }
    }

    if(validLogin)
    {
        printf("Welcome %s\n", newLoginAttempt.username);
    }
    else
    {
        outputError(3); // Outputs error message for too many invalid login attempts
        exit(0); // Exits the program
    }
}