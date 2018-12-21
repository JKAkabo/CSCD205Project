#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void printHeader()
{
	system("clear");
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "+            SCHOOL MANAGEMENT PROGRAM           +" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << endl;
}

string get_nth_column_from_csv_record(int column_number, string record)
{
	int i;
	int a = 0;
	int b = record.find(",");

	if(column_number > 1)
	{
		a = b;
		for(i = 2; i < column_number; i++)
		{
			a = record.find(",", a + 1);
		}
		b = record.find(",", a + 1);
		b = b - a -1;
		a++;
	}
	return record.substr(a, b);
}

struct Student
{
	string id;
	string first_name;
	string last_name;
	string gender;
	string level;
};
struct Teacher
{
	string id;
	string first_name;
	string last_name;
	string gender;
	string qualification;
	string subject;
	string experience;
	string salary;
};
int main()
{
	static int choice = -1;
	while(true)
	{
		printHeader();
		cout << "[1] Students' information" << endl;
		cout << "[2] Teachers' information" << endl;
		cout << "[3] Exit" << endl;
		cout << "> ";
		cin >> choice;
		if(choice == 1)
		{
			// display menu for students
			while(true)
			{
				printHeader();
				cout << "[1] Add Student" << endl;
				cout << "[2] Find and Display Student" << endl;
				cout << "[3] Edit Student" << endl;
				cout << "[4] Remove Student" << endl;
				cout << "[5] Back" << endl;
				cout << "[6] Exit" << endl;
				cout << "> ";
				choice = -1;
				cin >> choice;
				if(choice == 1)
				{
					// add student
					while(true)
					{
						printHeader();
						Student new_student;
						cout << "-----------------------------------------" << endl;
						cout << "Add New Student" << endl;
						cout << "-----------------------------------------" << endl;
						cout << "\nEnter Student's ID\n> ";
						cin >> new_student.id;
						cout << "\nEnter Student's First Name\n> ";
						cin >> new_student.first_name;
						cout << "\nEnter Student's Last Name\n> ";
						cin >> new_student.last_name;
						cout << "\nEnter Student's Gender\n> ";
						cin >> new_student.gender;
						cout << "\nEnter Student's Level\n> ";
						cout << "Options:" << endl;
						cout << "P1" << endl;
						cout << "P2" << endl;
						cout << "P3" << endl;
						cout << "P4" << endl;
						cout << "P5" << endl;
						cout << "P6" << endl;
						cout << "J1" << endl;
						cout << "J2" << endl;
						cout << "J3" << endl;
						cout << "> ";
						cin >> new_student.level;
						cout << "Confirm Add Operation" << endl;
						cout << "[0] No" << endl;
						cout << "[1] Yes" << endl;
						cout << "> ";
						choice = -1;
						cin >> choice;
						if(choice == 0)
						{
							continue;
						}
						else if(choice == 1)
						{
							ofstream fout;
							fout.open("students.csv", ios::app);
							fout << new_student.id << "," << new_student.first_name << "," << new_student.last_name << "," << new_student.gender << "," << new_student.level << endl;
							fout.close();
							cout << endl;
							cout << "Sucessfully added new student." << endl;
							cout << "Again?" << endl;
							cout << "[0] No" << endl;
							cout << "[1] Yes" << endl;
							cout << "> ";
							choice = -1;
							cin >> choice;
							if(choice == 1)
							{
								continue;
							}
							else
							{
								break;
							}
						}
					}
				}
				else if(choice == 2)
				{
					// find and display student
					while(true)
					{
						printHeader();
						cout << "----------------------------------------------" << endl;
						cout << "Find and Display Student" << endl;
						cout << "----------------------------------------------" << endl;
						string search_id;
						cout << "\nEnter id for search\n> ";
						cin >> search_id;
						ifstream fin("students.csv");
						string student_record;
						bool record_found = false;
						// ...
						while(getline(fin, student_record))
						{
							string student_id = get_nth_column_from_csv_record(1, student_record);
							if(search_id == student_id)
							{
								record_found = true;
								break;
							}
						}
						fin.close();
						printHeader();
						if(record_found)
						{
							Student student;
							student.id = get_nth_column_from_csv_record(1, student_record);
							student.first_name = get_nth_column_from_csv_record(2, student_record);
							student.last_name = get_nth_column_from_csv_record(3, student_record);
							student.gender = get_nth_column_from_csv_record(4, student_record);
							student.level = get_nth_column_from_csv_record(5, student_record);
							cout << "----------------------------------------------" << endl;
							cout << "Details for " << student.id << endl;
							cout << "----------------------------------------------" << endl;
							cout << setw(20) << "First Name" << setw(20) << student.first_name << endl;
							cout << setw(20) << "Last Name" << setw(20) << student.last_name << endl;
							cout << setw(20) << "Gender" << setw(20) << student.gender << endl;
							cout << setw(20) << "Level" << setw(20) << student.level << endl;
						}
						else
						{
							cout << "No record found" << endl;
						}
						cout << "Again?" << endl;
						cout << "[0] No" << endl;
						cout << "[1] Yes" << endl;
						cout << "> ";
						choice = -1;
						cin >> choice;
						if(choice == 1)
						{
							continue;
						}
						else
						{
							break;
						}
					}
				}
				else if(choice == 3)
				{
					// edit student;
					while(true)
					{
						printHeader();
						cout << "----------------------------------------------" << endl;
						cout << "Find and Display Student" << endl;
						cout << "----------------------------------------------" << endl;
						string search_id;
						cout << "\nEnter id to edit\n> ";
						cin >> search_id;
						ifstream fin("students.csv");
						ofstream fout;
						fout.open("temp.csv");
						string student_record;
						string cin_temp_str;
						bool record_found = false;
						// ...
						while(getline(fin, student_record))
						{
							string student_id = get_nth_column_from_csv_record(1, student_record);
							if(search_id == student_id)
							{
								Student target_student;
								record_found = true;
								printHeader();
								cout << "-----------------------------------------" << endl;
								cout << "Edit details for " << student_id << endl;
								cout << "-----------------------------------------" << endl;
								target_student.id = student_id;
								// edit first_name
								cout << "Enter student's first name. [#] to maintain previous data" << endl;
								target_student.first_name = get_nth_column_from_csv_record(2, student_record);
								cout << "\t Current = " << target_student.first_name << endl;
								cout << endl;
								cout << "> ";
								cin >> cin_temp_str;
								if(cin_temp_str != "#")
								{
									target_student.first_name = (cin_temp_str);
								}
								cout << endl;
								// edit last name
								cout << "Enter student's last name. [#] to maintain previous data" << endl;
								target_student.last_name = get_nth_column_from_csv_record(3, student_record);
								cout << "\t Current = " << target_student.last_name << endl;
								cout << endl;
								cout << "> ";
								cin >> cin_temp_str;
								if(cin_temp_str != "#")
								{
									target_student.last_name = cin_temp_str;
								}
								cout << endl;
									// edit gender
								cout << "Enter student's gender [M / F]. [#] to maintain previous data" << endl;
								target_student.gender = get_nth_column_from_csv_record(4, student_record);
								cout << "\t Current = " << target_student.gender << endl;
								cout << endl;
								cout << "> ";
								cin >> cin_temp_str;
								if(cin_temp_str != "#")
								{
									target_student.gender = cin_temp_str;
								}
								cout << endl;
								// edit level
								cout << "Enter student's level. [#] to maintain previous data" << endl;
								target_student.level = get_nth_column_from_csv_record(5, student_record);
								cout << "\t Current = " << target_student.level << endl;
								cout << "Options:" << endl;
								cout << "P1" << endl;
								cout << "P2" << endl;
								cout << "P3" << endl;
								cout << "P4" << endl;
								cout << "P5" << endl;
								cout << "P6" << endl;
								cout << "J1" << endl;
								cout << "J2" << endl;
								cout << "J3" << endl;
								cout << endl;
								cout << "> ";
								cin >> cin_temp_str;
								if(cin_temp_str != "#")
								{
									target_student.level = (cin_temp_str);
								}
								cout << endl;
								fout << target_student.id << "," << target_student.first_name << "," << target_student.last_name << "," << target_student.gender << "," << target_student.level << endl;
								continue;
							}
							fout << student_record << endl;
						}
						fin.close();
						fout.close();
						if(!record_found)
						{
							remove("temp.csv");
						}
						else
						{
							fin.open("temp.csv");
							fout.open("students.csv");
							while(getline(fin, student_record))
							{
								fout << student_record << endl;
							}
							fin.close();
							fout.close();
							remove("temp.csv");
						}
						cout << "Successfully editted record" << endl;
						cout << "Again?" << endl;
						cout << "[0] No" << endl;
						cout << "[1] Yes" << endl;
						cout << "> ";
						choice = -1;
						cin >> choice;
						if(choice == 1)
						{
							continue;
						}
						else
						{
							break;
						}
					}
				}
				else if(choice == 4)
				{
					// remove student;
					while(true)
					{
						printHeader();
						cout << "----------------------------------------------" << endl;
						cout << "Find and Display Student" << endl;
						cout << "----------------------------------------------" << endl;
						string search_id;
						cout << "\nEnter id to edit\n> ";
						cin >> search_id;
						ifstream fin("students.csv");
						ofstream fout;
						fout.open("temp.csv");
						string student_record;
						string cin_temp;
						bool record_found = false;
						// ...
						while(getline(fin, student_record))
						{
							string student_id = get_nth_column_from_csv_record(1, student_record);
							if((search_id) == student_id)
							{
								record_found = true;
								continue;
							}
							fout << student_record << endl;
						}
						fin.close();
						fout.close();
						if(!record_found)
						{
							remove("temp.csv");
						}
						else
						{
							fin.open("temp.csv");
							fout.open("students.csv");
							while(getline(fin, student_record))
							{
								fout << student_record << endl;
							}
							fin.close();
							fout.close();
							remove("temp.csv");
						}
						cout << "Successfully removed record" << endl;
						cout << "Again?" << endl;
						cout << "[0] No" << endl;
						cout << "[1] Yes" << endl;
						cout << "> ";
						choice = -1;
						cin >> choice;
						if(choice == 1)
						{
							continue;
						}
						else
						{
							break;
						}
					}
				}
				else if(choice == 5)
				{
					// previous menu
					break;
				}
				else if(choice == 6)
				{
					// exit
					exit(0);
				}
				else
				{
					 continue;
				}
			}
		}
		else if(choice == 2)
		{
			while(true)
			{
				printHeader();
				cout << "[1] Add Teacher" << endl;
				cout << "[2] Find and Display Teacher" << endl;
				cout << "[3] Edit Teacher" << endl;
				cout << "[4] Remove Teacher" << endl;
				cout << "[5] Back" << endl;
				cout << "[6] Exit" << endl;
				cout << "> ";
				choice = -1;
				cin >> choice;
				if(choice == 1)
				{
					// add student
					while(true)
					{
						printHeader();
						Teacher new_teacher;
						cout << "-----------------------------------------" << endl;
						cout << "Add New Teacher" << endl;
						cout << "-----------------------------------------" << endl;
						cout << "\nEnter Teacher's ID\n> ";
						cin >> new_teacher.id;
						cout << "\nEnter Teacher's First Name\n> ";
						cin >> new_teacher.first_name;
						cout << "\nEnter Teacher's Last Name\n> ";
						cin >> new_teacher.last_name;
						cout << "\nEnter Teacher's Gender\n> ";
						cin >> new_teacher.gender;
						cout << "\nEnter Teacher's Qualification\n> ";
						cout << "Options:" << endl;
						cout << "Bachelor" << endl;
						cout << "Master" << endl;
						cout << "Doctorate" << endl;
						cin >> new_teacher.qualification;
						cout << "\nEnter Teacher's Subject\n> ";
						cin >> new_teacher.subject;
						cout << "\nEnter Teacher's Experience (years)\n> ";
						cin >> new_teacher.experience;
						cout << "\nEnter Teacher's Salary\n> ";
						cin >> new_teacher.salary;
						cout << "Confirm Add Operation" << endl;
						cout << "[0] No" << endl;
						cout << "[1] Yes" << endl;
						cout << "> ";
						choice = -1;
						cin >> choice;
						if(choice == 0)
						{
							continue;
						}
						else if(choice == 1)
						{
							ofstream fout;
							fout.open("teachers.csv", ios::app);
							fout << new_teacher.id << "," << new_teacher.first_name << "," << new_teacher.last_name << "," << new_teacher.gender << "," << new_teacher.qualification << "," << new_teacher.subject << "," << new_teacher.experience << "," << new_teacher.salary << endl;
							fout.close();
						}
						cout << "Successfully added record" << endl;
						cout << "Again?" << endl;
						cout << "[0] No" << endl;
						cout << "[1] Yes" << endl;
						cout << "> ";
						choice = -1;
						cin >> choice;
						if(choice == 1)
						{
							continue;
						}
						else
						{
							break;
						}	
					}
				}
				else if(choice == 2)
				{
					// find and display student
					while(true)
					{
						printHeader();
						cout << "----------------------------------------------" << endl;
						cout << "Find and Display Teacher" << endl;
						cout << "----------------------------------------------" << endl;
						string search_id;
						cout << "\nEnter id for search\n> ";
						cin >> search_id;
						ifstream fin("teachers.csv");
						string teacher_record;
						bool record_found = false;
						// ...
						while(getline(fin, teacher_record))
						{
							string teacher_id = get_nth_column_from_csv_record(1, teacher_record);
							if(search_id == teacher_id)
							{
								record_found = true;
								break;
							}
						}
						fin.close();
						printHeader();
						if(record_found)
						{
							Teacher target_teacher;
							target_teacher.id = get_nth_column_from_csv_record(1, teacher_record);
							target_teacher.first_name = get_nth_column_from_csv_record(2, teacher_record);
							target_teacher.last_name = get_nth_column_from_csv_record(3, teacher_record);
							target_teacher.gender = get_nth_column_from_csv_record(4, teacher_record);
							target_teacher.qualification = get_nth_column_from_csv_record(5, teacher_record);
							target_teacher.subject = get_nth_column_from_csv_record(6, teacher_record);
							target_teacher.experience = get_nth_column_from_csv_record(7, teacher_record);
							target_teacher.salary = get_nth_column_from_csv_record(8, teacher_record);
							cout << "----------------------------------------------" << endl;
							cout << "Details for " << target_teacher.id << endl;
							cout << "----------------------------------------------" << endl;
							cout << setw(20) << "First Name" << setw(20) << target_teacher.first_name << endl;
							cout << setw(20) << "Last Name" << setw(20) << target_teacher.last_name << endl;
							cout << setw(20) << "Gender" << setw(20) << target_teacher.gender << endl;
							cout << setw(20) << "Qualification" << setw(20) << target_teacher.qualification << endl;
							cout << setw(20) << "Subject" << setw(20) << target_teacher.subject << endl;
							cout << setw(20) << "Experience" << setw(20) << target_teacher.experience << endl;
							cout << setw(20) << "Salary" << setw(20) << target_teacher.salary << endl;
						}
						else
						{
							cout << "No record found" << endl;
						}
						cout << "Again?" << endl;
						cout << "[0] No" << endl;
						cout << "[1] Yes" << endl;
						cout << "> ";
						choice = -1;
						cin >> choice;
						if(choice == 1)
						{
							continue;
						}
						else
						{
							break;
						}
					}
				}
				else if(choice == 3)
				{
					// edit student;
					while(true)
					{
						printHeader();
						cout << "----------------------------------------------" << endl;
						cout << "Find and Display Teacher" << endl;
						cout << "----------------------------------------------" << endl;
						string search_id;
						cout << "\nEnter id to edit\n> ";
						cin >> search_id;
						ifstream fin("teachers.csv");
						ofstream fout;
						fout.open("temp.csv");
						string teacher_record;
						string cin_temp_str;
						bool record_found = false;
						// ...
						while(getline(fin, teacher_record))
						{
							string teacher_id = get_nth_column_from_csv_record(1, teacher_record);
							if(search_id == teacher_record)
							{
								Teacher target_teacher;
								record_found = true;
								printHeader();
								cout << "-----------------------------------------" << endl;
								cout << "Edit details for " << teacher_id << endl;
								cout << "-----------------------------------------" << endl;
								target_teacher.id = teacher_id;
								// edit first_name
								cout << "Enter teacher's first name. [#] to maintain previous data" << endl;
								target_teacher.first_name = get_nth_column_from_csv_record(2, teacher_record);
								cout << "\t Current = " << target_teacher.first_name << endl;
								cout << endl;
								cout << "> ";
								cin >> cin_temp_str;
								if(cin_temp_str != "#")
								{
									target_teacher.first_name = (cin_temp_str);
								}
								cout << endl;
								// edit last name
								cout << "Enter teacher's last name. [#] to maintain previous data" << endl;
								target_teacher.last_name = get_nth_column_from_csv_record(3, teacher_record);
								cout << "\t Current = " << target_teacher.last_name << endl;
								cout << endl;
								cout << "> ";
								cin >> cin_temp_str;
								if(cin_temp_str != "#")
								{
									target_teacher.last_name = cin_temp_str;
								}
								cout << endl;
									// edit gender
								cout << "Enter teacher's gender [M / F]. [#] to maintain previous data" << endl;
								target_teacher.gender = get_nth_column_from_csv_record(4, teacher_record);
								cout << "\t Current = " << target_teacher.gender << endl;
								cout << endl;
								cout << "> ";
								cin >> cin_temp_str;
								if(cin_temp_str != "#")
								{
									target_teacher.gender = cin_temp_str;
								}
								cout << endl;
								// edit level
								cout << "Enter teacher's qualification. [#] to maintain previous data" << endl;
								target_teacher.qualification = get_nth_column_from_csv_record(5, teacher_record);
								cout << "\t Current = " << target_teacher.qualification << endl;
								cout << "Options:" << endl;
								cout << "Bachelor" << endl;
								cout << "Master" << endl;
								cout << "Doctorate" << endl;
								cout << endl;
								cout << "> ";
								cin >> cin_temp_str;
								if(cin_temp_str != "#")
								{
									target_teacher.qualification = (cin_temp_str);
								}
								cout << endl;
								fout << target_teacher.id << "," << target_teacher.first_name << "," << target_teacher.last_name << "," << target_teacher.gender << "," << target_teacher.qualification << endl;
								continue;
							}
							fout << teacher_record << endl;
						}
						fin.close();
						fout.close();
						if(!record_found)
						{
							remove("temp.csv");
						}
						else
						{
							fin.open("temp.csv");
							fout.open("students.csv");
							while(getline(fin, teacher_record))
							{
								fout << teacher_record << endl;
							}
							fin.close();
							fout.close();
							remove("temp.csv");
						}
						cout << "Successfully editted record" << endl;
						cout << "Again?" << endl;
						cout << "[0] No" << endl;
						cout << "[1] Yes" << endl;
						cout << "> ";
						choice = -1;
						cin >> choice;
						if(choice == 1)
						{
							continue;
						}
						else
						{
							break;
						}
					}
				}
				else if(choice == 4)
				{
					// remove student;
					while(true)
					{
						printHeader();
						cout << "----------------------------------------------" << endl;
						cout << "Find and Display Teacher" << endl;
						cout << "----------------------------------------------" << endl;
						string search_id;
						cout << "\nEnter id to edit\n> ";
						cin >> search_id;
						ifstream fin("students.csv");
						ofstream fout;
						fout.open("temp.csv");
						string teacher_record;
						string cin_temp;
						bool record_found = false;
						// ...
						while(getline(fin, teacher_record))
						{
							string teacher_id = get_nth_column_from_csv_record(1, teacher_record);
							if((search_id) == teacher_id)
							{
								record_found = true;
								continue;
							}
							fout << teacher_record << endl;
						}
						fin.close();
						fout.close();
						if(!record_found)
						{
							remove("temp.csv");
						}
						else
						{
							fin.open("temp.csv");
							fout.open("students.csv");
							while(getline(fin, teacher_record))
							{
								fout << teacher_record << endl;
							}
							fin.close();
							fout.close();
							remove("temp.csv");
						}
						cout << "Successfully removed record" << endl;
						cout << "Again?" << endl;
						cout << "[0] No" << endl;
						cout << "[1] Yes" << endl;
						cout << "> ";
						choice = -1;
						cin >> choice;
						if(choice == 1)
						{
							continue;
						}
						else
						{
							break;
						}
					}
				}
				else if(choice == 5)
				{
					// previous menu
					break;
				}
				else if(choice == 6)
				{
					// exit
					exit(0);
				}
				else
				{
					 continue;
				}
			}
		}
		else if(choice == 3)
		{
			// exit
			exit(0);
		}
		else
		{
			continue;
		}
	}
}