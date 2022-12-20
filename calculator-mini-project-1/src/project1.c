#include "project1.h"

int main(void) {
    printf("The final calculation is %lf", run_calculator());
    return 0;
}

double run_calculator() {
    char operator;
    double input;
    double start = 0.0;
    int final = 0;

    while (final == 0) {
        printf("\nEnter operator, and an optional operand: ");
        scanf(" %c", &operator);
        scan_data(&operator, &input);
        start = do_next_op(operator, input, start, &final);
        if (operator == unaryOperators[3]) {
            return start;
        }
        else {
            printf("Result so far is %lf", start);
        }
    }
}

void scan_data(char* operator, double* input) {

    for (int i = 0; i <=4; i++) {
        if (*operator == binary_operators[i]) {
            scanf("%lf", &*input);
            break;
        }
    }
}

double do_next_op(char operator, double input, double start, int* final) {

    if (operator == '+') {
        start = runAddition(start, input);
    }
    else if (operator == '-') {
        start = runSubstraction(start, input);
    }
    else if (operator == '*') {
        start = runMultiplication(start, input);
    }
    else if (operator == '/') {
        if (input == 0) {}
        else {
            start = runDivision(start, input);
        }
    }
    else if (operator == '^') {
        start = runPotency(start, input);
    }
    else if (operator == '#') {
        if (start < 0) {}
        else {
            start = runSquareRot(start);
        }
    }
    else if (operator == '%') {
        start = runReverse(start);
    }
    else if (operator == '!') {
        start = runDivisonWithOne(start);
    }
    else if (operator == 'q') {
        *final = 1;
    }
    return start;
}