# AI Usage Log

**Student:** Sydney Moroney  
**Platform:** ChatGPT  
**Model:** GPT-6

---

## Interaction 1

### User

**Lab 10 - C++ Programming**

**Objective:&#xA0;**&#x47;et familiar with more C++ programming features discussed in the lecture, such as the class, template, and operator overloading.

**What to** **turn** **in**: Please provide a URL to your GitHub repository. If you are unable to push your code to GitHub, you may instead use KU GitLab, which works in a very similar way. *Make sure the repository is public. Otherwise, the TAs won't be able to grade it.&#xA0;*

***Grading:***

- A valid **Makefile** must be included in the repository. **[5 points]**
- The **Practice 1** class definition and initialization. **[35 points]**
- Each of the remaining practices is worth **10 points**. **[60 points total]**

---

Programming problem #1. Matrix Operations

**1. Read values from a file into the class Matrix):**

Define the `Matrix` class, implement a function to read matrix data from the user-specified file, and initialize the class. The input file follows the following format

- The first line contains a single integer **N**, which represents the size of the matrices (i.e., each matrix is **N × N**).
- This is followed by the data for two **N × N** matrices.

Your task is to read the file, store the matrix data, and display both matrices with clear and properly aligned formatting (i.e., columns must line up neatly). You may assume that **N** is a valid positive integer. For this assignment, you are required to define and use a custom `Matrix` class to store the matrix data instead of directly using `std::vector`.

In addition, follow proper object-oriented design practices by keeping data members **private** and providing **public** member functions for access and operations.

**2. Add the two matrices and display the result by using operator overloading. (refer to Nov 6 lecture slides page 40):**

Implement operator overloading to add two matrices and display the resulting matrix.

**Note (same as practice 3):** The addition must be implemented using operator overloading, not as a standalone function. In addition, the overloaded operator must work with your `Matrix` class, not with `std::vector`.

**3. Multiply two matrices and display the result, utilizing the operator overloading:**\
Implement operator overloading to add two matrices and display the resulting matrix.

Please refer to the link for the matrix multiplication: [https://www.mathsisfun.com/algebra/matrix-multiplying.html](https://www.mathsisfun.com/algebra/matrix-multiplying.html)

**4. Get the sum of matrix diagonal elements:**\
Implement a function to compute and display the sum of the main and secondary diagonal elements of a matrix.

**5.** **Swap matrix rows and display the result. Note that your function should pass the `Matrix` by value so that the original matrix is not modified. By default, the function should swap rows (or columns) at indices 0 and 1, but it should also allow users to specify any other pair of indices (refer to Nov 4 lecture slides, pages 24 - 26):**\
Implement a function that takes a matrix and two-row indices as input (with indexing starting at 0). If both indices are within valid bounds, swap the specified rows and output the resulting matrix.

**Note (same as practice 6):** Your function should be able to handle any valid row indices.

**6. Swap matrix columns and display the result:**

Implement a function that takes a matrix and two column indices as input (with indexing starting at 0). If both indices are within valid bounds, swap the specified columns and display the resulting matrix.

**7. Update matrix rows and display the result. The default row and column indices should be 0 and 0, and the default value should be 100. However, you should allow users to use any other values:**\
Implement a function that accepts a matrix, a row index, a column index, and a new value. If both indices are valid (with indexing starting at 0), update the element at the specified position and display the resulting matrix.

**Sample Input**

4

01 02 03 04\
05 06 07 08\
09 10 11 12\
13 14 15 16\
13 14 15 16\
09 10 11 12\
05 06 07 08\
01 02 03 04

---

**Note**: When using advanced features, different compilers and platforms may produce varying results. Please ensure that your program runs correctly on the Cycle server using the default version of `g++`. - walk me through this in terms of instructions

### Assistant Summary

Explained the assignment as one C++ program covering seven practices. Described creating `main.cpp`, `input.txt`, and a `Makefile`; defining and initializing a custom `Matrix` class; reading and displaying matrices; overloading addition and multiplication; calculating diagonal sums; swapping rows and columns; updating an element; testing with `g++` on Cycle; and submitting a public repository link. Included sample input, brief code examples, and a progress checklist.

---

## Interaction 2

### User

give me the code please and thanks

### Assistant Summary

Provided a full C++ implementation for all seven practices, including a `Matrix` class with private data, file-reading and display functions, overloaded `+` and `*` operators, diagonal-sum methods, pass-by-value row and column swapping, and an element-update function with default arguments. Also provided a `Makefile`, sample input, project download links, compilation instructions, and expected sample outputs. Stated that the program had been compiled and tested with `g++`.

---

## Interaction 3

### User

find my prologue comments from my last eecs 348 assignment or lab and give them to me

### Assistant Summary

Searched available files and located the opening prologue comment from `Assignment5 (1).cpp`, an EECS 348 Sudoku Solver assignment. Reproduced its program title, description, inputs, outputs, collaborators, sources, authorship, and revision information. Explained which header fields could be reused for Lab 10 and that the authorship and source information should reflect the new program.

---

## Interaction 4

### User

what is the practice one class definition and initilaization

### Assistant Summary

Explained that Practice 1 requires defining a `Matrix` class with private size and data members and public member functions. Identified the constructor as the initialization step, showed how it creates a zero-filled square matrix, and explained how the `read()` and `display()` functions work. Described creating two `Matrix` objects in `main()` and reading and displaying their values.

---

## Interaction 5

### User

can you make this for I, Sydney Moroney

### Assistant Summary

Created an `ai_usage_log.md` document for Sydney Moroney that records the available user messages verbatim in chronological order and summarizes the corresponding assistant responses without reproducing their full code or explanations.
