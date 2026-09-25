# 🎓 CGPA Calculator — CodeAlpha C++ Internship

A console-based **CGPA Calculator** developed in C++ as part of the **CodeAlpha C++ Programming Internship**. The application calculates semester GPA and overall CGPA using course grades, credit hours, and previous academic performance.

The project focuses on applying fundamental C++ programming concepts such as structures, dynamic memory, input validation, calculations, formatted output, and Windows console customization.

---

## 📌 Project Overview

The **CGPA Calculator** allows students to enter their courses, grades, and credit hours and then calculates:

* Total credit hours
* Total grade points
* Quality points for each course
* Semester GPA
* Overall CGPA based on previous academic records

The program also provides input validation to reduce incorrect entries and presents the final results in a clear tabular format.

---

## 🏢 Internship Information

**Internship:** CodeAlpha C++ Programming Internship
**Task:** Task 1 — CGPA Calculator
**Programming Language:** C++
**Application Type:** Console Application
**Platform:** Windows

---

## ✨ Key Features

### 📚 Course Management

* Enter up to **20 courses**.
* Enter a name for each course.
* Enter the grade achieved.
* Enter credit hours for every course.
* Calculate individual quality points.

### 🧮 GPA Calculation

* Calculates total credit hours.
* Calculates total grade points.
* Calculates semester GPA using weighted grade points.
* Calculates overall CGPA using previous CGPA and completed credit hours.

### 📊 Detailed Results

The program displays a formatted results table containing:

| Information    | Description                  |
| -------------- | ---------------------------- |
| Course Name    | Name of the course           |
| Grade          | Letter grade achieved        |
| Credits        | Credit hours                 |
| Grade Point    | Numerical value of the grade |
| Quality Points | Grade Point × Credit Hours   |

### ✅ Input Validation

The application validates:

* Number of courses
* Course names
* Grades
* Credit hours
* Previous CGPA
* Previous credit hours

Invalid input generates an error message and asks the user to enter the information again.

### 🎨 Console Interface

The program uses Windows console colors to separate:

* Titles
* Error messages
* Course information
* Results
* Final GPA/CGPA output

---

## 📐 Grade Point Scale

The calculator supports the following grading scale:

| Grade | Grade Point |
| ----- | ----------: |
| A+    |        4.00 |
| A     |        4.00 |
| A-    |        3.70 |
| B+    |        3.30 |
| B     |        3.00 |
| B-    |        2.70 |
| C+    |        2.30 |
| C     |        2.00 |
| C-    |        1.70 |
| D+    |        1.30 |
| D     |        1.00 |
| F     |        0.00 |

---

## 🧮 Calculation Method

### Quality Points

For every course:

```text
Quality Points = Grade Point × Credit Hours
```

### Semester GPA

```text
Semester GPA =
Total Grade Points ÷ Total Credit Hours
```

### Overall CGPA

If previous academic credits exist:

```text
Overall CGPA =
((Previous CGPA × Previous Credit Hours) + Current Grade Points)
÷
(Previous Credit Hours + Current Credit Hours)
```

If the student is in the first semester and enters `0` previous credit hours, the semester GPA is used as the overall CGPA.

---

## 🛠️ Technologies & Concepts Used

### Programming Language

* **C++**

### C++ Concepts

* Structures
* Functions
* Dynamic memory allocation
* Pointers
* Loops
* Conditional statements
* Strings
* Input validation
* Exception-safe input handling through validation logic
* Stream formatting
* String streams
* Character checking
* Arrays
* Basic console manipulation

### Libraries Used

```cpp
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cctype>
#include <windows.h>
```

---

## 🧱 Program Structure

The project uses a `Course` structure to store information for every subject.

```cpp
struct Course
{
    string name;
    string grade;
    int creditHours;
    double gradePoint;
};
```

Each course stores:

* Course name
* Letter grade
* Credit hours
* Grade point

The program dynamically creates an array according to the number of courses entered by the user.

---

## 🔄 Program Workflow

```text
Start
  │
  ▼
Enter Number of Courses
  │
  ▼
Validate Number of Courses
  │
  ▼
Enter Course Information
  │
  ├── Course Name
  ├── Grade
  └── Credit Hours
  │
  ▼
Calculate Quality Points
  │
  ▼
Calculate Total Credits
  │
  ▼
Calculate Semester GPA
  │
  ▼
Enter Previous CGPA
  │
  ▼
Enter Previous Credit Hours
  │
  ▼
Calculate Overall CGPA
  │
  ▼
Display Final Results
  │
  ▼
Exit
```

