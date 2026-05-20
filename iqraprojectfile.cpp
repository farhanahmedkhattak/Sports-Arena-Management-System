#include <iostream>
#include <string>
using namespace std;

// -------------------- Base Class --------------------
class Person {         //class person
protected:
    string name;
    int age;
    string contactNo;
    string email;
    
public:
    Person() {        //default constructor
        name = "";
        age = 0;
        contactNo = "";
        email = "";
    }

    void setInfo(string n, int a, string c, string e) {         //parameterized constructor
        name = n;
        age = a;
        contactNo = c;
        email = e;
    }

    void getInfo() {
        cout << "\n----- Person Info -----" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Contact No: " << contactNo << endl;
        cout << "Email: " << email << endl;
    }

    void login() {
        cout << name << " logged in successfully." << endl;
    }

    void logout() {
        cout << name << " logged out successfully." << endl;
    }
};

// -------------------- Staff Class --------------------
class Staff : public Person {
protected:
    double salary;
    string assignedTask;
    bool attendance;

public:
    Staff() {
        salary = 0;
        assignedTask = "None";
        attendance = false;
    }

    void setSalary(double s) {
        salary = s;
    }

    double getSalary() {
        return salary;
    }

    void assignTask(string task) {
        assignedTask = task;
        cout << "\nTask Assigned to Staff: " << assignedTask << endl;
    }

    void clockIn() {
        attendance = true;
        cout << "\nStaff Clocked In (Attendance Marked)." << endl;
    }

    void clockOut() {
        attendance = false;
        cout << "\nStaff Clocked Out." << endl;
    }

    void viewPayslip() {
        cout << "\n----- Payslip -----" << endl;
        cout << "Staff Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }
};

// -------------------- Manager Class --------------------
class Manager : public Staff {
private:
    string rules;

public:
    Manager() {
        rules = "No Rules Set";
    }

    void approveBooking() {
        cout << "\nManager Approved Booking Successfully." << endl;
    }

    void manageStaff() {
        cout << "\nManager is Managing Staff Members." << endl;
    }

    void viewReports() {
        cout << "\n----- Manager Report -----" << endl;
        cout << "Manager Name: " << name << endl;
        cout << "Assigned Task: " << assignedTask << endl;
        cout << "Salary (Protected): " << salary << endl;
        cout << "Rules: " << rules << endl;
    }

    void setRules(string r) {
        rules = r;
        cout << "\nManager Set Rules: " << rules << endl;
    }
};

// -------------------- Testing Main --------------------
int main() {
    Manager m;

    m.setInfo("IQRA", 20, "0300-0000000", "iqra@gmail.com");
    m.setSalary(50000);

    m.login();
    m.getInfo();

    m.assignTask("Manage Attendance System");
    m.clockIn();

    m.setRules("Staff must clock in before 9 AM.");
    m.approveBooking();
    m.manageStaff();
    m.viewPayslip();
    m.viewReports();

    m.clockOut();
    m.logout();

    return 0;
}