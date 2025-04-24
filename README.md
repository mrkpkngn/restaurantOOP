
roject Description: Restaurant Management System

This project is a Restaurant Management System designed to simulate the core functionality of a modern restaurant. The system allows managing menus, processing dine-in and takeout orders, handling table reservations, and organizing tables based on capacity.

The project was developed using object-oriented principles such as inheritance, polymorphism, composition, and method overloading, and is implemented in C++ using header (.h) and source (.cpp) files.

Class Overview

1. Restaurant
The Restaurant class manages the overall functionality of the restaurant. It contains:
- A Menu object
- A list of Table objects
- A list of current Order objects
- A list of Reservation objects

It provides methods to display the menu, find available tables based on the number of guests, and add orders or reservations.

2. Menu, MenuCategory, and MenuItem
The menu structure consists of three layers:
- Menu contains multiple MenuCategory objects (e.g., Appetizers, Main Courses)
- Each MenuCategory contains a list of MenuItem objects
- MenuItem includes a name and price

This design reflects object composition, where higher-level classes are composed of multiple instances of other classes.

3. Order (Abstract Class)
The Order class is an abstract base class that defines a general structure for an order. It includes:
- A list of ordered items
- An order completion flag
- A total price
- A pure virtual method printReceipt() for generating order-specific output

4. DineIn and TakeOut (Derived Classes)
DineIn and TakeOut are concrete subclasses of Order:
- DineIn includes a reference to a Table and represents a dine-in order
- TakeOut includes customer information and pickup time

Both classes override the printReceipt() method to provide custom behavior, demonstrating method overriding and polymorphism.

5. Table
The Table class represents a seating area in the restaurant. Each table has:
- A table number
- A number of seats
- An occupancy status

Tables are used in both DineIn orders and Reservation objects to track availability.

6. Reservation
The Reservation class manages customer reservations. Each reservation includes:
- Customer name
- Number of reserved seats
- A Table object
- Reservation time

Reservations are used to ensure table availability in advance.

Object-Oriented Programming Concepts

This project demonstrates key OOP concepts:

- Composition: Restaurant includes Menu, Table, and Order objects; Menu contains MenuCategory objects, which in turn contain MenuItem objects.
- Inheritance: Order is the base class, and DineIn and TakeOut inherit from it.
- Abstract Class: Order is defined as an abstract class with at least one pure virtual method.
- Overloading and Overriding: Methods such as printReceipt() are overridden in derived classes, enabling dynamic behavior.
- Polymorphism: A polymorphic list of Order* allows handling both DineIn and TakeOut objects through base-class pointers.
- Class-as-Object: Classes like Table and MenuItem are used as object members in other classes.
- Instance Creation: At runtime, dozens of objects are instantiated, including MenuItem, Table, Reservation, DineIn, and TakeOut.
