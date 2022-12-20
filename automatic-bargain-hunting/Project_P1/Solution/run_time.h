#ifndef P1_PROTOTYPE_RUN_TIME_H
#define P1_PROTOTYPE_RUN_TIME_H

#endif //P1_PROTOTYPE_RUN_TIME_H

#include "main.h"
#include "utilities.h"
#include "store_management.h"

char user_groceries[MAX_PRODUCTS][30];

int load_shoppinglist(FILE *list);

void print(t_userdata user, t_store_db store_info[]);

t_userdata create_user();

void sort_stores(t_store_db store_info[]);

void sum_of_products(t_store_db store_info[]);

void set_on_sale(t_store_db store_prices[]);

int random_sale_decider();

void check_shoppinglist(t_userdata user, t_store_db store_info[]);

void print_promotions(t_store_db store_info[], int store);

int check_product(int shoppinglist, t_store_db store_info[]);

int comparator(const void *p1, const void *p2);