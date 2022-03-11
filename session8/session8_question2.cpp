#include <iostream>
#include <vector>
#include <string>

class Student {
private:
    std::string name;
    unsigned testScore;
public:
    Student(std::string n = "", unsigned int ts = 0);
    void setName(std::string name);
    void setTestScore(unsigned testScore);
    std::string getName() const;
    unsigned getTestScore() const;
};

Student::Student(std::string n, unsigned int ts) : name(n), testScore(ts) {}
void Student::setName(std::string name) {
    this->name = name;
}
void Student::setTestScore(unsigned testScore) {
    this->testScore = testScore;
}
std::string Student::getName() const {
    return this->name;
}
unsigned Student::getTestScore() const {
    return this->testScore;
}

double getAverage(std::vector<Student> Students) {
    double average = 0;
    for (int i = 0; i < Students.size(); i++) {
        average += Students[i].getTestScore();
    }
    return average / Students.size();
}

std::vector<std::string> getBelowAverageStudent(std::vector<Student> Students) {
    double average = getAverage(Students);
    std::vector<std::string> belowAverageStudent;
    for (int i = 0; i < Students.size(); i++) {
        if (Students[i].getTestScore() < average) {
            belowAverageStudent.push_back(Students[i].getName());
        }
    }
    return belowAverageStudent;
}

std::vector<std::string> getHighestStudent(std::vector<Student> Students) {
    unsigned int max_score = 0;
    for (int i = 0; i < Students.size(); i++) {
        if (max_score < Students[i].getTestScore()) {
            max_score = Students[i].getTestScore();
        }
    }
    std::vector<std::string> highestStudent;
    for (int i = 0; i < Students.size(); i++) {
        if (max_score == Students[i].getTestScore()) {
            highestStudent.push_back(Students[i].getName());
        }
    }
    return highestStudent;
}

int main()
{
    int N_STUDENTS;
    std::cout << "Enter number of students: ";
    std::cin >> N_STUDENTS;
    std::cin.get();
    int temp_score;
    std::vector<Student> Students(N_STUDENTS);
    std::string temp_name;


    for (int i = 0; i < N_STUDENTS; i++) {
        std::cout << "Enter name: ";
        std::getline(std::cin, temp_name);
        Students[i].setName(temp_name);
        std::cout << "Enter score: ";
        std::cin >> temp_score;
        std::cin.get();
        Students[i].setTestScore(temp_score);
    }

    std::cout << "Average: " << getAverage(Students) << "\n";
    std::cout << "Congratulations to people with the highest scores:\n";
    std::vector<std::string> highestStudent = getHighestStudent(Students);
    for (int i = 0; i < highestStudent.size(); i++) {
        std::cout << highestStudent[i] << '\n';
    }
    std::cout << "Students with below average scores:\n";
    std::vector<std::string> belowAverageStudent = getBelowAverageStudent(Students);
    for (int i = 0; i < belowAverageStudent.size(); i++) {
        std::cout << belowAverageStudent[i] << '\n';
    }
    
}