#ifndef P1_PROTOTYPE_MAIN_H
#define P1_PROTOTYPE_MAIN_H

#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PRODUCTS 100                 // Max amount of products
#define MAX_STORES 5                     // Max amount of stores

typedef struct store
{
    double   longitude, latitude;           //Coordinates of store
    char     name[30];                      //Name of store array
    char     address[30];                   //Phyiscal address of store
    double   sum;                           //Sum of products in shoppinglist
    double   distance_from_user;            //Distance from user

    double   product_cost[MAX_PRODUCTS];    //Product cost array
    char    *product_name[MAX_PRODUCTS];    //Product name array
    int      product_onSale[MAX_PRODUCTS];  //Product sale array
} t_store_db;

typedef struct userdata
{
    char     name[30];                      //Name of the user array
    double   longitude;                     //Longitude coordinate of the user
    double   latitude;                      //Latitude coordinate of the user
    int      amount_of_products_in_cart;    //Amount of products in shoppinglist
    int      transport_mode;                //Transport option of the user
    double   max_traveling_distance;        //Max traveling distance
} t_userdata;

const static char *transport_names[] =      //Array of char pointers consisting of
        {"On foot", "Bike", "Car"};         //names of transport options

void run_time();
