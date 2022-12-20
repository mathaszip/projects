#ifndef P1_PROTOTYPE_FILE_MANAGEMENT_H
#define P1_PROTOTYPE_FILE_MANAGEMENT_H

#endif //P1_PROTOTYPE_FILE_MANAGEMENT_H


void update_store_database_with_prices(t_store_db arrayOfStorePrices[]);

t_store_db *create_store_database(t_userdata session);

void collect_list_of_groceries(FILE *db, t_store_db arrayOfStorePrices[], int number);

t_store_db collect_store_info(FILE *db);