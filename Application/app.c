#pragma warning(suppress : 4047)
#pragma warning(suppress : 4024)


#include "app.h"


void appStart(void)
{
	while (TRUE) {
		// ======================================   starting app   =======================================

		printf("\t\t\t\t*** welcome to our Payment Application ***\n");
		printf("press enter to continue...");
		while ((getchar()) != '\n');
		system("cls");

	//----------------------------------------- card section ------------------------------------------
		if (getCardHolderName(&cardData) == WRONG_NAME)
		{
			char char_x;
			printf("press (x) to close or (y) to  try again\n");
			char_x = getchar();
			if (char_x == 'x')
			{
				break;
			}
			else if (char_x == 'y')
			{
				continue;
			}
			break;
		}

		if (getCardExpiryDate(&cardData) == WRONG_EXP_DATE)
		{	
			char char_x = getchar();
			printf("press (x) to close or (y) to  try again\n");
			if (char_x == 'x')
			{
				break;
			}
			else if (char_x == 'y')
			{
				continue;
			}
			break; 		
		}

		if (getCardPAN(&cardData) == WRONG_PAN)
		{
			printf("press (x) to close or (y) to  try again\n");
			char char_x = getchar();
			if (char_x == 'x')
			{
				break;
			}
			else if (char_x == 'y')
			{
				continue;
			}
			break;
		}
		//---------------------------------------- terminal section ------------------------------------------
		getTransactionDate(&termData);

		if (isCardExpired(&cardData, &termData) == EXPIRED_CARD)
		{
			printf("press (x) to close or (y) to  try again\n");
			char char_x = getchar();
			if (char_x == 'x')
			{
				break;
			}
			else if (char_x == 'y')
			{
				continue;
			}
			break;
		}

		if (setMaxAmount(&termData) == INVALID_MAX_AMOUNT)
		{
			printf("press (x) to close or (y) to  try again\n");
			char char_x = getchar();
			if (char_x == 'x')
			{
				break;
			}
			else if (char_x == 'y')
			{
				continue;
			}
			break;
		}

		if (getTransactionAmount(&termData) == INVALID_AMOUNT)
		{
			printf("press (x) to close or (y) to  try again\n");
			char char_x = getchar();
			if (char_x == 'x')
			{
				break;
			}
			else if (char_x == 'y')
			{
				continue;
			}
			break;
		}

		if (isBelowMaxAmount(&termData) == EXCEED_MAX_AMOUNT)
		{
			printf("press (x) to close or (y) to  try again\n");
			char char_x = getchar();
			if (char_x == 'x')
			{
				break;
			}
			else if (char_x == 'y')
			{
				continue;
			}
			break;
		}

		//---------------------------------------- server section ------------------------------------------

		// check for account validation *
		if (isValidAccount(&cardData) == ACCOUNT_NOT_FOUND)
		{
			printf("press (x) to close or (y) to  try again\n");
			char char_x = getchar();
			if (char_x == 'x')
			{
				break;
			}
			else if (char_x == 'y')
			{
				continue;
			}
			break;
		}

		if (isBlockedAccount(Acc_dB) == DECLINED_STOLEN_CARD)
		{
			printf("press (x) to close or (y) to  try again\n");
			char char_x = getchar();
			if (char_x == 'x')
			{
				break;
			}
			else if (char_x == 'y')
			{
				continue;
			}
			break;
		}

		// check for amount availablity *
		if (isAmountAvailable(&termData, &cardData) == LOW_BALANCE)
		{
			printf("press (x) to close or (y) to  try again\n");
			char char_x = getchar();
			if (char_x == 'x')
			{
				break;
			}
			else if (char_x == 'y')
			{
				continue;
			}
			break;
		}

		//saving transaction *
		if (saveTransaction(&transData, &termData, &cardData) == SAVING_FAILED)
		{
			printf("press (x) to close or (y) to  try again\n");
			char char_x = getchar();
			if (char_x == 'x')
			{
				break;
			}
			else if (char_x == 'y')
			{
				continue;
			}
		}

		// get transaction data
		if (getTransaction(&transData->transactionSequenceNumber, &transData, Trans_dB) == TRANSACTION_NOT_FOUND)
		{
			printf("press (x) to close or (y) to  try again\n");
			char char_x = getchar();
			if (char_x == 'x')
			{
				break;
			}
			else if (char_x == 'y')
			{
				continue;
			}
		}

		//recive transaction
		recieveTransactionData(&transData);



		// Exit
		while ((getchar()) != '\n');
		printf("press (x) to close or (y) to  try again\n");
		char char_x = getchar();
		if (char_x == 'x')
		{
			break;
		}
		else if (char_x == 'y')
		{
			continue;
		}
	}

	printf("-------> program out <------- \n");
	

}
