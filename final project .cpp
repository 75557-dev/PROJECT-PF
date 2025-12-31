#include <iostream>
#include <fstream>
using namespace std;

// Function declarations
float celsiusToFahrenheit(float c);
float fahrenheitToCelsius(float f);
float celsiusToKelvin(float c);
float kelvinToCelsius(float k);
void saveToFile(float input, float output, string type);

int main() {
    int choice;
    float inputTemp, result;
    int attempts = 0;        // Count attempts
    const int MAX_ATTEMPTS = 10;

    while (attempts < MAX_ATTEMPTS) {
        cout << "\n===== Temperature Conversion Menu =====\n";
        cout << "1. Celsius to Fahrenheit\n";
        cout << "2. Fahrenheit to Celsius\n";
        cout << "3. Celsius to Kelvin\n";
        cout << "4. Kelvin to Celsius\n";
        cout << "5. Exit\n";
        cout << "Attempt " << (attempts + 1) << " of " << MAX_ATTEMPTS << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 5) {
            cout << "Program exited by user.\n";
            return 0;   // Program ends here
        }

        cout << "Enter temperature: ";
        cin >> inputTemp;

        switch (choice) {
            case 1:
                result = celsiusToFahrenheit(inputTemp);
                cout << "Result: " << result << " °F\n";
                saveToFile(inputTemp, result, "Celsius to Fahrenheit");
                break;

            case 2:
                result = fahrenheitToCelsius(inputTemp);
                cout << "Result: " << result << " °C\n";
                saveToFile(inputTemp, result, "Fahrenheit to Celsius");
                break;

            case 3:
                result = celsiusToKelvin(inputTemp);
                cout << "Result: " << result << " K\n";
                saveToFile(inputTemp, result, "Celsius to Kelvin");
                break;

            case 4:
                result = kelvinToCelsius(inputTemp);
                cout << "Result: " << result << " °C\n";
                saveToFile(inputTemp, result, "Kelvin to Celsius");
                break;

            default:
                cout << "Invalid choice!\n";
                continue;
        }

        attempts++;   // Increase attempt count
    }

    cout << "\nMaximum attempts reached (10). Program ended.\n";
    return 0;
}

// ---------- Functions ----------

float celsiusToFahrenheit(float c) {
    return (c * 9 / 5) + 32;
}

float fahrenheitToCelsius(float f) {
    return (f - 32) * 5 / 9;
}

float celsiusToKelvin(float c) {
    return c + 273.15;
}

float kelvinToCelsius(float k) {
    return k - 273.15;
}

void saveToFile(float input, float output, string type) {
    ofstream file("temperature_history.txt", ios::app);
    file << type << " | Input: " << input << " | Output: " << output << endl;
    file.close();
}

