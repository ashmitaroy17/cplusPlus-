#include <iostream>

class Student {
public:
    int age;
    char name[20];

    // Constructor
    Student(int a, const char n[]) {
        age = a;

        int i = 0;
        while (n[i] != '\0') {
            name[i] = n[i];
            i++;
        }
        name[i] = '\0';
    }

    void display() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
    }
};

int main() {
    // All values assigned together 👇
    Student s1(21, "Ashmita");

    s1.display();
    return 0;
}
