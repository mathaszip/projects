add_executable(Experimental-prototype "Experimental_prototype/main.c" "Experimental_prototype/menu.c" "Experimental_prototype/menu.h" "Experimental_prototype/profile_management.c" "Experimental_prototype/profile_management.h" "Experimental_prototype/utilities.c" "Experimental_prototype/utilities.h")
add_executable(Project-prototype "Project_prototype/main.c" "Project_prototype/main.h" "Project_prototype/store_management.c" "Project_prototype/store_management.h" "Project_prototype/utilities.c" "Project_prototype/utilities.h" "Project_prototype/run_time.c" "Project_prototype/run_time.h")

file(COPY "Experimental_prototype/Databases/" DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY Project_prototype/groceries_database/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY Project_prototype/store_database/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY Project_prototype/product_database/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR})