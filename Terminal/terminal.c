#define _CRT_SECURE_NO_WARNINGS
//#define _CRT_SECURE_NO_DEPRECATE  
//#define _CRT_NONSTDC_NO_DEPRECATE
#include "terminal.h"


int day, month, year;


EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)
{
	uint8_t today[12] = { '\0' };
	time_t current_date;
	time(&current_date);
	struct tm* local = localtime(&current_date);
	day = local->tm_mday;
	month = local->tm_mon + 1;
	year = local->tm_year + 1900;
	sprintf_s(today,sizeof(today), "%02d/%02d/%d\n", day, month, year);     // save current date

	return TERMINAL_OK;

}

EN_terminalError_t isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData)
{
	uint8_t expmonth[10] = { '\0' };
	uint8_t expyear[10] = { '\0' };
    int exp_mon, exp_year;

	sprintf_s(expmonth,sizeof(expmonth), "%.2s\n", (*cardData).cardExpirationDate);      // get first 2 element of string 
	sprintf_s(expyear, sizeof(expyear), "%.2s\n", &(*cardData).cardExpirationDate[3]);   // get from 3rd element to (+2 element) 5th
	exp_mon  = atoi(expmonth);		
	exp_year = atoi(expyear);
	printf("card exp date is:%s\n", cardData->cardExpirationDate);

	if ((exp_mon < month && exp_year <= (year-2000)) || (exp_year < year-2000))
	{

		printf("your card is expired\n");
		return EXPIRED_CARD;
	}
	else
	{
		printf("your card is function\n\n");
		return TERMINAL_OK;
	}
}

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData)
{
	float TransAmount;
	printf("please enter the amount of transaction: \n");
	scanf_s("%f", &TransAmount);
	while ((getchar()) != '\n' && (getchar()) != EOF);				 // clear input buffer

	if (TransAmount <= 0) 
	{
		printf("yor trasaction is too low\n");
		return INVALID_AMOUNT;
	}
	else
	{
		(*termData).transAmount = TransAmount;
		printf("your amount is %.2f\n", termData->transAmount);
		return TERMINAL_OK;                                
	}
}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)
{
	if ((*termData).maxTransAmount >= (*termData).transAmount) 
	{
		printf("your amount accepted\n");
		return TERMINAL_OK;
	}
	else {
		printf("your amount exceed the maximum\n");
		return EXCEED_MAX_AMOUNT;
	}
 }

EN_terminalError_t setMaxAmount(ST_terminalData_t* termData)
{
	float MaxAmount;
	printf("Set Maximum Amount: ");
	scanf_s("%f", &MaxAmount);
	while ((getchar()) != '\n' && (getchar()) != EOF);				 // clear input buffer
	if (MaxAmount <= 0)
	{
		printf("max Amount is too low\n");
		return INVALID_MAX_AMOUNT;
	}
	else
	{
		(*termData).maxTransAmount = MaxAmount;
		printf("The max Amount is:%.2f\n", termData->maxTransAmount);
		return TERMINAL_OK;
	}
}
