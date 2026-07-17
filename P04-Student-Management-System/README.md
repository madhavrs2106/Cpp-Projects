# 🎓 P04 - Student Management System (C++)

A simple **Student Management System** built using **C++** that allows users to manage student records through a menu-driven console application. The project demonstrates the use of **Object-Oriented Programming (OOP)** concepts, **STL Vector**, and **File Handling** for persistent data storage.

---

## 📌 Features

- ➕ Add new student records
- 📋 Display all students in a formatted table
- 🔍 Search student by ID
- 💾 Save student records to a text file
- 📂 Load existing records automatically on startup
- ✅ Duplicate Student ID validation
- 🛡️ Basic input validation for menu choices
- 📁 Persistent storage using file handling

---

## 🛠️ Technologies Used

- **Language:** C++
- **Concepts:**
    - Object-Oriented Programming (Classes & Objects)
    - Encapsulation
    - Constructors
    - STL (`vector`)
    - File Handling (`fstream`)
    - Formatted Output (`iomanip`)
    - Functions

---

## 📂 Project Structure

```
P04-Student-Management-System/
│
├── data/
│    └── students.txt
│
├── Student_Management_System.cpp
├── .gitignore
└── README.md
```

---

## 📖 Menu

```
====================================
     STUDENT MANAGEMENT SYSTEM
====================================

1. Add New Student
2. Display All Students
3. Search Student by ID
4. Save and Exit
```

---

## 💾 Data Storage

Student records are stored inside:

```
students.txt
```

Data format:

```
101    John Smith    20    Computer Science
102    Alice Brown   19    Artificial Intelligence
103    Rahul Verma   21    Data Science
```

The file is automatically:

- Loaded when the program starts
- Saved when the user exits

---

## 📷 Sample Output

### Add Student

```
Enter Student ID: 101
Enter Student Name: John Smith
Enter Student Age: 20
Enter Course/Major: Computer Science

Student added successfully!
```

### Display Students

```
-------------------------------------------------------------
ID        Name                     Age       Course
-------------------------------------------------------------
101       John Smith               20        Computer Science
102       Alice Brown              19        Artificial Intelligence
-------------------------------------------------------------
```

### Search Student

```
Enter Student ID to search: 101

 Record Found
=============================
 ID:        101
 Name:      John Smith
 Age:       20
 Course:    Computer Science
```

---

## 🧠 OOP Concepts Demonstrated

- ✔ Class
- ✔ Objects
- ✔ Private Data Members
- ✔ Public Member Functions
- ✔ Constructors
- ✔ Encapsulation

---

## 📚 STL Concepts Used

- `std::vector`
- Range-based loops
- Iteration
- Dynamic storage

---

## 📁 File Handling

The project uses:

- `ifstream`
- `ofstream`

Operations:

- Read student records
- Write student records
- Automatic data persistence

---

## ✅ Input Validation

Current validations include:

- Duplicate Student ID detection
- Invalid menu choice handling
- Invalid numeric input handling

---

## 🎯 Learning Outcomes

This project is great for beginners learning:

- C++
- Object-Oriented Programming
- STL
- File Handling
- Console Applications
- Software Design Fundamentals

---

## 👨‍💻 Author

**Madhav Shukla**

Computer Science & Engineering (AI)

Passionate about
- C++
- Data Structures & Algorithms
- Data Analytics
- Software Development

---

⭐ If you found this project helpful, consider giving it a Star!