#include "run_time.h"
#include <unistd.h>

/**
 * This function runs the program.
 */
void run_time()
{
    // Initialize the random number generator with the current time
    srand(time(NULL));

    // Get the user data
    t_userdata user = create_user();

    // Get the store database
    t_store_db *ptrToAllStoreList = create_store_database(user);

    // Check the shopping list for invalid products
    check_shoppinglist(user, ptrToAllStoreList);

    // Set some products on sale
    set_on_sale(ptrToAllStoreList);

    // Calculate the sum of the products in the shopping list
    sum_of_products(ptrToAllStoreList);

    // Sort the stores by distance
    sort_stores(ptrToAllStoreList);

    // Print the results to the user
    print(user, ptrToAllStoreList);
}

/**
 * This function checks whether a product is valid.
 *
 * @param shoppinglist The index of the product in the user's shopping list
 * @param store_info An array of structures containing information about the store
 *
 * @return 1 if the product is valid, 0 otherwise
 */
int check_product(int shoppinglist, t_store_db store_info[])
{
    // Iterate over the products in the store
    for (int i = 0; i < MAX_PRODUCTS; i++)
    {
        // Check if the product in the shopping list matches a product in the store
        if (strcmp(user_groceries[shoppinglist], store_info[1].product_name[i]) == 0)
        {
            // Return 1 if the product is valid
            return 1;
        }
    }
    // Return 0 if the product is not valid
    return 0;
}

/**
 * This function checks whether the products in the user's shopping list are valid.
 *
 * @param user A structure containing information about the user
 * @param store_info An array of structures containing information about the store
 */
void check_shoppinglist(t_userdata user, t_store_db store_info[])
{
    // Iterate over the products in the user's shopping list
    for (int i = 0; i < user.amount_of_products_in_cart; i++)
    {
        // Check if the current product is invalid
        if (check_product(i, store_info) == 0)
        {
            // Print a message to the user to update the product
            printf("\nItem: %s is invalid, please update here: ", user_groceries[i]);
            // Read the updated product name from standard input
            scanf(" %s", user_groceries[i]);
            // Print a warning to the user that the shopping list file will not be updated
            printf("\nThis will not update the product in shoppinglist.txt, please consider correcting your mistake in the file!");
        }
    }
    // Print a success message if the shopping list is loaded successfully
    printf("\n\n===================================\n=Shoppinglist loaded successfully!=\n===================================\n");
    // Pause the program for 1 second before continuing
    sleep(1);
}

/**
 * This is a void function with no return value.
 * It's purpose is to assign values to the sum variable for each element in the store_info array
 * @param store_info   | array of data type t_store_db
 */
void sum_of_products(t_store_db store_info[])
{
    //Variable declarations
    double sum;
    int j;

    //Nested loop. Outer loop going through all of the stores
    for (int i = 0; i < MAX_STORES; i++)
    {
        //Variable definitions
        j = 0, sum = 0;
        //Inner loop going through all of the products in each store
        for (int k = 0; k < MAX_PRODUCTS; k++)
        {
            //Comparison function (strcmp = stringcompare), compares each product
            //in shoppinglist with each product in the total list of products
            //If return value of strcmp is 0 then there's no
            //difference between the two compared elements
            if (strcmp(user_groceries[j], store_info[i].product_name[k]) == 0)
            {
                //Incrementing the local sum variable by the
                //product_cost of the product that was just found
                sum += store_info[i].product_cost[k];
                //Resetting variable k, so we can loop through
                //all of the products for next store again.
                k = 0;
                //Incrementing j by one, so we can compare next product
                //in the shoppinglist with all of the products in the store
                j++;
            }
        }
        //Return value to the indexed store of the array in the parameter
        store_info[i].sum = sum;
    }
}

/**
 * This function sets some products on sale in each store.
 *
 * @param store_info An array of structures containing information about the store prices
 */
void set_on_sale(t_store_db store_info[])
{
    // Iterate over the stores
    for (int i = 0; i < MAX_STORES; i++)
    {
        // Iterate over the products in each store
        for (int k = 0; k < MAX_PRODUCTS; k++)
        {
            // Set the product on sale using the random_sale_decider function
            store_info[i].product_onSale[k] = random_sale_decider();
        }
    }
}

/**
 * This function determines whether a product should be on sale or not.
 *
 * @return 1 if the product should be on sale, 0 otherwise
 */
int random_sale_decider()
{
    // Generate a random number between 0 and 3
    int x = rand() % 4;

    // If the number is 1, return 1 to indicate that the product should be on sale
    if (x == 1)
        return 1;

    // Otherwise, return 0 to indicate that the product should not be on sale
    return 0;
}

/**
 * This function sorts the stores.
 *
 * @param store_info An array of structures containing information about the stores
 */
void sort_stores(t_store_db store_info[])
{
    // Use the qsort function to sort the stores
    qsort(store_info, MAX_STORES, sizeof(t_store_db), comparator);
}

