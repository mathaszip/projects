#include "run_time.h"
#include <unistd.h>

//The function run time uses all the different functions and holds all the data
void run_time() {
    srand(time(NULL));
    //Getting all user data
    t_userdata user = create_user();

    //Getting all stores
    t_store_db *ptrToAllStoreList = create_store_database(user);

    check_shoppinglist(user, ptrToAllStoreList);

    set_on_sale(ptrToAllStoreList);

    sum_of_products(ptrToAllStoreList);

    sort_stores(ptrToAllStoreList, MAX_STORES);

    print(user, ptrToAllStoreList);
}


int check_product(int shoppinglist, t_store_db store_info[]) {
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (strcmp(user_groceries[shoppinglist], store_info[1].product_name[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void check_shoppinglist(t_userdata user, t_store_db store_info[]) {
    for (int i = 0; i < user.amount_of_products_in_cart; i++) {
        if (check_product(i, store_info) == 0) {
            printf("\nItem: %s is invalid, please update here: ", user_groceries[i]);
            scanf(" %s", user_groceries[i]);
            printf("\nThis will not update the product in shoppinglist.txt, please consider correcting your mistake in the file!");
        }
    }
    printf("\n\n===================================\n=Shoppinglist loaded successfully!=\n===================================\n");
    sleep(1);
}

/**
 * This is a void function with no return value.
 * It's purpose is to assign values to each object in the store_info array
 * @param store_info   | array of type t_store_db consisting of objects of type t_store_db
 */
void sum_of_products(t_store_db store_info[]) {
    //Variable declarations
    double sum;
    int j;

    //Outer loop going through all of the stores
    for (int i = 0; i < MAX_STORES; i++) {
        //Variable definitions
        j = 0, sum = 0;
        //Inner loop going through all of the products in each store
        for (int k = 0; k < MAX_PRODUCTS; k++) {
            //Comparison function (strcmp = stringcompare), compares each product in shoppinglist with each product in the total list of products)
            //If return value of strcmp is 0 then there's no difference between the two compared elements
            if (strcmp(user_groceries[j], store_info[i].product_name[k]) == 0) {
                //Incrementing the local sum variable by the product_cost of the product that was just found
                sum += store_info[i].product_cost[k];
                //Resetting variable k, so we can loop through all of the products for next store again.
                k = 0;
                //Incrementing j by one, so we can compare next product in the shoppinglist with all of the products in the store
                j++;
            }
        }
        //Return value to the array in the parameter
        store_info[i].sum = sum;
    }
}

void set_on_sale(t_store_db store_prices[]) {
    for (int i = 0; i < MAX_STORES; i++) {
        for (int k = 0; k < MAX_PRODUCTS; k++) {
            store_prices[i].product_onSale[k] = random_sale_decider();
        }
    }
}

int random_sale_decider() {
    int x;

    x = rand() % 4;

    if (x == 1)
        return 1;

    return 0;
}

/* This function sorts all the store_info after lowest price*/
void sort_stores(t_store_db store_info[], int stores_amount) {
    //Quicksort method
    qsort(store_info, stores_amount, sizeof(t_store_db), comparator);

    //Bubblesort method
    /*t_store_db temp;
    for (int i = 0; i < stores_amount - 1; i++)
    {
        for (int j = 0; j < (stores_amount - 1-i); j++)
        {
            if (store_info[j].sum > store_info[j + 1].sum)
            {
                temp = store_info[j];
                store_info[j] = store_info[j + 1];
                store_info[j + 1] = temp;
            }
        }
    }*/
}

int comparator(const void *p1, const void *p2) {
    t_store_db *store1 = (t_store_db *) p1;
    t_store_db *store2 = (t_store_db *) p2;

    if (store1->sum > store2->sum)
        return 1;
    else if (store1->sum < store2->sum)
        return -1;
    else
        return 0;
}

void print_promotions(t_store_db store_info[], int store) {
    int i, j = 0;

    for (i = 0; i < MAX_PRODUCTS; i++) {
        if (strcmp(user_groceries[j], store_info[store].product_name[i]) == 0) {
            j++;
            if (store_info[store].product_onSale[i] == 1) {
                printf("%s is on sale for %.2lf DKK!\n", store_info[store].product_name[i],
                       store_info[store].product_cost[i]);
            }
            i = 0;
        }
    }
}

void print(t_userdata user, t_store_db store_info[]) {
    printf("\nYour name is set to: %s "
           "\nYour location is set to: %lf %lf"
           "\nYour preferred mode of transport is set to %s and your max travel distance is set to %lf km."
           "\n\nYou have %d item(s) in your shopping list:", user.name, user.longitude, user.latitude,
           transport_names[user.transport_mode - 1], user.max_traveling_distance, user.amount_of_products_in_cart);

    for (int i = 0; i < user.amount_of_products_in_cart; i++) {
        printf("\n%s", user_groceries[i]);
    }

    printf("\n\nStores found within %lf km from your location:", user.max_traveling_distance);
    for (int i = 0; i < MAX_STORES; i++) {
        if (store_info[i].distance_from_user <= user.max_traveling_distance) {
            printf("\n%s %s | TOTAL PRICE: %.2lf | %.2lf KM AWAY\n", store_info[i].name, store_info[i].address,
                   store_info[i].sum, store_info[i].distance_from_user);
            print_promotions(store_info, i);
        }
        printf("---------------------------------------------------------\n");
    }
}

t_userdata create_user() {
    t_userdata session;
    printf("\nEnter name please: ");
    scanf(" %s", session.name);
    printf("\nPlease enter your location in a coordinate format: ");
    scanf(" %lf, %lf", &session.longitude, &session.latitude);
    printf("\nPlease enter the number of your preferred mode of transport:\n(1) On foot\n(2) Bike\n(3) Car\n");
    scanf(" %d", &session.transport_mode);
    printf("\nHow far are you willing to travel %s in kilometers: ", transport_names[session.transport_mode - 1]);
    scanf(" %lf", &session.max_traveling_distance);

    char filename[30] = "shoppinglist.txt";
    FILE *shoppingList;

    shoppingList = fopen(filename, "r");

    validate_file_pointer(shoppingList);

    session.amount_of_products_in_cart = load_shoppinglist(shoppingList);

    return session;
}

int load_shoppinglist(FILE *list) {
    int i = 0;
    int k;

    if (list == NULL) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    } else {
        while (!feof(list)) {
            fscanf(list, "%s", user_groceries[i]);
            i++;
        }
        k = i;

        while (k < 100) {
            strcpy(user_groceries[k], "0");
            k++;
        }

    }
    return i;
}