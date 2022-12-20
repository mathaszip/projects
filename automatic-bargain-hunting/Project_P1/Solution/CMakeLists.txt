add_executable(Project-solution "main.c" "main.h" "store_management.c" "store_management.h" "utilities.c" "utilities.h" "run_time.c" "run_time.h")

file(COPY groceries_database/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY store_database/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY product_database/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR})