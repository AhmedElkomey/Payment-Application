# Payment Application 
Payment systems are now available everywhere and everyone interacts with these systems every day.

There are different types of transactions you can make, SALE, REFUND, Pre-Authorization, and VOID.

SALE: means to buy something and its price will be deducted from your bank account.
REFUND: this means that you will return something and wants your money back to your bank account.
Pre-Authorization: means holding an amount of money from your account, e.g Hotel reservation.
VOID: this means canceling the transaction, e.g if the seller entered the wrong amount.

Application Flowchart📊
![image](https://user-images.githubusercontent.com/104584213/191598614-dab71b20-09ec-45ba-8761-29a935a265e6.png)



## Features

- **Modular Design**: Separates concerns into different modules such as Application, Card, Server, and Terminal.
- **Transaction Processing**: Handles card transactions securely.
- **Extensibility**: Easily extendable to add more features or modify existing ones.

## Project Structure

```plaintext
Payment-Application/
├── Application/
│   ├── app.c
│   └── app.h
├── Card/
│   ├── card.c
│   └── card.h
├── Server/
│   ├── server.c
│   └── server.h
├── Terminal/
│   ├── terminal.c
│   └── terminal.h
├── .gitattributes
├── .gitignore
├── Payment Application.sln
├── Payment Application.vcxproj
├── Payment Application.vcxproj.filters
├── README.md
└── main_test.c
