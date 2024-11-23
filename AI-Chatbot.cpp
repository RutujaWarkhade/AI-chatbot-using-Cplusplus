#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

// Base class
class JARVIS {
protected:
    string input;
    string userName;

public:
    // Constructor
    JARVIS() {
        srand(time(0));
        cout << "\n*********** WELCOME TO TALK WITH J.A.R.V.I.S ************\n\n";
        cout << "Hello, I am J.A.R.V.I.S. What's your name?\n";
        getline(cin, userName);
        cout << "Hello " << userName << "! How can I assist you today?\n";
        showTimeBasedGreeting();
    }

    // Method to get user input
    void getInput() {
        cout << "\nYou: ";
        getline(cin, input);
        transform(input.begin(), input.end(), input.begin(), ::tolower); // Convert to lowercase
    }

    // Method to process the input
    virtual void processInput() {
        if (input == "hi") {
            cout << "Hello " << userName << ", I am J.A.R.V.I.S.\n";
        } else if (input == "how are you") {
            cout << "I am functioning optimally. Thank you for asking!\n";
        } else if (input == "hello") {
            cout << "Hi " << userName << "!\n";
        } else if (input == "what is your name") {
            cout << "I am J.A.R.V.I.S, your personal assistant.\n";
        } else if (input == "bye") {
            cout << "Goodbye " << userName << "! Have a great day!\n";
            exit(0);
        } else if (input == "tell me a joke") {
            tellJoke();
        } else {
            cout << "Sorry " << userName << ", I can't understand that.\n";
        }
    }

protected:
    // Method to tell a random joke
    void tellJoke() {
        string jokes[] = {
            "Why don't scientists trust atoms? Because they make up everything!",
            "Why did the computer go to the doctor? It caught a virus!",
            "Why was the math book sad? It had too many problems!"
        };
        int randomIndex = rand() % (sizeof(jokes) / sizeof(jokes[0]));
        cout << jokes[randomIndex] << "\n";
    }

    // Method to display a time-based greeting
    void showTimeBasedGreeting() {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        if (ltm->tm_hour < 12)
            cout << "Good Morning, " << userName << "!\n";
        else if (ltm->tm_hour < 18)
            cout << "Good Afternoon, " << userName << "!\n";
        else
            cout << "Good Evening, " << userName << "!\n";
    }
};

// Derived class for additional features
class AdvancedJARVIS : public JARVIS {
public:
    // Constructor
    AdvancedJARVIS() : JARVIS() {}

    // Overriding processInput to handle additional features
    void processInput() override {
        if (input == "addition") {
            performAddition();
        } else if (input == "subtraction") {
            performSubtraction();
        } else if (input == "multiplication") {
            performMultiplication();
        } else if (input == "division") {
            performDivision();
        } else if (input == "convert temperature") {
            convertTemperature();
        } else if (input == "convert km to miles") {
            convertKilometersToMiles();
        } else if (input == "palindrome checker") {
            checkPalindrome();
        } else if (input == "factorial") {
            calculateFactorial();
        } else if (input == "find max") {
            findMaxInList();
        } else {
            // Call the base class method for other inputs
            JARVIS::processInput();
        }
    }

private:
    // Methods for arithmetic operations
    void performAddition() {
        int num1, num2;
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;
        cout << "The sum is: " << num1 + num2 << "\n";
        cin.ignore();
    }

    void performSubtraction() {
        int num1, num2;
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;
        cout << "The difference is: " << num1 - num2 << "\n";
        cin.ignore();
    }

    void performMultiplication() {
        int num1, num2;
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;
        cout << "The product is: " << num1 * num2 << "\n";
        cin.ignore();
    }

    void performDivision() {
        int num1, num2;
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;
        if (num2 != 0)
            cout << "The quotient is: " << num1 / num2 << "\n";
        else
            cout << "Division by zero is not allowed.\n";
        cin.ignore();
    }

    // Method to convert temperature
    void convertTemperature() {
        double celsius;
        cout << "Enter temperature in Celsius: ";
        cin >> celsius;
        cout << "Temperature in Fahrenheit: " << (celsius * 9 / 5) + 32 << "\n";
        cin.ignore();
    }

    // Method to convert kilometers to miles
    void convertKilometersToMiles() {
        double kilometers;
        cout << "Enter distance in kilometers: ";
        cin >> kilometers;
        cout << kilometers << " kilometers is " << kilometers * 0.621371 << " miles.\n";
        cin.ignore();
    }

    // Method to check if a word is a palindrome
    void checkPalindrome() {
        string word;
        cout << "Enter a word to check: ";
        cin >> word;
        string reversed = word;
        reverse(reversed.begin(), reversed.end());
        if (word == reversed)
            cout << "The word is a palindrome.\n";
        else
            cout << "The word is not a palindrome.\n";
        cin.ignore();
    }

    // Method to calculate factorial
    void calculateFactorial() {
        int number;
        cout << "Enter a number: ";
        cin >> number;
        long long factorial = 1;  // Use long long to handle larger factorial results
        for (int i = 1; i <= number; ++i) {
            factorial *= i;
        }
        cout << "The factorial of " << number << " is " << factorial << ".\n";
        cin.ignore();
    }

    // Method to find the maximum number in a list
    void findMaxInList() {
        int n, num, maxNum;
        cout << "How many numbers will you enter? ";
        cin >> n;
        cout << "Enter the numbers:\n";
        cin >> maxNum; // Initialize with the first number
        for (int i = 1; i < n; i++) {
            cin >> num;
            if (num > maxNum)
                maxNum = num;
        }
        cout << "The largest number is: " << maxNum << "\n";
        cin.ignore();
    }
};

int main() {
    // Create an object of the derived class
    AdvancedJARVIS jarvis;

    // Continuous loop to get and process input
    while (true) {
        jarvis.getInput();
        jarvis.processInput();
    }

    return 0;
}
