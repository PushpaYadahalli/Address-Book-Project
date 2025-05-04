#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook, int sortCriteria)
{
    // Sort contacts based on the chosen criteria
    int i, j;
    Contact temp;
    switch (sortCriteria)
    {
    case 1:

        for (i = 0; i < addressBook->contactCount - 1; i++)
        {
            for (j = 0; j < addressBook->contactCount - 1 - i; j++)
            {
                if (strcmp(addressBook->contacts[j].name,addressBook->contacts[j + 1].name) > 0)
                {
                    temp=addressBook->contacts[j];
                    addressBook->contacts[j]=addressBook->contacts[j + 1];
                    addressBook->contacts[j + 1]=temp;
                }
            }
        }
        break;

    case 2:

        for (i = 0; i < addressBook->contactCount - 1; i++)
        {
            for (j = 0; j < addressBook->contactCount - 1 - i; j++)
            {
                if (strcmp(addressBook->contacts[j].phone,addressBook->contacts[j + 1].phone)>0)
                {
                    temp=addressBook->contacts[j];
                    addressBook->contacts[j]=addressBook->contacts[j + 1];
                    addressBook->contacts[j + 1]=temp;
                }
            }
        }
        break;

    case 3:

        for (i = 0; i < addressBook->contactCount - 1; i++)
        {
            for (j = 0; j < addressBook->contactCount - 1 - i; j++)
            {
                if (strcmp(addressBook->contacts[j].email,addressBook->contacts[j + 1].email)> 0)
                {
                    temp=addressBook->contacts[j];
                    addressBook->contacts[j]=addressBook->contacts[j + 1];
                    addressBook->contacts[j + 1]=temp;

                }
            }
        }
        break;

    default:
        printf("Invalid choice.\n");
    }
          
    printf("Name\t   Phone number\t  email Id\t\n\n");
    for (i = 0; i < addressBook->contactCount; i++)
    {
               printf("%s %s %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone,
                addressBook->contacts[i].email);
    }
}

void initialize(AddressBook *addressBook)
{
    addressBook->contactCount = 0;
    //populateAddressBook(addressBook);

    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook)
{
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS);              // Exit the program
}

// function to create and add new_contact
void createContact(AddressBook *addressBook)
{
    char new_name[50];
    char new_phone[20];
    char new_email[50];

    // if it is valid continue next reading phone else read the same
    do
    {
        printf("Enter the name you want to add:");
        scanf(" %[^\n]", new_name);
    } while (isvalidname(new_name));

    // if it is valid continue next reading email else read the same
    int phone;
    do
    {
        printf("Enter the phone number you want to add:");
        scanf(" %s", new_phone);
        phone = isuniqphone(addressBook, new_phone);
        if (phone != 0)
        {
            printf("The phone number is already present in addressBook\n");
        }
    } while (isvalidphone(new_phone) || phone);

    // if it is valid continue next else read the same
    int email;
    do
    {
        printf("Enter the new_email you want to add:");
        scanf(" %s", new_email);
        email = isuniqmail(addressBook, new_email);
        if (email != 0)
        {
            printf("The email is already present in addressBook\n");
        }
    } while (isvalidmail(new_email) || email);

        // Add the new contact to the address book
        strcpy(addressBook->contacts[addressBook->contactCount].name, new_name);
        strcpy(addressBook->contacts[addressBook->contactCount].phone, new_phone);
        strcpy(addressBook->contacts[addressBook->contactCount].email, new_email);
        addressBook->contactCount++;
        printf("Contact added successfully.\n");
}
int isvalidname(char *added_name)
{
    int i;
    for (i = 0;added_name[i]; i++)
    {
        if (isalpha(added_name[i]) || added_name[i] == ' ')
            continue;
        else
        {
            printf("Invalid name\n");
            return 1; // read again name
        }
    }
    return 0; // dont read again name
}
int isvalidphone(char *new_phone)
{
    int i,f=0;
    for (i = 0; i < strlen(new_phone); i++)
    {
        if ((strlen(new_phone) == 10 && strlen(new_phone) <= 10) && (isdigit(new_phone[i])))
            continue;
        else
            printf("Invalid phone number\n");
        return 1; // read again phone no.
    }
    return 0; // dont read again phone no.
}

