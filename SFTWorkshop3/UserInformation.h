#pragma once
#ifndef MATHFUNCS_H
#define MATHFUNCS_H
#define MAX_LENGTH 100

struct CustomerInfo {
	char firstName[MAX_LENGTH];
	char lastName[MAX_LENGTH];
	char streetAddress[MAX_LENGTH];
	char city[MAX_LENGTH];
	char province[MAX_LENGTH];
	char postalCode[MAX_LENGTH];
};

void getInfo(struct CustomerInfo* info);
int verifyPostalCode(char* pcode);
int verifyName(char* name);
int verifyAddress(char* address);
int verifyProvince(char* province);
int verifyPostalCode(char* postalCode);
void display(struct CustomerInfo* info);

#endif
