//Mason Moore EECS348 10/11/2024
//This file takes an input file from the user and outputs the data in certain ways depending on the order



#include <stdio.h>

#include <stdlib.h>

#define MONTHS 12

// Function s
void monthlySalesReport(const char* months[], double sales[]);
void salesSummaryReport(double sales[]);
void sixMonthMovingAverageReport(double sales[]);
void salesReportHighestToLowest(const char* months[], double sales[]);

// Main function
int main() {
    const char* months[MONTHS] = {"January", "February", "March", "April", "May", "June", 
                                  "July", "August", "September", "October", "November", "December"};
    double sales[MONTHS];
    char fileName[100];
    
    // Ask for file name
    printf("Enter the name of the input file (including extension): ");
    scanf("%s", fileName);

    FILE *file = fopen(fileName, "r");
    
    // Read sales data from file
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", fileName);
        return 1;
    }

    for (int i = 0; i < MONTHS; i++) {
        fscanf(file, "%lf", &sales[i]);
    }
    fclose(file);

    // Generate reports
    monthlySalesReport(months, sales);
    salesSummaryReport(sales);
    sixMonthMovingAverageReport(sales);
    salesReportHighestToLowest(months, sales);

    return 0;
}

// 1. Monthly Sales
void monthlySalesReport(const char* months[], double sales[]) {
    printf("Monthly Sales Report\n");
    printf("----------------------\n");
    printf("%-10s %10s\n", "Month", "Sales");
    for (int i = 0; i < MONTHS; i++) {
        printf("%-10s $%10.2f\n", months[i], sales[i]);
    }
    printf("\n");
}

// 2. Sales summary
void salesSummaryReport(double sales[]) {
    double min = sales[0], max = sales[0], sum = 0;

    for (int i = 0; i < MONTHS; i++) {
        if (sales[i] < min) min = sales[i];
        if (sales[i] > max) max = sales[i];
        sum += sales[i];
    }
    double avg = sum / MONTHS;

    printf("Sales Summary Report\n");
    printf("----------------------\n");
    printf("Minimum Sales: $%.2f\n", min);
    printf("Maximum Sales: $%.2f\n", max);
    printf("Average Sales: $%.2f\n", avg);
    printf("\n");
}

// 3. 6 Month Report
void sixMonthMovingAverageReport(double sales[]) {
    printf("Six-Month Moving Average Report\n");
    printf("------------------------------\n");
    for (int i = 0; i <= MONTHS - 6; i++) {
        double sum = 0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        printf("%-10s - %-10s $%.2f\n", i == 0 ? "January" : "June", 
                i == 6 ? "July" : "December", sum / 6);
    }
    printf("\n");
}

// 4. Sales Report High to Low
void salesReportHighestToLowest(const char* months[], double sales[]) {
    // Sort sales in descending order with corresponding months
    double sortedSales[MONTHS];
    const char* sortedMonths[MONTHS];

    for (int i = 0; i < MONTHS; i++) {
        sortedSales[i] = sales[i];
        sortedMonths[i] = months[i];
    }

    for (int i = 0; i < MONTHS - 1; i++) {
        for (int j = i + 1; j < MONTHS; j++) {
            if (sortedSales[i] < sortedSales[j]) {
                double tempSales = sortedSales[i];
                sortedSales[i] = sortedSales[j];
                sortedSales[j] = tempSales;

                const char* tempMonth = sortedMonths[i];
                sortedMonths[i] = sortedMonths[j];
                sortedMonths[j] = tempMonth;
            }
        }
    }

    printf("Sales Report (Highest to Lowest)\n");
    printf("-------------------------------\n");
    printf("%-10s %10s\n", "Month", "Sales");
    for (int i = 0; i < MONTHS; i++) {
        printf("%-10s $%10.2f\n", sortedMonths[i], sortedSales[i]);
    }
    printf("\n");
}