# Table of Contents

<!-- TOC -->
* [Table of Contents](#table-of-contents)
* [Useful Resources](#useful-resources)
* [Notes from Slides](#notes-from-slides)
  * [Namespace](#namespace)
  * [Arguments for main()](#arguments-for-main--)
  * [Unsigned](#unsigned)
  * [Chaining the operator `=`](#chaining-the-operator-)
  * [Function prototype](#function-prototype)
  * [Function definition](#function-definition)
  * [Memory](#memory)
    * [Null Pointers](#null-pointers)
  * [Arrays](#arrays)
    * [Classical Arrays vs. Array Containers](#classical-arrays-vs-array-containers)
    * [Initializing](#initializing)
    * [Passing Arrays to Functions](#passing-arrays-to-functions)
    * [Pointers to Arrays](#pointers-to-arrays)
  * [Loops](#loops)
  * [Default Arguments to functions](#default-arguments-to-functions)
  * [Void Pointers: `void*`](#void-pointers--void)
  * [Renaming with `typedef` or `using`](#renaming-with-typedef-or-using)
    * [Renaming with `typedef`](#renaming-with-typedef)
    * [Renaming with `using`](#renaming-with-using)
  * [The `auto` keyword](#the-auto-keyword)
  * [Static](#static)
  * [Dynamic Memory](#dynamic-memory)
  * [IO](#io)
    * [Text File Streams](#text-file-streams)
  * [Preprocessor](#preprocessor)
  * [The `extern` keyword](#the-extern-keyword)
  * [The `assert` keyword](#the-assert-keyword)
  * [Makefile/makefile and `make`](#makefilemakefile-and-make)
  * [Segementation Fault & Bus Fault](#segementation-fault--bus-fault)
  * [User-Defined Types](#user-defined-types)
  * [Randomness](#randomness)
    * [Pre C++11: `rand()`](#pre-c11--rand)
    * [Post C++11: `#include <random>`](#post-c11--include-random)
  * [OOP Nonsense](#oop-nonsense)
    * [Encapsulation](#encapsulation)
    * [UML Visibility Prefixes](#uml-visibility-prefixes)
  * [Operator Overloading](#operator-overloading)
    * [Can Overload](#can-overload)
    * [Cannot overload](#cannot-overload)
* [Notes from Sites](#notes-from-sites)
  * [Operators](#operators)
<!-- TOC -->

# Useful Resources

* https://en.cppreference.com/w/cpp
* https://learnxinyminutes.com/docs/c++/

# Notes from Slides

## Namespace

* https://en.cppreference.com/w/cpp/language/namespace
* Namespaces are organisational tools for encapsulation.
    * Using `X::Y` refers to Y in namespace X.
    * They can help avoid name clashes.
    * `using namespace std;`
        * Brings the entire `std` namespace into scope.
        * Can now access without needing scope resolution operators.
        * The double colon `::` is a scope resolution operator.
    * `using std::cout`
        * Brings part of the `std` namespace into scope.
* Namespaces **cannot** be declared inside a function!
    * Not even main()
* Namespaces can be nested inside another namespace.
    * It behaves exactly how you think it would.
        * `namespace NS1 { namespace NS2 { int myVar; } }`
        * `int main() { NS1::NS2::myVar = 0; return 0; }`

## Arguments for main()

* https://en.cppreference.com/w/cpp/language/main_function
* ```cpp
  int main(int argc, char *argv[]) { }
  ```
* argc is the number of command-line arguments.
    * Including the name of the executable itself.
    * The 'c' in "argc" stands for count.
* *argv is an array of C-style strings.

## Unsigned

* Variables that are declared as unsigned only represent values
  greater than or equal to zero.

## Chaining the operator `=`

* The operator `=` is right associative.
* ```cpp
  int x, y, z;
  x = y = z = 65
  ```
* z is set to 65, then y to z, then x to y.

## Function prototype

* Also known as:
    * Forward declaration.
    * Declarations.
* ```cpp
  void print();
  ```
* Often done in header (.h) files.
    * These files also include data structure declarations like
      struct, enum, class, etc.

## Function definition

* ```cpp
  void print() {
    cout << "Hello world!" << endl;
  }
  ```

## Memory

* A sequence of bytes.
* Each typed object is given a location in memory.
* Values are placed in such objects.
* Access
    * Access a variable using the variable name.
    * Access the address the variable references,
      and operate on that address, using operator `&`.
* Aliases
    * ```cpp
      int value = 41;
      int &rValue = value;       // References MUST be initialized.
      int *pValue const = value; // Behaves like a reference alias, but is an object of its own.
      ```
    * ```cpp
      /// Print the address of the pointer itself.
      cout << &pValue << endl;
      ```
    * ```cpp
      /// Print the address of the value.
      cout << pValue << endl;
      cout << &rValue << endl;
      cout << &value << endl;
      ```
    * ```cpp
      /// Print the value itself, i.e. '41'.
      cout << *pValue << endl; // This is called "dereferencing".
      cout << rValue << endl;
      cout << value << endl;
      ```
    * Differences between rValue and pValue:
        * pValue has its own address in memory.
        * ```
          -------------------
          | Address | Value |
          |---------|-------|
          | 1000    | 41    | value, rValue
          | 1008    |       | 
          | 1016    | 1000  | pValue
          ```

### Null Pointers

* Use 0, `NULL`, or `nullptr`
* ```cpp
  int *ptr = 0;
  int *ptr = NULL;    // cstdlib header, or <stddef.h>
  int *ptr = nullptr; // C++11 literal.
  ```
* `nullptr` is always a pointer type, `NULL` is not.
* Hence, when using `NULL`, `ptr` may be treated as an integer 0.
* This will not happen when using `nullptr`.
    * Must compile with `-std=c++11` or newer.
    * Otherwise, `Error: nullptr is not defined.`

## Arrays

### Classical Arrays vs. Array Containers

* ```cpp
  #include <array>
  std::array<int, 4> arrayContainer;
  int arrayClassical[4];
  ```
    * The memory location is set up, but there's no initialization.
    * To initialize all four locations to 0...
        * ```cpp
      std::array<int, 4> arrayContainer = {0};
      int arrayClassical[4] = {0};
      ```
* The `[]` is referred to as subscripting.

### Initializing

* ```cpp
  const unsigned myArraySize = 3;
  int ia1[myArraySize] = {24, 36, 86};
  int ia2[] = {33, 21, 75}; // Size is inferred.
  int ia3[] = {9, 12};      // ia3[2] is defaulted to '0'.
  ```
* The string datatype will default to `""` (empty string) for any elements uninitialized.

### Passing Arrays to Functions

* By default, **arrays are passed to functions by reference**.
    * Use `const` to make the array immutable in the function.
* Multidimensional arrays only allow the 1st dimension's size to be omitted.
    * ```cpp
      void print3D(const int myArray[][3][3]); // valid.
      void print3D(const int myArray[3][3][3]); // valid.
      void print3D(const int myArray[3][][3]); // invalid.
      void print3D(const int myArray[3][3][]); // invalid.
      void print3D(const int myArray[3][][]); // invalid.
      void print3D(const int myArray[][3][]); // invalid.
      void print3D(const int myArray[][][3]); // invalid.
      void print3D(const int myArray[][][]); // invalid.
      ```
* You can pass a "slice" (like in Python or Go) of an array to a function.
    * Given the following:
        * ```cpp
          void printArray(int arr[], int n);
          int main() {
          int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
          printArray[A, 10]; // Print all 10 elements.
          printArray[&A[0], 10]; // Print all 10 elements.
          printArray[&A[1], 9]; // Print last 9 elements.
          }
          // function definition ...
          // ...
          // ...
          ```
    * In Python:
        * ```python
          A: list = [1,2,3,4,5,6,7,8,9,10]
          print(A)       # Print all 10 elements.
          print(A[1:10]) # Print last 9 elements.
          ```

### Pointers to Arrays

* ```cpp
  int A[10];
  int *B = A;
  
  /// Same thing
  std::cout << *B   << std::endl;
  std::cout << A[0] << std::endl;
  ```
* Hence `B[5]` is the same as `A[5]`.
* But, `int A; int *B = &A;` allows `B[7]` or `B[10]`.
    * For pointers to arrays, do not access indexes outside the upper bound.
    * For pointers to integers, do not use indexes.

## Loops

* Infinite loops:
  ```cpp
  while (true) { break; }
  for (;;)     { break; }
  do           { break; } while (true);
  ```
* Range for loop:
  ```cpp
  std::string str("Hello world");
  
  /// By value
  for (char c: str) {
    cout << c;
  }
  cout << endl;
  
  /// By reference.
  for (char &c: str) {
    cout << c;
  }
  cout << endl;
  
  /// By reference, same as above.
  for (auto &c: str) {
    cout << c;
  }
  cout << endl;
  ```

## Default Arguments to functions

```cpp
void printGreeting(string message = "Hello, ", string name = "John");
int main() {
    std::string studentName = "Mike";
    std::string studentGreeting = "Good morning, ";
    printGreeting(studentGreeting, studentName); // Good morning, Mike
    printGreeting(studentGreeting);              // Good morning, John
    printGreeting();                             // Hello, John
    printGreeting(studentName);                  // MikeJohn
}
// function definition ...
// ...
// ...
```

## Void Pointers: `void*`

* Hold the address of any type.
* Type being held is **not** known.
* Useful when dealing with memory as memory, without accessing the content.
    * For example, `sizeof(void*)` is 4, or something like that.
* Cannot dereference directly.
* Can dereference with casting.
    * ```cpp
      int i = 10;
      void *vp = &i;
      
      // Option 1
      int *ip = static_cast<int*>(vp);
      cout << *ip << endl;
      
      // Option 2
      cout << *(static_cast<int*>(vp)) << endl;
      
      // Option 3 (S2d.ppt Slide 19)
      cout << *((int*)vp) << endl;
      ```
    * If the void pointer is not cast to the correct type, undefined behavior will happen.

## Renaming with `typedef` or `using`

### Renaming with `typedef`

* ```cpp
  #include <cstdint>
  typedef uint8_t   u8;
  typedef uint16_t  u16;
  typedef uint32_t  u32;
  typedef uint64_t  u64;
  typedef int8_t    i8;
  typedef int16_t   i16;
  typedef int32_t   i32;
  typedef int64_t   i64;
  int main {
      u8  myU8 = -1;  // 255                  (2^8 - 1)
      u16 myU16 = -1; // 65535                (2^16 - 1)
      u32 myU32 = -1; // 4294967295           (2^32 - 1)
      u64 myU64 = -1; // 18446744073709551615 (2^64 - 1)
  };
  ```
* Using `typedef` has the potential to make code difficult to read.
* Its use should primarily be restricted to header files which "end users" don't see.
* You can do something like `typedef int* intp` (S2d.ppt, slide 21)
    * Don't actually do this.

### Renaming with `using`

* ```cpp
  typedef double f64;
  using longfloat = f64;
  longfloat myVariable = 5.6;
  ```

## The `auto` keyword

* Introduced in C++11.
* **Compiler** figures out the variable's type **based on the initializer**.

## Static

* ```cpp
  int val() {
    static int static_val = 0;
    return ++val;
  }
  
  int main()
  {
    for (int i = 0; i < 100; i++) {
        std::cout << val() << ' ';
    }
  }
  ```

## Dynamic Memory

* ```cpp
  int *ip = new int(420);
  int *iA = new int[100];
  ```

## IO

### Text File Streams

* ```cpp
  #include <fstream>
  string str = "filename.txt"
  ifstream ifs(str);
  if (ifs.is_open()) {
    
    // Do stuff
  
    ifs.close()
  } else {
    // Unable to open file.
    // File does not exist?
    // Typo in filename?
  }
  ```

## Preprocessor

* ```cpp
  /// @file MyTemplates.h
  #ifndef MyTemplates_H
  #define MyTemplates_H
  
  // #include statement is always after #define
  #include <algorithm>
  
  // Implementation here
  
  #endif // MyTemplates_H
  ```
* The file should end at the `#endif` line.
* Definitions:
    * `#ifndef` if not defined.
    * `#define` defines a macro.
        * Specifies a preprocessor variable.
        * Used in the text of our program.
        * Literally **preprocessed**, i.e. prior to the rest of the compilation.
    * `#ifdef` if defined.
    * `#endif` end of preprocessor directive block.
* Why use `#ifndef` and `#endif`?
    * Avoid multiple inclusion.
        * Make sure we don't include the same header files through multiple paths.
    * This is known as a **header guard**.
    * Definitions are often only allowed to be made once.

## The `extern` keyword

* ```cpp
  /// @file MyTemplates.h
  #ifndef MyTemplates_H
  #define MyTemplates_H
  
  // Declare variable.
  extern unsigned int global_call_count;
  
  #endif // MyTemplates_H
  ```
* Use `extern` to indicate a variable has been defined elsewhere.
* ```cpp
  /// @file main.cpp
  #include <iostream>
  #include "MyTemplates.h"
  
  // Definition checked against declaration.
  unsigned int global_call_count = 50;
  
  int main() {
    for (int i = 0; i < 10; i++) {
        std::cout << global_call_count++ << ' ';
    }
    std::cout << std::endl;
    return 0;
  }
  
  #endif // MyTemplates_H
  ```

## The `assert` keyword

* Defensive programming is guarding against unexpected errors.
* Exception handling handlers errors that are expected.
* Offensive programming is when bad data results in:
    * An error report printed on the screen.
    * Immediate termination of program.
    * Hence, `assert` is offensive programming.
* ```cpp
  #include <iostream>
  #include <cassert>
  using std::cout;
  using std::endl;
  
  int main() {
    assert(5 > 1);   // Program will not terminate.
    assert(100 < 0); // Program will terminate here, with relevant message to stdout.
  
    cout << "Hello World" << endl; // Unreachable code.
    return 0;                      // Unreachable code.
  }
  ```
* **Slides**
    * Use `assert` with some sort of calculated function that you couldn't know for sure the state of at the time.
* **tldr**
    * Identify bugs / wrong implementations by forcing the program to terminate early.
    * Program will stop working until code is fixed, such that the assert statement evaluates to `true`.

## Makefile/makefile and `make`

* Describe how our program can be constructed from source files.
* Dependency and construction rules.
* Execution via CLI, works with the shell of the OS.
* In Unix-like, default shell is `/bin/sh`.
* In Windows, default shell is usually `cmd.exe`, but it can also use PowerShell.
* Indent with tabs, do not use spaces.
* Macros are defined like `CC=g++` and `CCFLAGS=-std=c++11 -Wall`
    * These variables are **not the same** as the ones defined by the shell.

## Segementation Fault & Bus Fault

* Segmentation Fault:
    * Trying to use memory which does not belong to you.
    * Out of bounds array references.
    * Reference through dangling pointers.
        * Memory has already been freed.
        * i.e. You did `delete` on that pointer, **then** tried to access or dereference it.
    * Reference through uninitialized pointers.
    * Happens at runtime, compiler is unaware.
* Bus Fault:
    * Access memory that cannot be physically addressed.
    * Memory is invalid for the access type specified.
        * Something to do with memory misalignment.

## User-Defined Types

* A `class` has private members by default.
    * See [class](https://en.cppreference.com/w/cpp/keyword/class).
    * ```cpp
      class Point2D {
          int x; // this is private.
      private:
          int y; // this is also private.
      public:
          int i; // this is public.
      };
      ```
* A `struct` has public members by default.
    * See [struct](https://en.cppreference.com/w/cpp/keyword/struct).
    * ```cpp
      struct Point2D {
          int x; // this is public.
      private:
          int y; // this is private.
      public:
          int i; // this is also public.
      };
      ```
* A `union` has public members and can hold one of its members at a time.
    * See [union](https://en.cppreference.com/w/cpp/language/union).

## Randomness

### Pre C++11: `rand()`

* No
* No need to know.

### Post C++11: `#include <random>`

* ```cpp
  #include <random>
  int main() {
  std::default_random_engine rnd; // default seed.
  std::uniform_int_distribution<> intRange(-999, 999);
  int i = intRange(rnd); // random number between **inclusive** range.
        
  // Other examples
  std::uniform_int_distribution<unsigned> uintRange(0, 9);
  }
  ```
* You can also use your own seed:
    * ```cpp
      #include <random>
      int main() {
          int mySeed = 314159;
          // Do this
          {
              std::default_random_engine rnd(mySeed);
          }
          // Or this
          {
              std::default_random_engine rnd;
              rnd.seed(mySeed);
          }
      }
      ```

## OOP Nonsense

### Encapsulation
* To hide components in a container.
  * Encapsulation is an example of a black box.
* To access these hidden components, an interface is required.
  * For example, getter setter for a private variable.
* The `private` keyword encapsulates.
  * But it is a compiler setting, same as `const`.
  * Use pointers to indirectly target the private or const variable.
  * Allows user to access or modify the variable.

### UML Visibility Prefixes
* `+` is the public member
* `-` is the private member
* `#` is the protected member
* `/` is the derived member
* `~` is the package member
* Therefore:
  * ```
    +---------------------+
    |       Person        |
    +---------------------+
    | - name: string      |
    | - age: int          |
    | - height: float     |
    +---------------------+
    | + getName(): string |
    +---------------------|
    ```

## Operator Overloading

### Can Overload
* Binary Operators
  * `+` `-` `*` `/` `%` `>` `<`
* Unary Operators
  * `!` `++` `--` `&` `->`

### Cannot overload
* `.` - Member access operator
* `*` - Pointer operator
* `::` - Scope resolution operator
* `? :` - Conditional operator
* `sizeof()` - function

# Notes from Sites

## Operators

* Assignment
    * ```cpp
      a = b   // Simple
      a += b  // Addition
      a -= b  // Subtraction
      a *= b  // Multiplication
      a /= b  // Division
      a %= b  // Remainder
      a &= b  // Bitwise AND
      a |= b  // Bitwise OR
      a ^= b  // Bitwise XOR
      a <<= b // Bitwise left shift
      a >>= b // Bitwise right shift
      ```
* Increment/Decrement
    * ```cpp
      ++a
      --a
      a++
      a--
      ```