int isvalidmail(char *new_email)
{
    //length of a new_email
    int l,i; 
    l= strlen(new_email);
    if (strlen(new_email) == 0)
    {
        printf("Email cannot be empty.\n");
        return 1; // read again email
    }

    int c1 = 0, c2 = 0, f1 = 0, f2 = 0;
    for (i = 0; new_email[i]; i++)
    {
        if (new_email[i] == '@') //@
        {
            c1++;
            f1 = i; // save '@' position in another veriable
        }
        else if (new_email[i] == '.') // dot
        {
            c2++;
            f2 = i; // save '.' position in another veriable
        } 
        else
        {
         continue; // It is Alphabet continue next checking
        }         
    }
    
    /* f1==0 --> @ should not come 1st
       f2==0 --> '.' should not come 1st
       c1 > 1 || c2 > 1 --> count should be 1 for '@' and '.'
       f1 > f2 ---> f1 & f2 for position of '@' should be less than '.'
       f1-f2==1 ---> '.' should not come immediately after '@'
       f1==l-1 ---> @ should not come end
       f2==l-1 --> '.' should not come end
    */
    if (c1 > 1 || c2 > 1 || f1 > f2 || f1==0 || f2==0||f2-f1==1||f1==l-1||f2==l-1)
    {
        printf("Invalid email number\n");
        return 1; // read again email
    }
    else
        return 0; // dont read email again
}

// check or search In addressBook name and Entered name same or not
int isuniqname(AddressBook *addressBook, char *new_name)
{
    int i, found = 0; // both are not same
    for (i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(addressBook->contacts[i].name, new_name) == 0) // both same
        {
            printf("%s %s %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone,
                   addressBook->contacts[i].email);
            found++; // both are same
        }
    }
    return found;
}

// check or search In addressBook phone number and Entered phone number same or not
int isuniqphone(AddressBook *addressBook, char *new_phone)
{
    int i, found = 0; // both are not same
    for (i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(addressBook->contacts[i].phone, new_phone) == 0) // both same
        {
            printf("%s %s %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone,
                   addressBook->contacts[i].email);
            found = 1; // both are same
        }
    }
    return found;
}

// check or search In addressBook mail and Entered mail same or not
int isuniqmail(AddressBook *addressBook, char *new_email)
{
    int i, found = 0; // both are not same
    for (i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(addressBook->contacts[i].email, new_email) == 0) // both same
        {
            printf("%s %s %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone,
                   addressBook->contacts[i].email);
            found = 1; // both are same
        }
    }
    return found;
}

void searchContact(AddressBook *addressBook)
{
    while (1)
    {
        printf("What you want to search\n 1.search by name\n 2.search by phone\n 3.search by email\n");
        int choice, found = 0;
        char a;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        // search by name
        case 1:

            char search_name[50];
            int i;
            do
            {
                printf("Enter the name you want to search: ");
                scanf(" %[^\n]", search_name);
            } while (isvalidname(search_name)); // if it is valid continue next else read the same

            for (i = 0; i < addressBook->contactCount; i++)
            {
                // check main string(adressBook) substring(search name) present or not
                if (strstr(addressBook->contacts[i].name, search_name))
                {
                    // print the all substrings presents in addressBook
                    printf("%s %s %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone,
                           addressBook->contacts[i].email);
                    found = 1;
                }
            }
            if (found == 0)
                printf("Entered name is not present in addressbook\n");
            break;

        // search by phone number
        case 2:
            char search_phone[20];
            do
            {
                printf("Enter the phone you want to search: ");
                scanf(" %[^\n]", search_phone);
            } while (isvalidphone(search_phone)); // if it is valid continue next else read the same

            // check substring present or not
            for (i = 0; i < addressBook->contactCount; i++)
            {
                // check main string(adressBook) substring(phone number) present or not
                if (strstr(addressBook->contacts[i].phone, search_phone))
                {
                    // print the all substrings presents in addressBook
                    printf("%s %s %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone,
                           addressBook->contacts[i].email);
                    found = 1;
                }
            }
            if (found == 0)
            {
                printf("Entered name is not present in addressbook\n");
            }
            break;

        // search by email
        case 3:
            char search_email[50];
            do
            {
                printf("Enter the email you want to search: ");
                scanf(" %[^\n]", search_email);
            } while (isvalidmail(search_email)); // if it is valid continue next else read the same

            for (i = 0; i < addressBook->contactCount; i++)
            {
                // check main string(adressBook) substring(email) present or not
                if (strstr(addressBook->contacts[i].email, search_email))
                {
                    // print the all substrings presents in addressBook
                    printf("%s %s %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone,
                           addressBook->contacts[i].email);
                    found = 1;
                }
            }
            if (found == 0)
                printf("Entered name is not present in addressbook\n");
            break;

        default:
            printf("Wrong choice\n");
        }
        printf("you want to search again press Y/N:");
        scanf(" %c", &a);
        if (a == 'Y' || a == 'y')
            continue;
        else
            return;
    }
}

void editContact(AddressBook *addressBook)
{
    while (1)
    {
        printf("What you want to edit\n 1.edit by name\n 2.edit by phone\n 3.edit by email\n");
        int choice;
        char a;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        // edit by name
        case 1:
            // search name
            char search_name[50];
            char search_phone[20];
            int i, j;
            do
            {
                // Read the name you want to edit
                printf("Enter the name you want to edit: ");
                scanf(" %[^\n]", search_name);
            } while (isvalidname(search_name)); // if it is valid continue next else read the same

            // search entered name in addressBook present or not
            int found = isuniqname(addressBook, search_name);

            if(found==1) // unique name
            {
                printf("Printed details Successfully\n");
            }
            else if(found > 1) // more than one name search phone number also
            {
                printf("Printed details Successfully\n");
                do
                {
                    printf("Enter the phone number you want to edit name:");
                    scanf(" %[^\n]", search_phone);
                } while (isvalidphone(search_phone));
            }
            else
            {
                printf("Entered name not present in addressBook\n");
                // come out of the switch case (next step->if you want to read again read it else it will go back to menu)
                break;
            }

            char new_name[50];
            do
            {
                // //Read the name you want to added
                printf("Enter the new name: ");
                scanf(" %[^\n]", new_name);
            } while (isvalidname(new_name)); // if it is valid continue next else read the same

            // edit name
            if (found == 1) // my name is in addressBook only 1
            {
                for (i = 0; i < addressBook->contactCount; i++)
                {
                    // compaire editing name(search_name) and addressBook name
                    if (strcmp(addressBook->contacts[i].name, search_name) == 0)
                    {
                        // found replace new_name
                        strcpy(addressBook->contacts[i].name, new_name);
                        printf("Edited the name successfully\n");
                    }
                }
            }
            else // my name is in addressBook more than 1
            {
                for (i = 0; i < addressBook->contactCount; i++)
                {
                    // compaire editing name(search_name) and addressBook name
                    if (strcmp(addressBook->contacts[i].name, search_name) == 0)
                    {
                        // check phone no.and name matching or not
                        if (strcmp(addressBook->contacts[i].phone, search_phone) == 0)
                        {
                            // found replace new_name
                            strcpy(addressBook->contacts[i].name, new_name);
                            printf("Edited the name successfully\n");
                        }
                    }
                }
            }
            // come out of the switch case (next step->if you want to read again read it else it will go back to menu)
            break;

        // edit by phone number
        case 2:

            do
            {
                // Read the phone you want to edit
                printf("Enter the phone you want to edit: ");
                scanf(" %[^\n]", search_phone);
            } while (isvalidphone(search_phone)); // if it is valid continue next else read the same

            // search entered phone in addressBook present or not
            found = isuniqphone(addressBook, search_phone);

            if (found)
            {
                printf("Printed details Successfully\n");
            }
            else
            {
                printf("Entered phone number not present in addressBook\n");
                // come out of the switch case (next step->if you want to read again read it else it will go back to menu)
                break;
            }

            char new_phone[50];
            do
            {
                // //Read the phone number you want to added
                printf("Enter the new phone number: ");
                scanf(" %[^\n]", new_phone);
            } while (isvalidphone(new_phone)); // if it is valid continue next else read the same

            // edit phone
            for (i = 0; i < addressBook->contactCount; i++)
            {
                // compaire editing phone(search_phone) and addressBook phone number
                if (strcmp(addressBook->contacts[i].phone, search_phone) == 0)
                {
                    // found replace new_name
                    strcpy(addressBook->contacts[i].phone, new_phone);
                    printf("Edited the phone successfully\n");
                }
            }

            // come out of the switch case (next step->if you want to read again read it else it will go back to menu)
            break;

            // edit by email
        case 3:
            // search email
            char search_email[50];
            do
            {
                // Read the email you want to edit
                printf("Enter the email you want to edit: ");
                scanf(" %[^\n]", search_email);
            } while (isvalidmail(search_email)); // if it is valid continue next else read the same

            // search entered email in addressBook present or not
            found = isuniqmail(addressBook, search_email);

            if (found)
            {
                printf("Printed details Successfully\n");
            }
            else
            {
                printf("Entered email not present in addressBook\n");
                // come out of the switch case (next step->if you want to read again read it else it will go back to menu)
                break;
            }

            char new_email[50];
            do
            {
                // //Read the email you want to added
                printf("Enter the new email: ");
                scanf(" %[^\n]", new_email);
            } while (isvalidmail(new_email)); // if it is valid continue next else read the same

            // edit email
            for (i = 0; i < addressBook->contactCount; i++)
            {
                // compaire editing email(search_email) and addressBook email
                if (strcmp(addressBook->contacts[i].email, search_email) == 0)
                {
                    // found replace new_name
                    strcpy(addressBook->contacts[i].email, new_email);
                    printf("Edited the email successfully\n");
                }
            }

            // come out of the switch case (next step->if you want to read again read it else it will go back to menu)
            break;
        }
        // if you want to edit next continue
        printf("you want to continue again press Y/N:");
        scanf(" %c", &a);
        if (a == 'Y' || a == 'y')
            continue;
        else
            return;
    }
}

