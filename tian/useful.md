# Useful Resources

* https://en.cppreference.com/w/cpp
* https://learnxinyminutes.com/docs/c++/

---

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
          | 1016    | 1000  | pValue
          ```

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

---
