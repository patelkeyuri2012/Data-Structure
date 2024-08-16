/*
19. A file contains sales of  salesmen for 4 months. Read this file and display output in formatted manner.
Salesman					Sales in Rs.						% of total sales
			Jan	     Feb		Mar    	    April		Jan	     Feb		Mar    	    April	  
*/

#include <stdio.h>
#define MAX_SALESMEN 50
#define MONTHS 4

struct salesman
{
    char name[50];
    float sales[MONTHS];
    float totalsales;
};

void displaySales(struct salesman *salesmen, int numsalesmen)
{
    printf("______________________________________________________________________________________________________________________\n");
    printf("%-30s %-32s %-25s %-15s\n", "Salesman", "Sales of months", "Total sales", "% of sales of months\n");
    printf("%-20s %-10s %-10s %-10s %-25s %-10s %-10s %-10s %-7s" ," ", "Jan", "Feb", "Mar", "April", "Jan", "Feb", "Mar", "April", "\n");
    printf("______________________________________________________________________________________________________________________\n\n");

    for (int i = 0; i < numsalesmen; i++)
    {
        printf("%-20s", salesmen[i].name);

        for (int j = 0; j < MONTHS; j++)
        {
            printf("%-10.2f ", salesmen[i].sales[j]);
        }
        printf("%-15.2f ", salesmen[i].totalsales);

        for (int j = 0; j < MONTHS; j++)
        {
            printf("%-10.2f ", (salesmen[i].sales[j] / salesmen[i].totalsales) * 100);
        }
        printf("\n");
    }
}

int main()
{
    FILE *file = fopen("sales_data.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    struct salesman salesmen[MAX_SALESMEN];
    int numsalesmen = 0;

    while (fscanf(file, "%s %f %f %f %f",
                  salesmen[numsalesmen].name,
                  &salesmen[numsalesmen].sales[0],
                  &salesmen[numsalesmen].sales[1],
                  &salesmen[numsalesmen].sales[2],
                  &salesmen[numsalesmen].sales[3]) == 5 && numsalesmen < MAX_SALESMEN)
                  {
        salesmen[numsalesmen].totalsales = 0;
        for (int i = 0; i < MONTHS; i++)
        {
            salesmen[numsalesmen].totalsales += salesmen[numsalesmen].sales[i];
        }
        numsalesmen++;
    }
    fclose(file);
    displaySales(salesmen, numsalesmen);
    return 0;
}
