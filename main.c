#include <stdio.h>
#include <stdlib.h> /* required for exit() method */
#include <string.h> /* required for strcmp() method */
#define MAX_STRING_LENGTH 100
#define NUM_SERVICES 20

int main() {

    char services[NUM_SERVICES][MAX_STRING_LENGTH + 1] = {"oil change", "basic inspection", "tire rotation", "wiper replacement", "brakepad replacement", "new tires", "air-filter replacement", "flat tire"};
    float prices[NUM_SERVICES] = {50.00, 200.00, 60.00, 50.00, 100.00, 400.00, 75.00, 20.00}; 
    
    char shopping_cart_services[NUM_SERVICES][MAX_STRING_LENGTH];
    float shopping_cart_prices[NUM_SERVICES]; 
    int cart_size = 0;
    int shopping = 1;
    char service[MAX_STRING_LENGTH + 1];

    while (shopping) {

        //Get the first service
        printf("\n\nSelect service:\n");
        if (fgets(service, MAX_STRING_LENGTH, stdin) == NULL) {
            exit(0);
        }
        service[strlen(service) - 1] = '\0';
        //getchar();
    
        //Verify that the service is available, add it to shopping cart if it is
        for (int i = 0; i < NUM_SERVICES; i++) {
            if (strcmp(services[i], service) == 0) {
                strcpy(shopping_cart_services[cart_size], service);
                shopping_cart_prices[cart_size] = prices[i];
                cart_size++;
                break;
            } else if (i == NUM_SERVICES - 1) {
                printf("\"%s\" is not available.\n", service);
            }
        }

        printf("Continue shopping? (y/n)\n");
        if (getchar() == 'n') {
            shopping = 0;
        }

        while (getchar() != '\n');
    }
    
    float total = 0;
    printf("\n\nDavy's auto shop invoice\n\n");
    for (int i = 0; i < cart_size; i++) {
        printf("%d) %1s -- $%.2f\n", i + 1, shopping_cart_services[i], shopping_cart_prices[i]);
        total += shopping_cart_prices[i];
    }
    printf("Total: $%0.2f\n", total);













}