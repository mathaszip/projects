#ifndef P1_PROTOTYPE_MAIN_H
#define P1_PROTOTYPE_MAIN_H

#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PRODUCTS 100 // Amount of products
#define MAX_STORES 5     // Amount of stores

typedef struct store {
    double longitude, latitude;
    char name[30];
    char address[30];
    double sum;
    double distance_from_user; //distance from user

    double product_cost[MAX_PRODUCTS];
    char *product_name[MAX_PRODUCTS];
    int product_onSale[MAX_PRODUCTS];
} t_store_db;

typedef struct userdata {
    char name[30];
    double longitude;
    double latitude;
    int amount_of_products_in_cart;
    int transport_mode;
    double max_traveling_distance;
} t_userdata;

const static char *transport_names[] = {"On foot", "Bike", "Car"};

void run_time();