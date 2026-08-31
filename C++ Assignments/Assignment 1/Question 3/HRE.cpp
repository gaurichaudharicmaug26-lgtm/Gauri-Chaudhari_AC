#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Employee
{
private:
    int empId;
    string name;
    string department;
    char grade;
    double basicSalary;
    bool isActive;

    static int employeeCount;

public:

    // Constructor
    Employee()
    {
        empId = 1001 + employeeCount;
        employeeCount++;

        name = "";
        department = "";
        grade = 'D';
        basicSalary = 10001;
        isActive = true;
    }

    // Setter for name
    void setName(const string& n)
    {
        if (n.empty())
        {
            cout << "ERROR: Name cannot be empty. Value rejected." << endl;
        }
        else
        {
            name = n;
        }
    }

    // Setter for department
    void setDepartment(const string& dept)
    {
        if (dept == "Engineering" ||
            dept == "HR" ||
            dept == "Finance" ||
            dept == "Operations")
        {
            department = dept;
        }
        else
        {
            cout << "ERROR: '" << dept
                 << "' is not a registered department." << endl;
        }
    }

    // Setter for grade
    void setGrade(char g)
    {
        if (g == 'A' || g == 'B' || g == 'C' || g == 'D')
        {
            grade = g;
        }
        else
        {
            cout << "ERROR: Invalid grade '" << g
                 << "'. Accepted values: A, B, C, D." << endl;
        }
    }

    // Setter for salary
    void setBasicSalary(double salary)
    {
        if (salary > 10000 && salary < 500000)
        {
            basicSalary = salary;
        }
        else
        {
            cout << "ERROR: Salary must be between Rs.10,000 "
                 << "and Rs.5,00,000. Value rejected." << endl;
        }
    }

    // Deactivate employee
    void deactivate()
    {
        isActive = false;
    }

    // Getters
    int getEmpId() const
    {
        return empId;
    }

    string getName() const
    {
        return name;
    }

    string getDepartment() const
    {
        return department;
    }

    char getGrade() const
    {
        return grade;
    }

    double getBasicSalary() const
    {
        return basicSalary;
    }

    bool getIsActive() const
    {
        return isActive;
    }

    // Calculate allowances
    double computeAllowances() const
    {
        if (grade == 'A')
            return basicSalary * 0.40;

        if (grade == 'B')
            return basicSalary * 0.30;

        if (grade == 'C')
            return basicSalary * 0.20;

        return basicSalary * 0.10;
    }

    // Calculate gross salary
    double computeGrossSalary() const
    {
        return basicSalary + computeAllowances();
    }

    // Calculate tax
    double computeTax() const
    {
        double gross = computeGrossSalary();

        if (gross <= 50000)
        {
            return 0;
        }
        else if (gross <= 100000)
        {
            return (gross - 50000) * 0.10;
        }
        else
        {
            return 5000 + (gross - 100000) * 0.20;
        }
    }

    // Calculate net salary
    double computeNetSalary() const
    {
        return computeGrossSalary() - computeTax();
    }

    // Accept employee details
    void acceptDetails()
    {
        string n;
        string dept;
        char g;
        double salary;

        // Name
        do
        {
            cout << "Enter name: ";
            getline(cin >> ws, n);

            if (n.empty())
                cout << "ERROR: Name cannot be empty. Value rejected." << endl;
            else
                setName(n);

        } while (n.empty());


        // Department
        do
        {
            cout << "Enter department: ";
            cin >> dept;

            if (dept == "Engineering" ||
                dept == "HR" ||
                dept == "Finance" ||
                dept == "Operations")
            {
                setDepartment(dept);
                break;
            }
            else
            {
                setDepartment(dept);
            }

        } while (true);


        // Grade
        do
        {
            cout << "Enter grade: ";
            cin >> g;

            if (g == 'A' || g == 'B' || g == 'C' || g == 'D')
            {
                setGrade(g);
                break;
            }
            else
            {
                setGrade(g);
            }

        } while (true);


        // Basic salary
        do
        {
            cout << "Enter basic salary: ";
            cin >> salary;

            if (salary > 10000 && salary < 500000)
            {
                setBasicSalary(salary);
                break;
            }
            else
            {
                setBasicSalary(salary);
            }

        } while (true);
    }

    // Print payslip
    void printPayslip() const
    {
        cout << fixed << setprecision(2);

        cout << "\nEMPLOYEE PAYSLIP - AUG 2026" << endl;
        cout << "============================================" << endl;

        cout << "Emp ID      : " << empId << endl;
        cout << "Name        : " << name << endl;
        cout << "Department  : " << department << endl;
        cout << "Grade       : " << grade << endl;

        if (isActive)
            cout << "Status      : Active" << endl;
        else
            cout << "Status      : Inactive" << endl;

        cout << "--------------------------------------------" << endl;

        cout << "Basic Salary     : Rs. "
             << basicSalary << endl;

        cout << "Allowances ("
             << (grade == 'A' ? 40 :
                 grade == 'B' ? 30 :
                 grade == 'C' ? 20 : 10)
             << "%) : Rs. "
             << computeAllowances() << endl;

        cout << "Gross Salary     : Rs. "
             << computeGrossSalary() << endl;

        cout << "--------------------------------------------" << endl;

        cout << "Tax Deduction    : Rs. "
             << computeTax() << endl;

        cout << "Net Salary       : Rs. "
             << computeNetSalary() << endl;

        cout << "============================================" << endl;
    }

    // Static getter
    static int getEmployeeCount()
    {
        return employeeCount;
    }
};

// Initialize static member
int Employee::employeeCount = 0;


int main()
{
    // One object on stack
    Employee e1;

    // Two objects on heap
    Employee* e2 = new Employee();
    Employee* e3 = new Employee();

    // Accept details
    e1.acceptDetails();
    e2->acceptDetails();
    e3->acceptDetails();

    /*
       The following statements are invalid because
       empId and basicSalary are private.

       e1.empId = 999;
       e1.basicSalary = -1000;

       Private data members cannot be accessed directly.
       They must be accessed using public member functions.
    */

    // Print payslips
    e1.printPayslip();
    e2->printPayslip();
    e3->printPayslip();

    // Simulate resignation
    e3->deactivate();

    if (!e3->getIsActive())
    {
        cout << e3->getName()
             << " is no longer active. Payroll skipped."
             << endl;
    }

    // Display total employees
    cout << "Total Employees : "
         << Employee::getEmployeeCount() << endl;

    // Delete heap objects
    delete e2;
    delete e3;

    return 0;
}
