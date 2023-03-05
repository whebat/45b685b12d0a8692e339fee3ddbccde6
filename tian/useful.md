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
    * Using X::Y refers to Y in namespace X.
    * They can help avoid name clashes.

## Arguments for main()

* https://en.cppreference.com/w/cpp/language/main_function
* int main(int argc, char *argv[]) { }
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
    void print3D(const int myArray[][3][3]);   // valid.
    void print3D(const int myArray[3][3][3]);  // valid.
    void print3D(const int myArray[3][][3]);   // invalid.
    void print3D(const int myArray[3][3][]);   // invalid.
    void print3D(const int myArray[3][][]);    // invalid.
    void print3D(const int myArray[][3][]);    // invalid.
    void print3D(const int myArray[][][3]);    // invalid.
    void print3D(const int myArray[][][]);     // invalid.
    ```
* You can pass a "slice" (like in Python or Go) of an array to a function.
  * Given the following:
    * ```cpp
      void printArray(int arr[], int n);
      int main() {
        int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        printArray[A, 10];     // Print all 10 elements.
        printArray[&A[0], 10]; // Print all 10 elements.
        printArray[&A[1], 9];  // Print last 9 elements.
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

## Renaming with `typedef`
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
      u8 myU8 = -1;  // 255                  (2^8 - 1)
      u16 myU8 = -1; // 65535                (2^16 - 1)
      u32 myU8 = -1; // 4294967295           (2^32 - 1)
      u64 myU8 = -1; // 18446744073709551615 (2^64 - 1)
  };
  ```
* Using `typedef` has the potential to make code difficult to read.
* Its use should primarily be restricted to header files which "end users" don't see.
* You can do something like `typedef int* intp` (S2d.ppt, slide 21)
  * Don't actually do this.

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