/**
 * This function compares two stores by their total price.
 *
 * @param p1 A pointer to the first store
 * @param p2 A pointer to the second store
 *
 * @return 1 if the first store has a higher total price, -1 if the second store has a higher total price, 0 if the total prices are equal
 */
int comparator(const void *p1, const void *p2)
{
    // Cast the void pointers to t_store_db pointers
    t_store_db *store1 = (t_store_db *) p1;
    t_store_db *store2 = (t_store_db *) p2;

    // Compare the total prices of the two stores
    if (store1->sum > store2->sum)
        return 1;
    else if (store1->sum < store2->sum)
        return -1;
    else
        return 0;
}

/**
 * This function prints the promotions for a given store.
 *
 * @param store_info An array of structures containing information about the stores
 * @param store The index of the store in the array
 */
void print_promotions(t_store_db store_info[], int store)
{
    // Initialize the product and store index variables
    int i, j = 0;

    // Iterate over the products in the store
    for (i = 0; i < MAX_PRODUCTS; i++)
    {
        // Check if the current product is in the user's shopping list
        if (strcmp(user_groceries[j], store_info[store].product_name[i]) == 0)
        {

            // Check if the value of j is larger than the size of user_groceries
            if (j > (sizeof(user_groceries) / sizeof(user_groceries[0])))
            {
                // If so, break out of the loop
                break;
            }

            // Increment the shopping list index
            j++;

            // Check if the product is on sale
            if (store_info[store].product_onSale[i] == 1)
            {
                // Print a message to the user indicating that the product is on sale
                printf("%s is on sale for %.2lf DKK!\n", store_info[store].product_name[i],
                       store_info[store].product_cost[i]);
            }

            // Reset the product index to 0
            i = 0;
        }
    }
}

/**
 * This function prints the results of the program to the user.
 *
 * @param user A structure containing information about the user
 * @param store_info An array of structures containing information about the stores
 */
void print(t_userdata user, t_store_db store_info[])
{
    // Print the user information
    printf("\nYour name is set to: %s "
           "\nYour location is set to: %lf %lf"
           "\nYour preferred mode of transport is set to %s and your max travel distance is set to %lf km."
           "\n\nYou have %d item(s) in your shopping list:\n", user.name, user.longitude, user.latitude,
           transport_names[user.transport_mode - 1], user.max_traveling_distance, user.amount_of_products_in_cart);

    // Print the items in the user's shopping list
    for (int i = 0; i < user.amount_of_products_in_cart; i++)
    {
        printf("\n%s", user_groceries[i]);
    }

    // Print the stores that are within the user's maximum traveling distance
    printf("\n\nStores found within %lf km from your location:\n", user.max_traveling_distance);
    for (int i = 0; i < MAX_STORES; i++)
    {
        if (store_info[i].distance_from_user <= user.max_traveling_distance)
        {
            // Print the store information and total price
            printf("\n%s %s | TOTAL PRICE: %.2lf | %.2lf KM AWAY\n", store_info[i].name, store_info[i].address,
                   store_info[i].sum, store_info[i].distance_from_user);

            // Print the promotions for the current store
            print_promotions(store_info, i);
        }

        // Print a separator line after each store
        printf("---------------------------------------------------------\n");
    }
}

/**
 * This function creates a user object by prompting the user for input.
 *
 * @return A t_userdata structure containing the user's information
 */
t_userdata create_user()
{
    // Create a user data structure
    t_userdata session;

    // Prompt the user for their name
    printf("\nEnter name please: ");
    scanf(" %s", session.name);

    // Prompt the user for their location
    printf("\nPlease enter your location in a coordinate format (x, y): ");
    scanf(" %lf, %lf", &session.longitude, &session.latitude);

    // Prompt the user for their preferred mode of transport
    printf("\nPlease enter the number of your preferred mode of transport:\n(1) On foot\n(2) Bike\n(3) Car\n");
    scanf(" %d", &session.transport_mode);

    // Prompt the user for their maximum traveling distance
    printf("\nHow far are you willing to travel %s in kilometers: ", transport_names[session.transport_mode - 1]);
    scanf(" %lf", &session.max_traveling_distance);

    // Open the shopping list file and load the shopping list
    char filename[30] = "shoppinglist.txt";
    FILE *shoppingList;
    shoppingList = fopen(filename, "r");

    //validate the file pointer to see if the file exists.
    validate_file_pointer(shoppingList);

    session.amount_of_products_in_cart = load_shoppinglist(shoppingList);

    // Return the user data structure
    return session;
}

/**
 * This function loads the shopping list from a file into an array.
 *
 * @param list A pointer to the shopping list file
 * @return The number of items in the shopping list
 */
int load_shoppinglist(FILE *list)
{
    int i = 0;
    int k;

    // Read each item from the file and store it in the user_groceries array
    while (!feof(list))
    {
        fscanf(list, "%s", user_groceries[i]);
        i++;
    }

    // Set remaining elements in the array to "0"
    k = i;
    while (k < MAX_PRODUCTS)
    {
        strcpy(user_groceries[k], "0");
        k++;
    }

    // Return the number of items in the shopping list
    return i;
}
