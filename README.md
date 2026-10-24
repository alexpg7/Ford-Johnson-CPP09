# 💀 Ford-Johnson-CPP09 ![Static Badge](https://img.shields.io/badge/Barcelona-black?style=for-the-badge&logo=42&logoColor=%23FFFFFF)
![Static Badge](https://img.shields.io/badge/C++-blue?style=flat&logo=cplusplus)
![Static Badge](https://img.shields.io/badge/Makefile-green?style=flat&logo=AnkerMake)
![Static Badge](https://img.shields.io/badge/status-completed-green?style=flat)

This project focuses on **data structures, algorithms, and data processing** in C++. It consists of three exercises that explore Bitcoin exchange rates, Reverse Polish Notation, and the Ford-Johnson sorting algorithm.

## Exercises

### Exercise 00 — Bitcoin Exchange

This exercise implements a program that calculates the value of Bitcoin for a given date and amount.

The program loads historical exchange-rate data from `data.csv` and processes an input file containing dates and values. For each entry, it finds the closest available date in the database and uses its exchange rate to calculate the result.

Key features:
- Loads and stores historical exchange rates using a `std::map`.
- Validates dates and input values.
- Supports date comparisons through a custom `Date` class.
- Handles missing dates by selecting the closest available date.
- Calculates and displays the value of the specified amount using the corresponding exchange rate.
- Reports errors when files cannot be opened or input data is invalid.

**Input format:**
The input file must contain dates and values separated by a pipe (`|`), using the following format:

```text
date | value
2011-01-03 | 3
2011-01-09 | 2
```

The exchange-rate database uses dates and values separated by commas.

**How it works:**
1. Loads the exchange-rate database from `data.csv`.
2. Reads the input file provided as a command-line argument.
3. Validates each date and value.
4. Finds the closest available exchange-rate date.
5. Calculates and prints the result for each valid entry.

### Exercise 01 — Reverse Polish Notation (RPN)

This exercise implements a calculator that evaluates mathematical expressions written in **Reverse Polish Notation**.

Unlike conventional notation, RPN places operators after their operands. For example, `8 9 *` means `8 * 9`.

The program uses a `std::stack` to process the expression. Numbers are pushed onto the stack, and operators use the top two values to perform calculations. The result is then pushed back onto the stack.

Key features:
- Evaluates expressions using a stack.
- Supports addition (`+`), subtraction (`-`), multiplication (`*`), and division (`/`).
- Processes an expression supplied as a command-line argument.
- Rejects input containing unsupported characters.

**Example:**

```bash
./RPN "8 9 *"
```

Expected output:

```text
72
```

**How it works:**
1. Reads the expression provided as an argument.
2. Pushes numbers onto the stack.
3. When an operator is encountered, uses the top two stack values to perform the corresponding operation.
4. Pushes the result back onto the stack.
5. Prints the final value.

### Exercise 02 — PmergeMe

This exercise implements a sorting algorithm based on the **Ford-Johnson merge-insertion sort**.

The program receives a sequence of positive integers, sorts them, and compares the processing times of two different STL containers: `std::vector` and `std::deque`.

Key features:
- Validates command-line arguments to ensure the values are positive integers within the supported `int` range.
- Sorts the input using a merge-insertion approach.
- Implements sorting for both `std::vector` and `std::deque`.
- Measures and displays the processing time for each container.
- Displays the input sequence before and after sorting.

**Example:**

```bash
./PmergeMe 9 3 7 1 5 2
```

Example output:

```text
Before: 9 3 7 1 5 2
After:  1 2 3 5 7 9
Time to process a range of 6 elements with std::vector: ...
Time to process a range of 6 elements with std::deque : ...
```

The exact processing times depend on the machine and the input sequence.

**How it works:**
1. Reads and validates the input numbers.
2. Stores the numbers in both a `std::vector` and a `std::deque`.
3. Sorts each container using the merge-insertion approach.
4. Measures the time taken by each sorting process.
5. Displays the sorted sequence and the processing times.

This exercise highlights how different STL containers can be used to implement the same sorting algorithm and compare their performance.

## Instructions

Compile the project using Make from the directory of the corresponding exercise:

```bash
make
```

Run each exercise:

```bash
./ex00 <input_file>
./ex01 "8 9 *"
./ex02 9 3 7 1 5 2
```

For **Exercise 00**, make sure `data.csv` is available in the working directory, as the program uses it as its exchange-rate database.

Clean the generated object files:

```bash
make clean
```

Remove all compiled files and executables:

```bash
make fclean
```

The project is written in **C++** and uses Makefiles for compilation.

