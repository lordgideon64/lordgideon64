#include <stdio.h>

int main() {
    float hoursWorked, hourlyWage;
    float grossPay, taxes, netPay;

    // Constants for tax rates and thresholds
    const float OVERTIME_RATE = 1.5;
    const float TAX_RATE_1 = 0.15; // 15% for the first $600
    const float TAX_RATE_2 = 0.20; // 20% for the amount over $600
    const float TAX_THRESHOLD = 600.0;

    // Request user input
    printf("Enter hours worked in a week: ");
    scanf("%f", &hoursWorked);
    printf("Enter hourly wage: ");
    scanf("%f", &hourlyWage);

    // Calculate gross pay
    if (hoursWorked > 40) {
        float regularHours = 40;
        float overtimeHours = hoursWorked - regularHours;
        grossPay = (regularHours * hourlyWage) + (overtimeHours * hourlyWage * OVERTIME_RATE);
    } else {
        grossPay = hoursWorked * hourlyWage;
    }

    // Calculate taxes
    if (grossPay <= TAX_THRESHOLD) {
        taxes = grossPay * TAX_RATE_1;
    } else {
        taxes = (TAX_THRESHOLD * TAX_RATE_1) + ((grossPay - TAX_THRESHOLD) * TAX_RATE_2);
    }

    // Calculate net pay
    netPay = grossPay - taxes;

    // Print results
    printf("Gross Pay: $%.2f\n", grossPay);
    printf("Taxes: $%.2f\n", taxes);
    printf("Net Pay: $%.2f\n", netPay);

    return 0;
}