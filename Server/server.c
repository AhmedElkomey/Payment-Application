#include "server.h"

volatile uint32_t i;
static volatile int trans_seq = 0;          // save to data segment 
uint8_t TRANS_ERROR;

ST_cardData_t* cardData;
ST_terminalData_t* termData;
ST_transaction_t* transData;
ST_accountsDB_t* accountRefrence;

 ST_accountsDB_t Acc_dB[255] = {       {104550.0, RUNNING, "2384605505296168"},
									   {2000.0,   RUNNING, "5974923674999820"},
									   {650.0,    BLOCKED, "0223189135404046"},
									   {66300.0,  RUNNING, "4201818270026705"},
									   {1450.0,   RUNNING, "2370512053978252"},
									   {500000.0, RUNNING, "3461958484345322"},
									   {70450.0,  BLOCKED, "2964877632413184"},
};
 ST_transaction_t Trans_dB[255] = {0};

EN_transState_t recieveTransactionData(ST_transaction_t* transData)
{
	if (TRANS_ERROR == DECLINED_STOLEN_CARD)
	{
		printf("Declined stolen card\n");
		Trans_dB[trans_seq].transState = DECLINED_STOLEN_CARD;
		return DECLINED_STOLEN_CARD;
	}
	else if (TRANS_ERROR == DECLINED_INSUFFECIENT_FUND)
	{
		printf("Declined insuffecuent card\n");
		Trans_dB[trans_seq].transState = DECLINED_INSUFFECIENT_FUND;
		return DECLINED_INSUFFECIENT_FUND;
	}
	else if (TRANS_ERROR == INTERNAL_SERVER_ERROR)
	{
		printf("server error\n");
		Trans_dB[trans_seq].transState = INTERNAL_SERVER_ERROR;
		return INTERNAL_SERVER_ERROR;
	}
	else {
		printf("Transaction *APPROVE*\n");
		Trans_dB[trans_seq].transState = APPROVED;
		return APPROVED;
	}
}

EN_serverError_t isValidAccount(ST_cardData_t* cardData)
{
	for (i = 0; i < 7 /*size*/; i++)
	{
		int cmp = strcmp(cardData->primaryAccountNumber, (char*)Acc_dB[i].primaryAccountNumber);
		printf("\n--> i = %d\n", i);
		
		if ( cmp == 0)
		{
			cardData->cbalance =(float) Acc_dB[i].balance;
			printf("\n\t*** your account is valid ***\n\n");
			return SERVER_OK;
		}
		else {
			continue;
		}
	}  
	printf("account not found\n");
	while ((getchar()) != '\n' && (getchar()) != EOF);				 // clear input buffer
	TRANS_ERROR = ACCOUNT_NOT_FOUND;
	return ACCOUNT_NOT_FOUND;
}

EN_serverError_t isBlockedAccount(ST_accountsDB_t* accountRefrence)
{
	if (Acc_dB[i].state == BLOCKED)
	{
		printf("sorry this account is blocked\n");
		TRANS_ERROR = DECLINED_STOLEN_CARD;
		return DECLINED_STOLEN_CARD;
	}
	else
	{
		printf("your account is running perfectly\n");
		return SERVER_OK;
	}

}

EN_serverError_t isAmountAvailable(ST_terminalData_t* termData, ST_cardData_t* cardData)
{
	if (termData->transAmount > Acc_dB[i].balance)
	{
		printf("The transaction amount : %f\n", termData->transAmount);
		printf("The balance avaliable amount : %f\n", Acc_dB[i].balance);
		printf("no balance enough\n");
		TRANS_ERROR = LOW_BALANCE;
		return LOW_BALANCE;
	}
	else {
		printf("The transaction amount : %f\n", termData->transAmount);
		printf("The balance avaliable amount : %f\n", Acc_dB[i].balance);
		Acc_dB[i].balance = Acc_dB[i].balance - termData->transAmount;
		printf("new balance equal:%f \n", Acc_dB[i].balance);
		printf("\t*** transaction is done ***\n\n");
		return  SERVER_OK;
	}
}


EN_serverError_t saveTransaction(ST_transaction_t* transData, ST_terminalData_t* termData, ST_cardData_t* cardData)
{

	if ((trans_seq < 255) && (transData->transState == APPROVED))
	{
		printf("\t\t\t\t SAVING TRANSACTION\n");

		printf("transcation sequence is : %d\n",trans_seq);
		transData->transactionSequenceNumber = trans_seq;

		strcpy_s(Trans_dB[trans_seq].cardHolderData.cardHolderName, sizeof(Trans_dB[trans_seq].cardHolderData.cardHolderName), cardData->cardHolderName);
		strcpy_s(Trans_dB[trans_seq].cardHolderData.cardExpirationDate, sizeof(Trans_dB[trans_seq].cardHolderData.cardExpirationDate), cardData->cardExpirationDate);
		strcpy_s(Trans_dB[trans_seq].cardHolderData.primaryAccountNumber, sizeof(Trans_dB[trans_seq].cardHolderData.primaryAccountNumber), cardData->primaryAccountNumber);
		Trans_dB[trans_seq].terminalData.transAmount = termData->transAmount;
		Trans_dB[trans_seq].transactionSequenceNumber = transData->transactionSequenceNumber;
		Trans_dB[trans_seq].transState = transData->transState;

		printf(" cardHolderData name dB   :%s  \n", Trans_dB[trans_seq].cardHolderData.cardHolderName);
		printf(" cardHolderData EXPdate dB:%s  \n", Trans_dB[trans_seq].cardHolderData.cardExpirationDate);
		printf(" cardHolderData PAN dB    :%s  \n", Trans_dB[trans_seq].cardHolderData.primaryAccountNumber);

		printf(" terminalData transamount dB:%f  \n", Trans_dB[trans_seq].terminalData.transAmount);
		printf(" transactionSequenceNumber dB:%d  \n\n", Trans_dB[trans_seq].transactionSequenceNumber);
		trans_seq++;

		return SERVER_OK;
	}
	else {
		printf("saving failed\n");
		TRANS_ERROR = SAVING_FAILED;
		return SAVING_FAILED;
	}
}

EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t* transData, ST_transaction_t Trans_dB[])
{
	for (int x = 0; x < 255; x++)
	{	
		printf("\t\tSEARCH FOR TRANSACTION...\n");
		printf("trans of dB:%d\n", Trans_dB[x].transactionSequenceNumber);
		printf("trans of td:%d\n", transData->transactionSequenceNumber);
		if (Trans_dB[x].transactionSequenceNumber == transData->transactionSequenceNumber)
		{
			printf("DATA found\n");
			printf(" cardHolderData name in   (search) :%s  \n", Trans_dB[x].cardHolderData.cardHolderName);
			printf(" cardHolderData EXPdate   (search) :%s  \n", Trans_dB[x].cardHolderData.cardExpirationDate);
			printf(" cardHolderData PAN       (search) :%s  \n", Trans_dB[x].cardHolderData.primaryAccountNumber);

			printf(" terminalData transamount (search) :%f  \n", Trans_dB[x].terminalData.transAmount);
			printf(" transactionSequenceNumber(search) :%d  \n\n", Trans_dB[x].transactionSequenceNumber);
			return SERVER_OK;
		}
		else {
			continue;
		}
	}
	printf("NO DATA found\n");
	return TRANSACTION_NOT_FOUND;
}
