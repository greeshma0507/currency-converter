#include <iostream>
#include <string>
using namespace std;

class CurrencyConverter {
public:
    string currencyName;
    double conversionRate;

public:
    CurrencyConverter(string name, double rate) {
        currencyName = name;
        conversionRate = rate;
    }

    double convertCurrency(double amount) {
        return amount * conversionRate;
    }

    void displayConversionRate() {
        cout << "1 Indian Rupee is equal to " << conversionRate << " " << currencyName << endl;
    }
};

void displayAllCurrencies(CurrencyConverter currencies[], int size) {
    cout << "\nAll Available Currencies and Conversion Rates:" << endl;
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". " << currencies[i].currencyName << ": " << currencies[i].conversionRate << endl;
    }
}

int main() {
    // Define the currencies and their conversion rates
    CurrencyConverter currencies[12] = {
        CurrencyConverter("US Dollar (USD)", 0.012),
        CurrencyConverter("Euro (EUR)", 0.0113),
        CurrencyConverter("Japanese Yen (JPY)", 1.8081),
        CurrencyConverter("British Pound Sterling (GBP)", 0.010),
        CurrencyConverter("Swiss Franc (CHF)", 0.0115),
        CurrencyConverter("Canadian Dollar (CAD)", 0.0166),
        CurrencyConverter("Australian Dollar (AUD)", 0.0189),
        CurrencyConverter("New Zealand Dollar (NZD)", 0.0205),
        CurrencyConverter("Chinese Yuan (CNY)", 0.0763),
        CurrencyConverter("Swedish Krona (SEK)", 0.1122),
        CurrencyConverter("Norwegian Krone (NOK)", 0.1144),
        CurrencyConverter("Singapore Dollar (SGD)", 0.0162)
    };

    int choice;
    double amount;

    cout << "\t\t\t\t\t\t\tCURRENCY CONVERTER\n" << endl;
    cout << "-----------------------------------------------------------" << endl;

    while (true) {
        cout << "\nChoose an option:" << endl;
        cout << "1. Convert currency" << endl;
        cout << "2. Display all currencies and conversion rates" << endl;
        cout << "3. Exit" << endl;
        cout << "\nEnter your choice(1 to 3): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nChoose a currency to convert to:" << endl;
                for (int i = 0; i < 12; i++) {
                    cout << i + 1 << ". " << currencies[i].currencyName << endl;
                }
                cout << "13. Back to main menu" << endl;
                cout << "\nEnter your choice(1 to 13): ";
                cin >> choice;

                if (choice < 1 || choice > 13) {
                    cout << "Invalid choice. Please try again." << endl;
                    continue;
                }

                if (choice == 13) {
                    continue; // Go back to the main menu
                }

                cout << "Enter the amount in Indian Rupees: ";
                cin >> amount;

                if (amount < 0) {
                    cout << "Amount cannot be negative." << endl;
                } else {
                    cout << amount << " INR is equal to " << currencies[choice - 1].convertCurrency(amount) << " " << currencies[choice - 1].currencyName << endl;
                    currencies[choice - 1].displayConversionRate();
                }
                break;

            case 2:
                displayAllCurrencies(currencies, 12);
                break;

            case 3:
                cout << "Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}