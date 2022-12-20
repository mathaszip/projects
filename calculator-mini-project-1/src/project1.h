#ifndef PROJECT1_PROJECT1_H
#define PROJECT1_PROJECT1_H
#endif //PROJECT1_PROJECT1_H

#include <stdio.h>

#include "math_functions.h"

const char  binary_operators[5] = {'+', '-', '*', '/', '^'},
            unaryOperators[4] = {'#', '%', '!', 'q'};

double run_calculator();
void scan_data(char* operator, double* input);
double do_next_op(char operator, double input, double start, int* final);


