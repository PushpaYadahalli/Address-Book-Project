#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {

    int i;
    FILE *fp;
    fp=fopen("Contact.csv","w");
    if(fp==0)
    {
        printf("file not present\n");
        return;
    }
  
    for (i = 0; i < addressBook->contactCount; i++)
    {
               fprintf(fp,"%s,%s,%s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone,
                addressBook->contacts[i].email);
    }
    printf("Contacts successfully saved to Contact.csv\n");
    fclose(fp);
}

void loadContactsFromFile(AddressBook *addressBook) {

    int i;
    FILE *fp1;
    fp1=fopen("Contact.csv","r");
    if(fp1==0)
    {
        printf("file not present\n");
        return;
    }
    addressBook->contactCount=0;
   
    while(fscanf(fp1,"%[^,],%[^,],%[^\n]\n", addressBook->contacts[addressBook->contactCount].name, addressBook->contacts[addressBook->contactCount].phone,
            addressBook->contacts[addressBook->contactCount].email)==3)
    {
            addressBook->contactCount++;
    }

    fclose(fp1);
}