void deleteContact(AddressBook *addressBook)
{
while(1)
{
    char a;
    printf("Do you want to delete press Y/N:");
    scanf(" %c",&a);
    if(a == 'Y')
    {
        while (1)
        {
            printf("What you want to delete\n 1.delete by name\n 2.delete by phone\n 3.delete by email\n");
            int choice, found = 0;
            //char a;
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice)
            {
            // delete by name
            case 1:
                char search_name[50];
                char search_phone[20];
                int i, j;
                do
                {
                    // Read the name you want to delete
                    printf("Enter the name you want to delete: ");
                    scanf(" %[^\n]", search_name);
                } while (isvalidname(search_name)); // if it is valid continue next else read the same

                // search entered name in addressBook present or not
                found = isuniqname(addressBook, search_name);

                if (found == 1)
                {
                    printf("Printed details Successfully\n");
                }
                else if (found > 1)
                {
                    printf("Printed details Successfully\n");
                    // Read the phone you want to delete
                    do
                    {
                        printf("Enter the phone you want to delete name: ");
                        scanf(" %[^\n]", search_phone);
                    } while (isvalidphone(search_phone)); // if it is valid continue next else read the same
                }
                else
                {
                    printf("Entered name not present in addressBook\n");
                    // come out of the switch case
                    break;
                }

                // delete name
                if (found == 1) // my name is in addressBook only 1
                {
                    for (i = 0; i < addressBook->contactCount; i++)
                    {
                        // compare deleting name(search_name) and addressBook name
                        if (strcmp(addressBook->contacts[i].name, search_name) == 0)
                        {
                            for (j = i; j < addressBook->contactCount - 1; j++)
                            {
                                // found replace new_name
                                addressBook->contacts[j] = addressBook->contacts[j + 1];
                            }
                            addressBook->contactCount--;
                            printf("deleted the name successfully\n");
                            break;
                        }
                    }
                }
                else
                {
                    for (i = 0; i < addressBook->contactCount; i++)
                    {
                        // compare deleting name(search_name) and addressBook name
                        if (strcmp(addressBook->contacts[i].name, search_name) == 0)
                        {
                            // more than two name check phone number also
                            if (strcmp(addressBook->contacts[i].phone, search_phone) == 0)
                            {

                                for (j = i; j < addressBook->contactCount - 1; j++)
                                {
                                    addressBook->contacts[j] = addressBook->contacts[j + 1];
                                }
                                addressBook->contactCount--;
                                printf("deleted the name successfully\n");
                            }
                        }
                    }
                }
                // come out of the switch case
                break;

            case 2:

                do
                {
                    // Read the phone you want to delete
                    printf("Enter the phone number you want to delete: ");
                    scanf(" %[^\n]", search_phone);
                } while (isvalidphone(search_phone)); // if it is valid continue next else read the same

                // search entered phone in addressBook present or not
                found = isuniqphone(addressBook, search_phone);

                if (found)
                {
                    printf("Printed details Successfully\n");
                }
                else
                {
                    printf("Entered phone not present in addressBook\n");
                    // come out of the switch case
                    break;
                }
                // delete phone
                for (i = 0; i < addressBook->contactCount; i++)
                {
                    // compare deleting phone(search_phone) and addressBook phone
                    if (strcmp(addressBook->contacts[i].phone, search_phone) == 0)
                    {
                        for (j = i; j < addressBook->contactCount - 1; j++)
                        {
                            addressBook->contacts[j] = addressBook->contacts[j + 1];
                        }
                        addressBook->contactCount--;
                        printf("deleted the phone number successfully\n");
                    }
                }
                // come out of the switch case
                break;

            case 3:

                char search_email[50];
                do
                {
                    // Read the email you want to delete
                    printf("Enter the email you want to delete: ");
                    scanf(" %[^\n]", search_email);
                } while (isvalidmail(search_email)); // if it is valid continue next else read the same

                // search entered phone in addressBook present or not
                found = isuniqmail(addressBook, search_email);

                if (found)
                {
                    printf("Printed details Successfully\n");
                }
                else
                {
                    printf("Entered email not present in addressBook\n");
                    // come out of the switch case
                    break;
                }

                // delete phone
                for (i = 0; i < addressBook->contactCount; i++)
                {
                    // compare deleting phone(search_phone) and addressBook phone
                    if (strcmp(addressBook->contacts[i].email, search_email) == 0)
                    {
                        for (j = i; j < addressBook->contactCount - 1; j++)
                        {
                            addressBook->contacts[j] = addressBook->contacts[j + 1];
                        }
                        
                        addressBook->contactCount--;
                        printf("deleted the email successfully\n");
                        break;
                    }
                }
                // come out of the switch case
                break;
            }
            printf("you want to continue again press Y/N:");
            scanf(" %c", &a);
            if (a == 'Y' || a == 'y')
                continue;
            else
                return;
        }
    }   
    else
    return;
}
}