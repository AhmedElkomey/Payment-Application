# Payment Application 
Payment systems are now available everywhere and everyone interacts with these systems every day.

There are different types of transactions you can make, SALE, REFUND, Pre-Authorization, and VOID.

SALE: means to buy something and its price will be deducted from your bank account.
REFUND: this means that you will return something and wants your money back to your bank account.
Pre-Authorization: means holding an amount of money from your account, e.g Hotel reservation.
VOID: this means canceling the transaction, e.g if the seller entered the wrong amount.

Application Flowchart📊
![image](https://user-images.githubusercontent.com/104584213/191598614-dab71b20-09ec-45ba-8761-29a935a265e6.png)



## Overview
The Payment Application project is designed to handle various types of payment transactions including SALE, REFUND, Pre-Authorization, and VOID. The project is implemented in C and is structured into several modules to separate different functionalities.

Repository Structure
The repository is organized as follows:

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
├── main_test.c
├── Payment Application.sln
├── Payment Application.vcxproj
├── Payment Application.vcxproj.filters
├── .gitattributes
├── .gitignore
└── README.md

## Modules Description
Application Module
app.c: Contains the main application logic for handling different types of transactions.
app.h: Header file for the application module, includes function prototypes and necessary includes.
Card Module
card.c: Manages card-related functionalities such as card validation, reading card details, etc.
card.h: Header file for the card module, includes function prototypes and necessary includes.
Server Module
server.c: Handles server-side operations such as transaction validation, storing transaction data, etc.
server.h: Header file for the server module, includes function prototypes and necessary includes.
Terminal Module
terminal.c: Manages terminal-related operations such as reading input, displaying output, etc.
terminal.h: Header file for the terminal module, includes function prototypes and necessary includes.
Main Test File
main_test.c: This file contains the main function used for testing the application. It demonstrates how to use the application and its different modules.
Configuration Files
Payment Application.sln: Solution file for the project.
Payment Application.vcxproj: Project file for Visual Studio.
Payment Application.vcxproj.filters: Filters file for organizing the project in Visual Studio.

# How to Build and Run
## Clone the Repository:
git clone https://github.com/AhmedElkomey/Payment-Application.git
Open the Solution in Visual Studio:
Open Payment Application.sln using Visual Studio.

## Build the Project:
Build the solution to compile all modules.

## Run the Application:
Execute the compiled binary to run the payment application.

Transaction Types
SALE: Process a sale transaction.
REFUND: Process a refund transaction.
Pre-Authorization: Handle a pre-authorization transaction.
VOID: Void a previously processed transaction.
Contributing
Contributions are welcome! Please follow these steps to contribute:

Fork the repository.
Create a new branch for your feature or bugfix.
Commit your changes.
Push your changes to your forked repository.
Create a pull request.
License
This project is licensed under the MIT License.

