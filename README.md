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
```

## Getting Started

### Prerequisites

To build and run this application, you need to have the following tools installed:

- GCC Compiler
- Make
- Git

### Installation

1. **Clone the Repository**

    ```sh
    git clone https://github.com/yourusername/Payment-Application.git
    cd Payment-Application
    ```

2. **Build the Application**

    ```sh
    make
    ```

### Usage

1. **Run the Application**

    ```sh
    ./payment_application
    ```

2. **Running Tests**

    ```sh
    ./main_test
    ```

## Contributing

We welcome contributions to enhance the features and improve the codebase. Here’s how you can contribute:

1. Fork the repository.
2. Create a new branch: \`git checkout -b feature-name\`.
3. Make your changes and commit them: \`git commit -m 'Add new feature'\`.
4. Push to the branch: \`git push origin feature-name\`.
5. Open a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgements

- Thanks to all contributors and open-source projects that have been utilized in the development of this application.
