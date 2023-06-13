#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "UserInformation.h"



void getInfo(struct CustomerInfo* info) {

	do {
		printf("Enter your first name: ");
		fgets(info->firstName, sizeof(info->firstName), stdin);

		info->firstName[strcspn(info->firstName, "\n")] = '\0';
	} while (verifyName(info->firstName) == 0);

	do {
		printf("Enter your last name: ");
		fgets(info->lastName, sizeof(info->lastName), stdin);

		info->lastName[strcspn(info->lastName, "\n")] = '\0';
	} while (verifyName(info->lastName) == 0);

	do {
		printf("Enter your street address: ");
		fgets(info->streetAddress, sizeof(info->streetAddress), stdin);

		info->streetAddress[strcspn(info->streetAddress, "\n")] = '\0';
	} while (verifyAddress(info->streetAddress) == 0);

	do {
		printf("Enter your city: ");
		fgets(info->city, sizeof(info->city), stdin);

		info->city[strcspn(info->city, "\n")] = '\0';
	} while (verifyName(info->city) == 0);

	do {
		printf("Enter your province: ");
		fgets(info->province, sizeof(info->province), stdin);

		info->province[strcspn(info->province, "\n")] = '\0';
	} while (verifyProvince(info->province) == 0);

	do {
		printf("Enter your postal code: ");
		fgets(info->postalCode, sizeof(info->postalCode), stdin);

		info->postalCode[strcspn(info->postalCode, "\n")] = '\0';
	} while (verifyPostalCode(info->postalCode) == 0);

}

	

int verifyName(char* name) {
	int Valid = 1;
	int keepGoing = 1;

	if (name[0] == '\0' || name[0] == '\n') {
		printf("Invalid entry: ");
		Valid = 0;  
		
	}

	for (int i = 0; name[i] != '\0'&& keepGoing; i++) {
		if (!isalpha(name[i]) && name[i] != ' ') {
			printf("Invalid entry: ");
			Valid = 0;  
			keepGoing = 0;
		}
	}
	return Valid;
}

int verifyAddress(char* address) {
	int Valid = 1;
	int keepGoing = 1;

	if (address[0] == '\0' || address[0] == '\n') {
		printf("Invalid entry.");
		Valid = 0;  

	}
	return Valid;

}

int verifyProvince(char* province) {
	int Valid = 1;
	int keepGoing = 1;
	int provinceLength;

	if (province[0] == '\0' || province[0] == '\n') {
		printf("Invalid entry.");
		Valid = 0; 

	}

	provinceLength = strlen(province);
	if (provinceLength != 2) {
		printf("Invalid entry.Needs to be 2 characters. ");
		Valid = 0;
		keepGoing = 0;
	}

	for (int i = 0; province[i] != '\0' && keepGoing; i++) {
		if (!isalpha(province[i])) {
			printf("Invalid entry.");
			Valid = 0;  
			keepGoing = 0;
		}
	}
	return Valid;
}

int verifyPostalCode(char* postalCode) {
	int Valid = 1;
	int keepGoing = 1;
	int i;

	if (postalCode[0] == '\0' || postalCode[0] == '\n') {
		printf("Invalid entry.");
		Valid = 0;  
	}
	for (i = 0; i < strlen(postalCode) && keepGoing; i++) {
		if (i == 3) {
			if (postalCode[i] != ' ') {
				Valid = 0;
				keepGoing = 0;
				printf("Invalid entry: ");
			}
		}
		else if (i < 3 || i > 3) {
			if (!isalnum(postalCode[i])) {
				Valid = 0;
				keepGoing = 0;
				printf("Invalid entry: ");
			}
		}
		else if (i == 2) {
			if (!isalpha(postalCode[i])) {
				Valid = 0;
				keepGoing = 0;
				printf("Invalid entry: ");
			}
		}
	}

	return Valid;
}

void display(struct CustomerInfo* info) {
	printf("\nYou entered:\n%s %s\n%s,\n%s, %s,\n", info->firstName, info->lastName, info->streetAddress, info->city, info->province);
	
	for (int i = 0; info->postalCode[i] != '\0'; i++) {
		info->postalCode[i] = toupper(info->postalCode[i]);
	}

	printf("%s", info->postalCode);
}


int main(void) {
	struct CustomerInfo Info;
	getInfo(&Info);
	display(&Info);
	

	return 0;
}