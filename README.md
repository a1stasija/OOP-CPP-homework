# OOP-CPP-homework
 This repository contains solutions for three homework assignments from the **Object-Oriented Programming 1** course using C++. The tasks are based on the concepts of object-oriented programming and focus on developing practical skills in C++.

## Homework 1: Flower Shop System

This assignment models a **flower shop system** where **flowers** and **bouquets** are managed. The main goal is to demonstrate the following concepts:

- **Classes and Pointers**: Using classes to represent flowers, bouquets, and the shop itself. Flowers are dynamically added to bouquets.
- **Dynamic Memory Management**: Managing dynamic arrays for storing the flowers in bouquets and ensuring proper memory cleanup.
- **Operator Overloading**: Overloading the `<<` operator for displaying bouquets and flowers, and using the `==` and `>` operators for comparing flowers and bouquets.
  
The system models a simple flower shop where bouquets and flowers can be managed, bought, and sold.

### Key Features
- **Bouquet Management**: Add flowers to bouquets and calculate profits based on the selling and buying prices.
- **Flower Shop Management**: The shop manages bouquets and allows adding, selling, and displaying them.
- **Operator Overloading**: The system uses operator overloading for comparing and displaying flowers and bouquets.

### Example Usage
```cpp
Cvet cvet1("Ruza", 2, 3), cvet2("Ljubicica", 3, 5);
Buket b1;
b1.Add(&cvet1);
b1.Add(&cvet2);
cout << b1;  // Prints bouquet details
```

## Homework 1: Library system

This project implements a **library system** where books can be added, searched, and displayed.

## Key Features

- **Knjiga (Book)**: Represents a book with title, author, and ID. Supports operator overloading for copying and printing.
- **Biblioteka (Library)**: Manages a collection of books. Allows adding books, searching by ID, and displaying the library.

### Concepts Demonstrated

- **Classes and Pointers**: Used to model books and the library.
- **Operator Overloading**: For adding books to the library and printing details.
- **Memory Management**: Proper allocation and deallocation of memory.

### Example Usage
```cpp
Knjiga k1("Glupost", "Alexlmao");
Biblioteka b1("Laza Kostic", 100);
b1 += k1;  // Adds the book
cout << b1;  // Prints the library
```

# Homework 3: Set and Word System

This project implements a **set and word system** where characters in a word are managed using linked lists. The task demonstrates various C++ features such as operator overloading and dynamic memory management.

## Key Features

- **Skup (Set)**: Represents a set of unique characters. Supports adding characters, checking if they exist, and printing the set.
- **Rec (Word)**: Represents a word as a sequence of characters. Allows counting characters, syllables, and checking if words rhyme.

### Concepts Demonstrated

- **Linked Lists**: Used to store and manage characters in both the set and word.
- **Operator Overloading**: For adding characters to the set, checking for membership, and comparing words for rhyming.
- **Dynamic Memory Management**: Proper handling of dynamically allocated memory for the set and word.

### Example Usage
```cpp
Skup s("mama");
s += 'a';  // Adds 'a' to the set
Rec rec1("Pica"), rec2("Banana");
bool rima1 = rec1 ^ rec2;  // Checks if the words "Pica" and "Banana" rhyme
cout << (rima1 ? "Rimuju se" : "Ne rimuju se") << endl;
```

