/*
20. write a program that reads data from an electricity meter reading file. 
File contains customer no, previous reading, last reading and customer type. 
Calculate bill using  following formulas.

Meter reading = last reading – previous reading

If customer type = 1, 
    Bill amount = meter reading * 1.50
             
If customer type = 2, 
    Bill amount = meter reading * 2.50
    
If customer type = 3, 
	Bill amount = meter reading * 1.50 for 50 units and meter reading * 2.50 for remaining units

    display output in formatted formula.
*/

#include <stdio.h>

struct MeterReading
{
    int customerNo;
    float previousReading;
    float lastReading;
    int customerType;
};

void calculateBill(struct MeterReading *reading)
{
    float meterReading = reading->lastReading - reading->previousReading;
    float billAmount;

    printf("Customer no : %d\n", reading->customerNo);
    printf("Previous reading : %.2f\n", reading->previousReading);
    printf("Last reading : %.2f\n", reading->lastReading);

    switch (reading->customerType)
    {
        case 1:
        	printf("\nBill calculation : \n");
            billAmount = meterReading * 1.50;
            printf("Bill amount = %.2f * 1.50 = %.2f", meterReading, billAmount);
            break;

        case 2:
        	printf("\nBill calculation : \n");
            billAmount = meterReading * 2.50;
            printf("Bill amount = %.2f * 2.50 = %.2f", meterReading, billAmount);
            break;

        case 3:
        	printf("\nBill calculation : \n");
            if (meterReading <= 50)
            {
                billAmount = meterReading * 1.50;
                printf("Bill amount = %.2f * 1.50 = %.2f", meterReading, billAmount);
            } else
            {
                billAmount = 50 * 1.50 + (meterReading - 50) * 2.50;
                printf("Bill amount = 50 * 1.50 + (%.2f - 50) * 2.50 = %.2f", meterReading, billAmount);
            }
            break;

        default:
            printf("\nInvalid customer type..!");
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
            return;
    }
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
}

int main()
{
    FILE *file = fopen("meter_reading.txt", "r");

    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    struct MeterReading reading;
    int numReadings = 0;

    while (fscanf(file, "%d %f %f %d",
                  &reading.customerNo,
                  &reading.previousReading,
                  &reading.lastReading,
                  &reading.customerType) == 4)
                  {

        calculateBill(&reading);
        numReadings++;
    }

    fclose(file);

    printf("Total number of readings processed: %d\n", numReadings);

    return 0;
}
