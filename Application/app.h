#ifndef APP_H
#define APP_H
#define TRUE 1

#include <stdio.h>
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "../Server/server.h"
#include "../Terminal/terminal.h"
#include "../Card/card.h"


ST_cardData_t *cardData;
ST_terminalData_t *termData;
ST_transaction_t* transData;




void appStart(void);



#endif // !APP_H