---

## 🛡️ Input Validation

The program includes several validation checks to make the calculator more reliable.

### Number of Courses

The number of courses must be:

```text
1 – 20
```

### Course Name

Course names:

* Cannot be empty.
* Must contain letters.
* Cannot contain digits.

Example:

```text
Programming Fundamentals
```

### Grade

Only supported grades are accepted:

```text
A+, A, A-, B+, B, B-, C+, C, C-, D+, D, F
```

### Credit Hours

Credit hours must be a whole number between:

```text
1 – 6
```

### Previous CGPA

The previous CGPA must be within:

```text
0.00 – 4.00
```

---

## 💻 Example Result

A simplified example of the results displayed by the program:

```text
===============================================================
                         COURSE RESULTS
===============================================================

Course Name              Grade     Credits        Grade Point
--------------------------------------------------------------------------------
Programming Fundamentals A         3              4.00
Discrete Structures      A-        3              3.70
Basic Electronics        B+        2              3.30
--------------------------------------------------------------------------------

Total Credit Hours : 8
Total Grade Points : 28.10
Semester GPA       : 3.51
```

The actual program also displays **quality points** for each course.

---

## 🖥️ Console Features

The program uses Windows console functionality through:

```cpp
#include <windows.h>
```

It provides:

* Colored text
* Error highlighting
* Screen clearing
* Delayed error messages
* Formatted result tables

The `color()` function is used to change the console text color.

---

## 📁 Project Structure

```text
CodeAlpha_CGPACalculator/
│── 1. Screenshot.jpg
│── 2. Screenshot.jpg
│── 3. Screenshot.jpg
│── 4. Screenshot.jpg
├── README.md
└── main.cpp
```

---

## ⚙️ Requirements

To run this project, you need:

* Windows operating system
* C++ compiler
* C++ compatible IDE or compiler
* Support for the Windows API

Recommended environments include:

* Visual Studio
* Code::Blocks with a suitable compiler
* Dev-C++
* MinGW/GCC on Windows

> **Note:** The program uses `windows.h`, so it is designed specifically for Windows environments.

---

## ▶️ How to Run

### 1. Clone the Repository

```bash
git clone YOUR-GITHUB-REPOSITORY-URL
```

### 2. Open the Project

Open the project in a C++ compatible IDE.

### 3. Compile

Compile the `main.cpp` file using a C++ compiler.

### 4. Run

Execute the program and follow the instructions displayed in the console.

---

## 📋 User Input Flow

The program asks the user for information in the following order:

```text
1. Number of courses
2. Course name
3. Grade
4. Credit hours
5. Previous CGPA
6. Previous total credit hours
```

After processing the information, the program displays the course-wise results followed by the semester GPA and overall CGPA.

---

## 🧠 Learning Outcomes

This project provided practical experience with:

* C++ structures
* Dynamic arrays
* Pointer-based memory management
* Weighted average calculations
* String processing
* Input validation
* Formatted console output
* Windows console functions
* Breaking a problem into reusable functions
* Building a complete console-based application

---

## 🚀 Possible Future Improvements

The current project can be expanded with features such as:

* Save results to a file
* Load previous semester records
* Support multiple semesters
* Generate academic reports
* Add a graphical user interface
* Add configurable grading scales
* Add course editing and deletion
* Export results to CSV or PDF
* Store complete academic history
* Add a menu-driven interface for repeated calculations

---

## ⚠️ Project Scope

This project is an **educational console-based CGPA calculator** created for the CodeAlpha C++ Programming Internship.

It is designed to demonstrate C++ programming and calculation logic rather than serve as an official university grading system.

---

## 👩‍💻 Author

**Maira Adil**

**BS Artificial Intelligence Student**
University of Central Punjab

### Connect

* **LinkedIn:** [(https://www.linkedin.com/in/mairaadil)]
* **GitHub:** [(https://github.com/MairaAdil)]
---

## 🏆 Internship Project

This project was developed as part of the:

**CodeAlpha C++ Programming Internship**

### Task 1 — CGPA Calculator

The project demonstrates the practical application of C++ programming concepts through a student-focused GPA and CGPA calculation system.

---

## 🙌 Acknowledgment

Thanks to **CodeAlpha** for providing the internship opportunity and a practical environment to develop and strengthen C++ programming skills through project-based tasks.

---

⭐ If you find this project useful or educational, consider giving the repository a star.
