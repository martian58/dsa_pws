#include <stdio.h>
#include <math.h>

/*
1. Start
2. Input number of days d
3. Calculate cost for each car:
    Mercedes: 100 * d + max(0, 500 - 250)
    BMW: 80 * d + max(0, 500 - 300) * 1.2
    Tesla: 180 * d + ceil(500 / 200) * 20
4. Output the car with the lowest cost
5. End
*/

/*
Compilation

gcc ex_5.c -o ex5 -lm
*/

#include <stdio.h>
#include <math.h>

int main() {
    int rental_days;
    float mercedes_cost, bmw_cost, tesla_cost;
    const int distance = 500;

    printf("Enter the number of rental days: ");
    scanf("%d", &rental_days);

    int mercedes_free_km = 250;
    mercedes_cost = 100 * rental_days;
    if (distance > mercedes_free_km) {
        mercedes_cost += (distance - mercedes_free_km) * 1;
    }

    int bmw_free_km = 300;
    bmw_cost = 80 * rental_days;
    if (distance > bmw_free_km) {
        bmw_cost += (distance - bmw_free_km) * 1.2;
    }

    int tesla_free_km = 250;
    int charge_distance = 200;
    int num_of_charges = ceil((float)distance / charge_distance); 
    tesla_cost = 180 * rental_days + 20 * num_of_charges;

    printf("\nCosts:\nMercedes: %.2f\nBMW: %.2f\nTesla: %.2f\n", mercedes_cost, bmw_cost, tesla_cost);

    if (mercedes_cost < bmw_cost && mercedes_cost < tesla_cost) {
        printf("Mercedes is the most beneficial choice.\n");
    } else if (bmw_cost < mercedes_cost && bmw_cost < tesla_cost) {
        printf("BMW is the most beneficial choice.\n");
    } else {
        printf("Tesla is the most beneficial choice.\n");
    }

    return 0;
}
