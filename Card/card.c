#pragma warning(suppress : 4996)
#pragma warning(suppress : 6031)
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_INSECURE_DEPRECATE(scanf_s)
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE

#include "card.h"


EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
	uint8_t name[50] = { '\0' };

	printf("please Enter Card Holder Name (between 20-25 characters):");
	fgets(name, sizeof(name), stdin);                       // get card holder name
	while ((getchar()) != '\n' && (getchar()) != EOF);				 // clear input buffer

	if ((strlen(name) > 25) || (strlen(name) < 20) || (name == NULL))    // check for name length
	{
		printf("length is %zd , size is %zd\n", strlen(name), sizeof(name));
		printf("wrong name\n");
		return WRONG_NAME;
	}
	else
	{
		strcpy_s(cardData->cardHolderName,sizeof((*cardData).cardHolderName), name);  // save name in card
		printf("welcome MR/MRS %s\n", cardData->cardHolderName);
		return CARD_OK;
	}
}

EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
	uint8_t expdate[6]  = { '\0' };
	uint8_t expmonth[6] = { '\0' };
	int exp_mon;

	printf("\n please Enter Expiration Date (in form of MM/YY): ");			  // get expiration date
	fgets(expdate, sizeof(expdate), stdin);
	//while ((getchar()) != '\n' && (getchar()) != EOF);						// clear input buffer
	sprintf(expmonth, "%.2s\n", expdate);                           // get first 2 element from string (expiration date)
	exp_mon = atoi(expmonth);								 // convert string into intger 

	if ((strlen(expdate) > 5) || (strlen(expdate) < 5) || (expdate == NULL) || (expdate[2] != '/' ) || (exp_mon > 12))     // check for format
	{
		printf("wrong format\n");
		return WRONG_EXP_DATE;
	}
	else
	{
		strcpy_s(cardData->cardExpirationDate, sizeof((*cardData).cardExpirationDate), expdate);  // save expiration date in card
		printf("Your expiration date is :%s\n", cardData->cardExpirationDate);
		return CARD_OK;
	}
}

EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
	uint8_t PAN[20] = { '\0' };		
	printf("please Enter your PAN: ");					                        	// get card PAN
	scanf("%s", &PAN);
	while ((getchar()) != '\n' && (getchar()) != EOF);                       // clear input buffer

	if ((strlen(PAN) > 19) || (strlen(PAN) < 16) || (PAN == NULL))               // check PAN length
	{
		printf("wrong PAN\n");
		return WRONG_PAN;
	}
	else
	{
		strcpy_s(cardData->primaryAccountNumber, sizeof((*cardData).primaryAccountNumber), PAN);   // Save PAN in card
		printf("OK\n");
		return CARD_OK;
	}
}
	