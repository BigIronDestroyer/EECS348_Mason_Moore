#include <stdio.h>

// Functions
double celsiusToFahrenheit(double celsius);
double fahrenheitToCelsius(double fahrenheit);
double celsiusToKelvin(double celsius);
double kelvinToCelsius(double kelvin);
void categorizeTemperature(double celsius);

int main() {
    double temp, convertedTemp;
    int inputScale, targetScale;

    // Value Innput
    printf("Enter the temperature value: ");
    scanf("%lf", &temp);

    // Choos type of measurment
    printf("Choose the input temperature scale:\n");
    printf("1. Fahrenheit\n2. Celsius\n3. Kelvin\n");
    scanf("%d", &inputScale);

    // Choose conversion
    printf("Choose the target conversion scale:\n");
    printf("1. Fahrenheit\n2. Celsius\n3. Kelvin\n");
    scanf("%d", &targetScale);

    // Do conversion
    if (inputScale == 1) {  // Fahrenheit
        if (targetScale == 2) {
            convertedTemp = fahrenheitToCelsius(temp);
            printf("Converted Temperature: %.2lf°C\n", convertedTemp);
        }
        else if (targetScale == 3) {
            convertedTemp = celsiusToKelvin(fahrenheitToCelsius(temp));
            printf("Converted Temperature: %.2lfK\n", convertedTemp);
        }
        else {
            convertedTemp = temp;
            printf("Converted Temperature: %.2lf°F\n", convertedTemp);
        }
    }
    else if (inputScale == 2) {  //Celsius
        if (targetScale == 1) {
            convertedTemp = celsiusToFahrenheit(temp);
            printf("Converted Temperature: %.2lf°F\n", convertedTemp);
        }
        else if (targetScale == 3) {
            convertedTemp = celsiusToKelvin(temp);
            printf("Converted Temperature: %.2lfK\n", convertedTemp);
        }
        else {
            convertedTemp = temp;
            printf("Converted Temperature: %.2lf°C\n", convertedTemp);
        }
    }
    else if (inputScale == 3) {  // Kelvin
        if (targetScale == 1) {
            convertedTemp = celsiusToFahrenheit(kelvinToCelsius(temp));
            printf("Converted Temperature: %.2lf°F\n", convertedTemp);
        }
        else if (targetScale == 2) {
            convertedTemp = kelvinToCelsius(temp);
            printf("Converted Temperature: %.2lf°C\n", convertedTemp);
        }
        else {
            convertedTemp = temp;
            printf("Converted Temperature: %.2lfK\n", convertedTemp);
        }
    }
    else {
        printf("Invalid input scale.\n");
        return 1;
    }

    //Celsius
    double tempInCelsius;
    if (targetScale == 2) {
        tempInCelsius = convertedTemp;
    }
    else if (targetScale == 1) {
        tempInCelsius = fahrenheitToCelsius(convertedTemp);
    }
    else {
        tempInCelsius = kelvinToCelsius(convertedTemp);
    }
    categorizeTemperature(tempInCelsius);

    return 0;
}

//Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Celsius to Kelvin
double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

// Kelvin to Celsius
double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

// Gather and give advice
void categorizeTemperature(double celsius) {
    if (celsius < 0) {
        printf("Category: Freezing\n");
        printf("Weather Advisory: Wear a heavy jacket and stay warm.\n");
    }
    else if (celsius >= 0 && celsius <= 10) {
        printf("Category: Cold\n");
        printf("Weather Advisory: Wear a jacket and keep warm.\n");
    }
    else if (celsius > 10 && celsius <= 25) {
        printf("Category: Comfortable\n");
        printf("Weather Advisory: It's a pleasant day.\n");
    }
    else if (celsius > 25 && celsius <= 35) {
        printf("Category: Hot\n");
        printf("Weather Advisory: Stay hydrated and wear light clothes.\n");
    }
    else {
        printf("Category: Extreme Heat\n");
        printf("Weather Advisory: Stay indoors and avoid the heat.\n");
    }
}
