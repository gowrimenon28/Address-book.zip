#include "contact.h"
#include <string.h>
#include<stdio.h>
#include<stdlib.h>
//#include "populate.h"
/* Dummy contact data
static Contact dummyContacts[] = {
    {"John Doe", "1234567890", "john@example.com"},
    {"Alice Smith", "0987654321", "alice@example.com"},
    {"Bob Johnson", "1112223333", "bob@company.com"},
    {"Carol White", "4445556666", "carol@company.com"},
    {"David Brown", "7778889999", "david@example.com"},
    {"Eve Davis", "6665554444", "eve@example.com"},
    {"Frank Miller", "3334445555", "frank@example.com"},
    {"Grace Wilson", "2223334444", "grace@example.com"},
    {"Hannah Clark", "5556667777", "hannah@example.com"},
    {"Ian Lewis", "8889990000", "ian@example.com"}
};*/

/*void populateAddressBook(AddressBook *addressBook) {
    FILE *file = fopen("address_book.csv", "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file) && addressBook->contactCount < MAX_CONTACTS) {
        line[strcspn(line, "\n")] = 0;  
        char *token = strtok(line, ",");
        if (token == NULL) continue;

        strncpy(addressBook->contacts[addressBook->contactCount].name, token, sizeof(addressBook->contacts[addressBook->contactCount].name) - 1);
        token = strtok(NULL, ",");
        if (token == NULL) continue;

        strncpy(addressBook->contacts[addressBook->contactCount].phone, token, sizeof(addressBook->contacts[addressBook->contactCount].phone) - 1);
        token = strtok(NULL, ",");
        if (token == NULL) continue;

        strncpy(addressBook->contacts[addressBook->contactCount].email, token, sizeof(addressBook->contacts[addressBook->contactCount].email) - 1);
        addressBook->contactCount++;
    }

    fclose(file);
}*/
