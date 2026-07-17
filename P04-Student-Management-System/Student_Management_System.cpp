#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

class Student {
private:
    int id;
    std::string name;
    int age;
    std::string course;

public:

    Student(
        const int &id, const std::string &name,
        const int &age, const std::string &course
    ) {
        this->id = id;
        this->name = name;
        this->age = age;
        this->course = course;
    }

    int getId() const { return id; }
    std::string getName() const { return name; }
    int getAge() const { return age; }
    std::string getCourse() const { return course; }

    void displayRow() const {
        std::cout << std::left << std::setw(10) << id
                  << std::setw(25) << name 
                  << std::setw(10) << age 
                  << std::setw(20) << course << "\n";
    }
};

std::string spaces(const int x, const char ch) {
    std::string spaces = "";
    for (int i=0; i<x; i++) {
        spaces += ch;
    }
    return spaces;
}

void addStudent(std::vector<Student>& students);
void displayAllStudents(const std::vector<Student>& students);
void searchStudent(const std::vector<Student>& students);
void saveToFile(const std::vector<Student>& students);
void loadFromFile(std::vector<Student>& students);

int main() {
    std::vector<Student> students;
    
    // Load existing records at startup
    loadFromFile(students);

    std::cout<<"\n"<<spaces(80,'=')<<"\n";
    std::cout<<spaces(27,' ')<<"STUDENT MANAGEMENT SYSTEM"<<std::endl;
    std::cout<<spaces(80,'=')<<"\n";
    std::cout<<spaces(25,' ')<<"1. Add New Student"<<std::endl;
    std::cout<<spaces(25,' ')<<"2. Display All Students"<<std::endl;
    std::cout<<spaces(25,' ')<<"3. Search Student by ID"<<std::endl;
    std::cout<<spaces(25,' ')<<"4. Save and Exit\n"<<std::endl;
    int choice;

    do {
        std::cout<<spaces(80,'=')<<std::endl;
        std::cout<<spaces(5,' ')<<" >> Enter to Perform (1-4) : ";
        std::cin>>choice;
        std::cout<<spaces(80,'-')<<std::endl;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout<<" -->> Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3:
                searchStudent(students);
                break;
            case 4:
                saveToFile(students);
                std::cout<<"\n"<<spaces(5,' ')<<" -->> Data saved successfully. Goodbye!"<<std::endl;
                std::cout<<spaces(80,'=')<<std::endl;
                break;
            default:
                std::cout<<" -->> Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

void addStudent(std::vector<Student>& students) {
    int id, age;
    std::string name, course;

    std::cout<<"\n"<<spaces(15,' ')<<"Enter Student ID : ";
    std::cin >> id;

    for (const auto& s : students) {
        if (s.getId() == id) {
            std::cout<<" -->> Error: A student with this ID already exists!\n";
            return;
        }
    }

    std::cin.ignore();
    std::cout<<spaces(15,' ')<<"Enter Student Name: ";
    std::getline(std::cin, name);

    std::cout<<spaces(15,' ')<<"Enter Student Age: ";
    std::cin >> age;

    std::cin.ignore();
    std::cout<<spaces(15,' ')<<"Enter Course: ";
    std::getline(std::cin, course);

    students.push_back(Student(id, name, age, course));
    std::cout<<"\n"<<spaces(10,' ')<<"Student added successfully!\n";
}

void displayAllStudents(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "\nNo student records found.\n";
        return;
    }

    std::cout << "\n"<<spaces(10,' ')<<spaces(60,'=')<<"\n";
    std::cout<<spaces(10,' ')<<std::left << std::setw(10) << " ID"
             <<std::setw(25) << "Name"
             <<std::setw(10) << "Age"
             <<std::setw(20) << "Course"<<"\n";
    std::cout<<spaces(10,' ')<<spaces(60,'-')<<"\n";
    
    for (const auto& student : students) {
        std::cout<<spaces(10,' ');
        student.displayRow();
    }
    std::cout<<spaces(10,' ')<<spaces(60,'=')<<"\n"<<std::endl;
}

void searchStudent(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "\n -->> No records available to search.\n";
        return;
    }

    int searchId;
    std::cout << "\nEnter Student ID to search: ";
    std::cin >> searchId;

    for (const auto& student : students) {
        if (student.getId() == searchId) {
            std::cout<<""<<spaces(10,' ')<<"Record Found:\n";
            std::cout<<spaces(10,' ')<<spaces(40,'=')<<"\n";
            std::cout<<spaces(10,' ')<<" Student ID:\t\t" <<student.getId()<<"\n";
            std::cout<<spaces(10,' ')<<" Name: \t\t" <<student.getName()<<"\n";
            std::cout<<spaces(10,' ')<<" Age:  \t\t" <<student.getAge()<<"\n";
            std::cout<<spaces(10,' ')<<" Course:\t\t"<<student.getCourse()<<"\n";
            std::cout<<spaces(10,' ')<<spaces(40,'=')<<"\n"<<std::endl;
            return;
        }
    }
    std::cout<<" -->> Student with ID " << searchId << " not found.\n";
}

void saveToFile(const std::vector<Student>& students) {
    std::ofstream outFile("./data/students.txt");
    if (!outFile) {
        std::cerr << " -->> Error opening file for writing!\n";
        return;
    }

    for (const auto& s : students) {
        outFile << s.getId() << "\t" 
                << s.getName() << "\t" 
                << s.getAge() << "\t" 
                << s.getCourse() << "\n";
    }
    outFile.close();
}

void loadFromFile(std::vector<Student>& students) {
    std::ifstream inFile("./data/students.txt");
    if (!inFile) {
        return;
    }

    int id, age;
    std::string name, course;

    while (inFile >> id) {
        inFile.ignore();
        std::getline(inFile, name, '\t');
        inFile >> age;
        inFile.ignore();
        std::getline(inFile, course, '\n');

        students.push_back(Student(id, name, age, course));
    }
    inFile.close();
}