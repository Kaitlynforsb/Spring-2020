/* Kaitlyn Forsberg
 * This program keeps track of a list of tasks. The user can view pending tasks, add and
 * complete tasks, and view a history of completed tasks.
 */

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

class Task {
private:
	string description;
	bool complete;
public:
	Task(string description_param, bool complete_param) {
		set_desc(description_param);
		set_complete(complete_param);
	}

	void set_desc(string description_param) {
		description = description_param;
	} 

	void set_complete(bool complete_param) {
		complete = complete_param;
	}

	string get_desc() {
		return description;
	}
	
	bool get_complete() {
		return complete;
	}

	friend ostream& operator<< (ostream& out, Task& task) {
        	out << task.description; 
		return out;
	} 
};

class TaskList {
private:
	vector<Task> tasks;
public:
	void operator+=(Task param) {
		tasks.push_back(param);		
	}

	
	Task &operator[](int index) {
			return tasks[index];	
	}

	int get_size() {
		return tasks.size();
	}
};

class TaskIO {
public:
	static TaskList read_file() {
		
		ifstream read;
		read.open("task_list.txt");

		string description;
		string comp;
		bool completed;
		TaskList list;	
			
		while(getline(read, description, '\t')) {
			
				getline(read, comp, '\n');

				if(comp == "1") {
					completed = 1;
				}		
				else {
					completed = 0;
				}	
	
				Task task(description, completed);
				list += task;			
		}
		read.close();
		return list;
		
	}
	

	static void write_file(TaskList list_param) {

		ofstream write;
		write.open("task_list.txt");
		
		int i;
		
		while(true) {
				
			for(i = 0; i < list_param.get_size(); i++) {
				write << list_param[i] << '\t' << list_param[i].get_complete() << endl;
			}	
			break;
		}
		
		write.close();
	}  
};

/*
ostream& operator<< (ostream &out, const Task &task) {
	out << "Description: " << task.description << endl;
	out << "Completed: " << task.complete << endl;
	return out;
}
*/

int main()
 {
	cout << endl;
	cout << "Task List" << endl << endl <<
		"COMMANDS: " << endl <<
		"v - View pending tasks" << endl <<
		"a - Add a task" << endl <<
		"c - Complete a task" << endl <<
		"h - History of completed tasks" << endl <<
		"x - Exit" << endl << endl;

	char option = 'v';

	TaskList task = TaskIO::read_file();

	while(true) {

	cout << "Command: ";
	cin >> option;
	cin.ignore();
	string descrip;
	int i, j, num;

	//performs each task based on user input
	switch(option) {
		case 'v': {
			j = 1; 
			for(i = 0; i < task.get_size(); i++) {
				if(task[i].get_complete() == 0) {
					cout << j << ". " << task[i] << endl;
					j++;
				}
			}	
			cout << endl;
			break;
		 }  	
		case 'a': {
			cout << "Description: ";
			getline(cin, descrip);
			cout << endl;
			Task ta(descrip, 0);
			task+=ta;
			break;
		 }
		case 'c': {
			j = 1;  
			cout << "Number: ";
			cin >> num;
			cin.ignore();
			while(num <= 0 || num > task.get_size()) {
				cout << "Invalid range. Please re-enter the value." << endl;
				cin >> num;
			}
			cout << endl;
			for(i = 0; i < task.get_size(); i++) {
				if(task[i].get_complete() == 0) {
					if(num == j) {
						task[i].set_complete(1);
						break;
					}
				j++; 	
				}
			}
		
			break;
		}
		case 'h': {
			j = 1;
                        for(i = 0; i < task.get_size(); i++) {
                                if(task[i].get_complete() == 1) {
					cout << j << ". " << task[i] << " (DONE!)" << endl; 
					j++;
				}		
			}
			cout << endl;
			break;
		}
		case 'x': {
			cout << endl << "Bye!" << endl << endl;
			TaskIO::write_file(task);
			return 0;
		}
	} //end switch




	} //end while loop 

	return 0;
} //end main
