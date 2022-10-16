# Project 1 : A command line calculator
- The program is handed in: 26.10.2022 at 21.00
- Submission: Last commit before the deadline that has been pushed to Github counts

# Description
Write a program that models a simple calculator.
The calculator keeps track of a single number of the type `double', which contains the result calculated so far.
This number is called the accumulator.
The initial value of the accumulator is `0.0`.
In a simple, iterative dialogue with the user, various calculations are performed on the accumulator.
These calculations can be controlled by unary or binary operators, which in this exercise are all noted with exactly one sign.

Unary operations (which precede their operand, and are therefore prefixed) perform a calculation on the accumulator:

`operator` `accumulator`

Binary operations perform a calculation on the accumulator and an additional operand as follows:

`accumulator` `operator` `right_upperand`

In both cases, the value of the expression is returned to the accumulator.

It is recommended that the operation to be performed by the calculator is loaded as a `char` with `scanf`.
Binary operators require a (right) operand that is loaded as a `double' with `scanf`.

You must have a function, `scan_data`, with two output parameters, which returns an operator and a possible right operand from a data line.
If a unary operator is used, the operand is simply returned as `0.0`.

You must also have a function, `do_next_op`, which performs the required operation: `do_next_op` must have two input parameters (operator and operand) in addition to the accumulator, which must be usable for both input and output (and therefore must be a pointer ).
The operand is ignored for unary operators.

The entire dialog of the calculator must be encapsulated in a function, `run_calculator`, which must return the final value of the accumulator.

Also consider writing a Boolean function that can determine whether an operator (of type `char') is binary.

Here are the valid binary operators in the calculator:

- `+` for addition of the accumulator with the operand
- `-` for subtraction of the accumulator with the operand
- `*` for multiplication of the accumulator by the operand
- `/` for division of the accumulator by the operand
- `^` for exponentiation of the accumulator with the operand

And here are the valid unary operators:

- `#` for the square root of the accumulator
- `%` to reverse the sign of the accumulator
- `!` to divide 1 by the accumulator
- `q` to exit the calculator with the final result

Your calculator must refuse to take the square root of a negative number, and it must refuse to divide by zero.
In case of such an illegal operation, the accumulator must simply be left unchanged.
No error messages should be printed.

Your calculator should display the accumulated value after each operation.

Here is an example of a dialogue with the calculator - as the dialogue may look like when you write your program:

```shell
Enter operator, and an optional operand: + 5.000000
Result so far is 5.000000.
Enter operator, and an optional operand: - 6.000000
Result so far is -1.000000.
Enter operator, and an optional operand: * 3.000000
Result so far is -3.000000.
Enter operator, and an optional operand: #
Result so far is -3.000000.
Enter operator, and an optional operand: %
Result so far is 3.000000.
Enter operator, and an optional operand: #
Result so far is 1.732051.
Enter operator, and an optional operand: ^ 2.000000
Result so far is 3.000000.
Enter operator, and an optional operand: * 4.000000
Result so far is 12,000,000.
Enter operator, and an optional operand: !
Result so far is 0.083333.
Enter operator, and an optional operand: q
Final result is: 0.083333
```

This assignment is inspired by a similar assignment from the 6th and 7th editions of the textbook, which is used in the course.

As always, do top-down programming with incremental refinement.
Carefully consider the control structures used.
Also consider making good use of the operators in C to perform calculator operations.
And last but not least, use good input and output parameters in your functions.
