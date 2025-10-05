# Ride Sharing OOP Demo 

This project models a **ride sharing system** using **Object-Oriented Programming (OOP)** concepts in **C++** and **Smalltalk**.  
It demonstrates the three core OOP principles:  

- **Encapsulation** → Bundling data and methods into a single class.  
- **Inheritance** → Reusing features of one class in another.  
- **Polymorphism** → Allowing different classes to respond differently to the same method.  

---

##  Object-Oriented Principles in Action

### 1. Encapsulation
- Each **Driver**, **Rider**, and **Ride** is modeled as a class with **attributes (data)** and **methods (behavior)**.  
- Example:  
  - In C++, `Driver` class has `name`, `rating`, and `showDetails()`.  
  - In Smalltalk, the `Ride` object encapsulates pickup, dropoff, distance, and fare calculation.

### 2. Inheritance
- **Person** → Parent class for **Driver** and **Rider**.  
- Both Driver and Rider **inherit** properties like `name`.  
- They also extend with their own behaviors:  
  - Driver has `showDetails()`.  
  - Rider can `addRide:`.

### 3. Polymorphism
- Both Driver and Rider override `showDetails()` differently.  
- A loop can call `showDetails()` on a list of `Person` objects, and the correct version runs depending on the actual object (Driver or Rider).  

---

##  C++ Implementation

- Uses classes: `Person`, `Driver`, `Rider`, and `Ride`.  
- Demonstrates **inheritance** (`Driver` and `Rider` extend `Person`).  
- Demonstrates **polymorphism** with virtual `showDetails()`.  
- Demonstrates **encapsulation** using `private` members and controlled access via methods.  

### Run Instructions
```bash
g++ rideshare.cpp -o rideshare
./rideshare
OR
Run with online compiler: https://www.onlinegdb.com/online_c++_compiler

```

---

##  Smalltalk Implementation

- Uses classes: `Person`, `Driver`, `Rider`, and `Ride`.  
- Demonstrates **inheritance** (`Driver` and `Rider` extend `Person`).  
- Demonstrates **polymorphism** by overriding `showDetails`.  
- Demonstrates **encapsulation** since instance variables are private by default.  

### Run Instructions
```bash
gst main.gst
OR
Run with Online compiler: https://www.jdoodle.com/execute-smalltalk-online
```

---

##  Key Takeaways
- **C++** → OOP layered on procedural syntax.  
- **Smalltalk** → Pure OOP, everything is an object.  
- Both show the **same design** with encapsulation, inheritance, and polymorphism.  

---

## Personal Notes
This project is a great way to see how the same principles apply universally across languages.  
