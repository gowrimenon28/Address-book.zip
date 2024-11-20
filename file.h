#ifndef FILE_H
#define FILE_H
#include<stdio.h>
#include "contact.h"

void saveContactsToFile(AddressBook *addressBook,FILE *fptr);
void loadContactsFromFile(AddressBook *addressBook,FILE *fptr);

#endif
