/* Kaitlyn Forsberg
 * This program creates customer and employee objects based on the input
 * given by the user. Both customer and employee objects store a first and last
 * name, and email. The customer object can also store a customer number and
 * the employee object can store a SSN
 */

#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
	string first;
	string last;
	string email;
public:
	string full_name(string first, string last) {
		return first + " " + last;
	}
	
	void set_first(string first_param) {
		first = first_param;
	}

	void set_last(string last_param) {
                last = last_param;
        }

	void set_email(string email_param) {
                email = email_param;
        }
	
	string get_email() {
		return email;
	}
};

class Customer : public Person {
protected:
	string cust_num;
public:
	void set_cust_num(string num_param){
		cust_num = num_param;
	} 	

	string get_cust_num(){
		return cust_num;
	}
};

class Employee : public Person {
protected:
	string SSN;
public:
	void set_SSN(string SSN_param) {
		SSN = SSN_param;
	}

	string get_SSN() {
		return SSN;
	}
};


int main() 
{
	cout << endl;
	cout << "Customer/Employee Data Entry" << endl << endl;

	char cont = 'y';
	
while (cont == 'y') {

	cout << endl;

	char choice;
	cout << "Customer or employee? (c/e): ";
	cin >> choice;

	cout << endl;
	cout << "DATA ENTRY" << endl << endl;

	string first_name, last_name, email_address;
	cout << "First name: ";
	cin >> first_name;
	cout << "Last name: ";
	cin >> last_name;
	cout << "Email: ";
	cin >> email_address;

	//sets all members for the customer and employee objects and prints them
	if (choice == 'c') {
		//creates Customer object
		Customer customer;		
		
		customer.set_first(first_name);
		customer.set_last(last_name);
		customer.set_email(email_address);

		string number;
		cout << "Number: ";
		cin >> number;

		customer.set_cust_num(number);

		cout << endl;
		cout << "CUSTOMER" << endl;
		cout << "Name: " << customer.full_name(first_name, last_name) << endl
		     << "Email: " << customer.get_email() << endl
		     << "Number: " << customer.get_cust_num() << endl << endl;
		
	}
	else {
		//creates Employee object
		Employee employee;

		employee.set_first(first_name);
                employee.set_last(last_name);
                employee.set_email(email_address);
		
		string SOC;
		cout << "SSN: ";
		cin >> SOC;

		employee.set_SSN(SOC);
		
		cout << endl;
		cout << "EMPLOYEE" << endl;
		cout << "Name: " << employee.full_name(first_name, last_name) << endl
		     << "Email: " << employee.get_email() << endl
		     << "SSN: " << employee.get_SSN() << endl << endl;
	}


	cout << "Continue? (y/n): ";
	cin >> cont;

} //end while 

	cout << endl;
	cout << "Bye!" << endl << endl;

	return 0;
}
