#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>

void displayEmployees(){
    std::cout << "First Name  |" << "Last Name  |" << "SSN  |" << "Salary  \n";
    std::cout << "++++++++++++++++++++++++++++++++++++++++++";
    std::ifstream empfile;
    empfile.open("C:/Users/laser/Desktop/C++/OOP Practice File/EMS.txt");
    if (empfile.is_open()){
        std::string tp;
        while(getline(empfile, tp)){
            std::cout << tp << "\n";
        }
    }
}

class menu{
    private:
    public:

    //subclass dealing with salaries
    class salarySlip{
        private:
        int salary;
        std::vector<std::string> userinfo;
        std::string ssn,fname,lname;        
        public:
        salarySlip(){
            std::cout<< "What is the ssn associated with the employee?";
            std::cin>> ssn;
        }
        void getsalary(){
            std::string ssalary;
            std::ifstream empfile;
            empfile.open("C:/Users/laser/Desktop/C++/OOP Practice File/EMS.txt");
            if (empfile.is_open()){
            std::string tp;
            while(getline(empfile, tp)){
                if (tp.find(ssn) != std::string::npos) {
                std::string arr[4];
                int i = 0;
                std::stringstream ssin(tp);
                // the next while loop puts the string tp into a list, we can probably delete the count variable since it's not needed
                while(ssin.good() && i < 4){
                    ssin >> arr[i];
                    i++;
                    }
                    fname = arr[0];
                    lname = arr[1];
                    ssalary = arr[3];
            }
            
        }
        std::cout << ssalary;
        salary = std::stod(ssalary);
        }
        }
        void printSalarySlip(){
            int hours;
            std::cout << "What is the number of hours worked this week?: ";
            std::cin >> hours;
            std::cout << fname << " " << lname << "'s current salary is:" << salary <<"\n";
            std::cout << "+++++++++++++++++++++++++++++++++++++++++++++\n";
            std::cout << "The total un-taxed pay for this week is:" << salary*hours << "\n";
            std::cout << "+++++++++++++++++++++++++++++++++++++++++++++\n";
            std::cout << "The total taxed pay for this week is: " << salary*hours*.98 << "\n";
            std::cout << "+++++++++++++++++++++++++++++++++++++++++++++\n";
        }
    };


    //subclass dealing with employees
    class employee{
        private:
        //private info
        std::string fname,lname,ssn, salary, yn;
        public:        
        void filein(){
            //attempts to file the private info THIS WONT WORK
            std::ofstream empfile;
            empfile.open("C:/Users/laser/Desktop/C++/OOP Practice File/EMS.txt" ,std::ios_base::app);
            if (empfile.is_open()){
                empfile << fname << " " << lname << " " << ssn << " " << salary << "\n";
                empfile.close();
                }
            }  
        void newEmployee(){
            // constructor to get info for private
            bool status = false;
            while (status != true){
                std::cout << "Enter the employees first name";
                std::cin >> fname;
                std::cout << "Enter the employees last name";
                std::cin >> lname;
                std::cout << "Enter the employees social security number";
                std::cin >> ssn;
                while (ssn.size() != 9){
                    std::cout << "Invalid Number, Try again: ";
                    std::cin >> ssn;
                }
                std::cout << "What is the employees current salary?";
                std::cin >> salary;

                std::cout << "Can you confirm the information?" << "\n" << fname << " " << lname << " " << ssn << " " << salary << " [y/n]";
                std::cin >> yn;
                if (yn == "y"){
                    status = true;
                }
                else{
                    status = status;
                }
            }
        filein();
        }

    };
};

int main(){
    menu::employee emp;
    emp.newEmployee();
}