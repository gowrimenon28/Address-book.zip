#include "contact.h"
#include <stdio.h>
#include<stdlib.h>

void displayMenu() {
    printf("\nAddress Book Menu:\n");
    printf("1. List All Contacts\n");
    printf("2. Add New Contact\n");
    printf("3. Search For Contact\n");
    printf("4. Edit Contact\n");
    printf("5. Delete Contact\n");
    printf("6. Save Contacts\n");
    printf("7. Exit Program\n");
    printf("Enter your choice: ");
}

void performAction(int choice, AddressBook *addressBook,FILE **fptr) {
    switch (choice) {
        case 1:
            listContacts(addressBook);
            break;
        case 2:
            createContact(addressBook,*fptr);
            break;
        case 3:
            searchContact(addressBook);
            break;
        case 4:
            editContact(addressBook,*fptr);
            break;
        case 5:
            deleteContact(addressBook,*fptr);
            break;
        case 6:
            if (*fptr) {  // Close the existing file if open
                fclose(*fptr);
            }
            *fptr = fopen("address_book.csv", "w");
            if (*fptr) {
                saveContactsToFile(addressBook, *fptr);
                fclose(*fptr);
                printf("current contacts saved.\n");
                populateAddressBook(addressBook);
                listContacts(addressBook);
            } else {
                printf("Failed to open file for writing.\n");
            }
            break;
        case 7:
            printf("Exiting program.\n");
            if (*fptr) {
                fclose(*fptr);
            }
            exit(0);
            break;
        default:
            printf("Invalid option. Please try again.\n");
    }
}

int main() {
    AddressBook addressBook;
    FILE *fptr = NULL;
    
    populateAddressBook(&addressBook); // Load contacts from the file
    
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // consume the newline character after the choice input
        
        performAction(choice, &addressBook, &fptr);
    } while (choice != 7);
    
    return 0;
}