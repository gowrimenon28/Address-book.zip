#include "contact.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Load contacts from the CSV file into the address book
void populateAddressBook(AddressBook *addressBook) {
    FILE *file = fopen("address_book.csv", "r");
    if (!file) {
        perror("Failed to open file for reading");
        return;
    }

    // Reset the contact count to zero when repopulating the address book
    addressBook->contactCount = 0;
    
    char line[256];
    if(fgets(line,sizeof(line),file)){
        scanf(line,"#%d#",&addressBook->contactCount);
    }
    while(fgets(line, sizeof(line), file) && addressBook->contactCount < MAX_CONTACTS) {
        line[strcspn(line, "\n")] = '\0';  // Remove newline character
        char *name = strtok(line, ",");
        char *phone = strtok(NULL, ",");
        char *email = strtok(NULL, ",");
        
        if (name && phone && email) {  // Ensure all tokens are valid
            strncpy(addressBook->contacts[addressBook->contactCount].name, name, sizeof(addressBook->contacts[addressBook->contactCount].name) - 1);
            strncpy(addressBook->contacts[addressBook->contactCount].phone, phone, sizeof(addressBook->contacts[addressBook->contactCount].phone) - 1);
            strncpy(addressBook->contacts[addressBook->contactCount].email, email, sizeof(addressBook->contacts[addressBook->contactCount].email) - 1);
            addressBook->contactCount++;
        }
    }

    fclose(file);
}


void saveContactsToFile(const AddressBook *addressBook, FILE *fptr) {
    if (fptr == NULL) {
        printf("File pointer is null.\n");
        return;
    }
    fprintf(fptr,"#%d#\n",addressBook->contactCount);
    for (int i = 0; i < addressBook->contactCount; i++) {
        fprintf(fptr, "%s,%s,%s\n",
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email);
    }
    printf("Contacts saved to file successfully.\n");
}