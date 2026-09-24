#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cctype>
#include <windows.h>

using namespace std;

struct Course
{
	string name;
	string grade;
	int creditHours;
	double gradePoint;
};

void color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void errorMessage(string message)
{
	color(12);
	cout << "\nERROR: " << message << "\n";
	color(7);

	Sleep(2000);
	system("cls");
}

double getGradePoint(string grade)
{
	if (grade == "A+" || grade == "A")
		return 4.0;
	else if (grade == "A-")
		return 3.7;
	else if (grade == "B+")
		return 3.3;
	else if (grade == "B")
		return 3.0;
	else if (grade == "B-")
		return 2.7;
	else if (grade == "C+")
		return 2.3;
	else if (grade == "C")
		return 2.0;
	else if (grade == "C-")
		return 1.7;
	else if (grade == "D+")
		return 1.3;
	else if (grade == "D")
		return 1.0;
	else if (grade == "F")
		return 0.0;
	else
		return -1;
}

bool validCourseName(string name)
{
	if (name.empty())
		return false;

	bool hasLetter = false;

	for (char ch : name)
	{
		if (isalpha(ch))
			hasLetter = true;

		if (isdigit(ch))
			return false;
	}

	return hasLetter;
}

int main()
{
	int n;

	system("cls");

	color(11);
	cout << "===============================================================\n";
	cout << "                       CGPA CALCULATOR\n";
	cout << "===============================================================\n";
	color(7);

	while (true)
	{
		cout << "\nEnter number of courses: ";

		string input;
		getline(cin, input);

		stringstream ss(input);

		if (ss >> n && ss.eof() && n > 0 && n <= 20)
			break;

		errorMessage(
			"Number of courses must be a whole number between 1 and 20."
		);

		color(11);
		cout << "                       CGPA CALCULATOR\n";
		color(7);
	}

	Course* courses = new Course[n];

	double totalCredits = 0;
	double totalGradePoints = 0;

	for (int i = 0; i < n; i++)
	{
		system("cls");

		color(11);
		cout << "===============================================================\n";
		cout << "                       COURSE " << i + 1 << "\n";
		cout << "===============================================================\n";
		color(7);

		while (true)
		{
			cout << "\nEnter course name: ";
			getline(cin, courses[i].name);

			if (validCourseName(courses[i].name))
				break;

			errorMessage(
				"Invalid course name. Please enter a course name using letters only. "
				"Numbers are not allowed. Example: Programming Fundamentals."
			);

			color(11);
			cout << "                       COURSE " << i + 1 << "\n";
			color(7);
		}

		while (true)
		{
			cout << "\nEnter grade (A+, A, A-, B+, B, B-, C+, C, C-, D+, D, F): ";
			getline(cin, courses[i].grade);

			if (getGradePoint(courses[i].grade) != -1)
			{
				courses[i].gradePoint =
					getGradePoint(courses[i].grade);

				break;
			}

			errorMessage(
				"Invalid grade. Please enter A+, A, A-, B+, B, B-, "
				"C+, C, C-, D+, D or F."
			);

			cout << "Course Name: "
				<< courses[i].name << "\n";
		}

		while (true)
		{
			cout << "\nEnter credit hours (1-6): ";

			string input;
			getline(cin, input);

			stringstream ss(input);

			if (ss >> courses[i].creditHours &&
				ss.eof() &&
				courses[i].creditHours >= 1 &&
				courses[i].creditHours <= 6)
			{
				break;
			}

			errorMessage(
				"Credit hours must be a whole number from 1 to 6. "
				"Example: enter 3 for a 3-credit-hour course."
			);

			cout << "Course Name: "
				<< courses[i].name << "\n";

			cout << "Grade: "
				<< courses[i].grade << "\n";
		}

		totalCredits += courses[i].creditHours;

		totalGradePoints +=
			courses[i].gradePoint *
			courses[i].creditHours;
	}

	double semesterGPA =
		totalGradePoints / totalCredits;

	system("cls");

	color(10);
	cout << "===============================================================\n";
	cout << "                         COURSE RESULTS\n";
	cout << "===============================================================\n";
	color(7);

	cout << "\n";

	color(14);

	cout << left
		<< setw(25) << "Course Name"
		<< setw(10) << "Grade"
		<< setw(15) << "Credits"
		<< setw(15) << "Grade Point"
		<< setw(18) << "Quality Points"
		<< "\n";

	color(11);

	cout << "--------------------------------------------------------------------------------\n";

	color(7);

	for (int i = 0; i < n; i++)
	{
		double qualityPoints =
			courses[i].gradePoint *
			courses[i].creditHours;

		cout << left
			<< setw(25) << courses[i].name
			<< setw(10) << courses[i].grade
			<< setw(15) << courses[i].creditHours
			<< setw(15) << fixed << setprecision(2)
			<< courses[i].gradePoint
			<< setw(18) << qualityPoints
			<< "\n";
	}

	color(11);

	cout << "--------------------------------------------------------------------------------\n";

	color(7);

	cout << "\nTotal Credit Hours : "
		<< totalCredits;

	cout << "\nTotal Grade Points : "
		<< fixed << setprecision(2)
		<< totalGradePoints;

	color(10);

	cout << "\nSemester GPA       : "
		<< fixed << setprecision(2)
		<< semesterGPA;

	color(7);

	double previousCGPA;
	int previousCredits;

	cout << "\n\n";

	color(14);
	cout << "===============================================================\n";
	cout << "                  OVERALL CGPA CALCULATION\n";
	cout << "===============================================================\n";
	color(7);

	while (true)
	{
		cout << "\nEnter previous CGPA (0 if first semester): ";

		string input;
		getline(cin, input);

		stringstream ss(input);

		if (ss >> previousCGPA &&
			ss.eof() &&
			previousCGPA >= 0 &&
			previousCGPA <= 4)
		{
			break;
		}

		errorMessage(
			"Previous CGPA must be a number between 0.00 and 4.00. "
			"Example: 3.25."
		);

		cout << "OVERALL CGPA CALCULATION\n";
	}

	while (true)
	{
		cout << "\nEnter previous total credit hours "
			<< "(0 if first semester): ";

		string input;
		getline(cin, input);

		stringstream ss(input);

		if (ss >> previousCredits &&
			ss.eof() &&
			previousCredits >= 0)
		{
			break;
		}

		errorMessage(
			"Previous credit hours must be a positive whole number or 0."
		);

		cout << "OVERALL CGPA CALCULATION\n";
	}

	double overallCGPA;

	if (previousCredits == 0)
	{
		overallCGPA = semesterGPA;
	}
	else
	{
		overallCGPA =
			((previousCGPA * previousCredits) +
				totalGradePoints) /
				(previousCredits + totalCredits);
	}

	cout << "\n";

	color(10);

	cout << "===============================================================\n";
	cout << "                         FINAL RESULT\n";
	cout << "===============================================================\n";

	cout << left
		<< setw(25) << "Semester GPA"
		<< ": "
		<< fixed << setprecision(2)
		<< semesterGPA << "\n";

	cout << left
		<< setw(25) << "Overall CGPA"
		<< ": "
		<< fixed << setprecision(2)
		<< overallCGPA << "\n";

	cout << "===============================================================\n";

	color(7);

	delete[] courses;

	cout << "\nPress Enter to exit...";
	cin.get();

	return 0;
}