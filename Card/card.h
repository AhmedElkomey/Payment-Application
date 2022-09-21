#ifndef CARD_H
#define CARD_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#pragma warning(suppress : 4996)
#define _CRT_SECURE_NO_WARNINGS

typedef unsigned char uint8_t;
typedef unsigned int  uint32_t;

typedef enum EN_cardError_t
{
	CARD_OK, WRONG_NAME, WRONG_EXP_DATE, WRONG_PAN
}EN_cardError_t;


typedef struct ST_cardData_t
{
	uint8_t cardHolderName[25];
	uint8_t primaryAccountNumber[20];
	uint8_t cardExpirationDate[6];
	float cbalance;
}ST_cardData_t;

EN_cardError_t getCardHolderName(ST_cardData_t* cardData);
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData);
EN_cardError_t getCardPAN(ST_cardData_t* cardData);


#endif // !CARD_H
