#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include<cmath>
#include <ctime>
#include <limits>
/*NOTE(PLEASE READ IF YOU ARE USING THIS SYSTEM FOR THE FIRST TIME) :
	you must create a user by using using the admin_create_user()
	function to create an admin type account in order to use the system probably
	with out any problems.* /
/*This a ctime vs warning disable for running the system without problems.*/

#pragma warning(disable : 4996)
using namespace std;

/*This structure used to store the date data and used within the user structure at line [21].*/

struct date
{
	int day;
	int month;
	int year;
};

/*This is the user structure used to hold the data of the users and contains functions used in the main functions of the system.*/

struct user
{
	int id;
	char name[30];
	char email[50];
	char password[12];
	char acc_type[8];
	date creation_date;
	int contact_no;
	void create_user();
	void show_user();
	string return_acc_type();
	string return_username();
    string return_password();
	int return_creation_day();
	void number_validation(int number);
};

/*This a user structure function used to check if certain data of integer type are acutally numbers.*/

void user :: number_validation(int number)
{
	if (cin.fail())
	{
		cout << "Please, Enter Numbers Only." << endl;
	}
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cin >> number;
	}
}


/*This is a user structure function used to create a new user.*/

void user :: create_user()
{
	cout << "Enter the user's ID:" << endl;
	cin >> id;
	number_validation(id);
	cout << "Enter the user's Name:" << endl;
	cin.ignore();
	cin.get(name, 30);
	cout << "Enter the user's Email:" << endl;
	cin.ignore();
	cin.get(email, 50);
	cout << "Enter the user's Password:" << endl;
	cin.ignore();
	cin.get(password, 12);
	cout << "Enter the user's Account Type [student, guest, admin, staff]:" << endl;
	cin.ignore();
	cin.get(acc_type, 8);
	cout << "Enter the user's Creation Date:" << endl;
	cout << "Enter the day:" << endl;
	cin >> creation_date.day;
	number_validation(creation_date.day);
	cout << "Enter the month:" << endl;
	cin >> creation_date.month;
	number_validation(creation_date.month);
	cout << "Enter the year:" << endl;
	cin >> creation_date.year;
	number_validation(creation_date.year);
	cout << "Enter the user's Contact number (Max. Char. 3):" << endl;
	cin >> contact_no;
	number_validation(contact_no);
}

/*This a user structure function used to display a user(s) data.*/

void user :: show_user()
{
	cout << "The user's ID:" << endl;
	cout << id << endl;
	cout << "the user's Name:" << endl;
	cout << name<<endl;
	cout << "the user's Email:" << endl;
	cout << email<<endl;
	cout << "the user's Password:" << endl;
	cout << password<<endl;
	cout << "the user's Account Type:" << endl;
	cout << acc_type<<endl;
	cout << "the user's Creation Date:" << endl;
	cout << creation_date.day << " / " << creation_date.month << " / " << creation_date.year << endl;
	cout << "The user's Contact number:" << endl;
	cout << contact_no << endl;
}

/*This a user structure function used to return the user's account type.*/

string user :: return_acc_type()
{
	return string(acc_type);
}

/*This a user structure function used to return the user's username.*/

string user :: return_username()
{
	return string(name);
}

/*This a user structure function used to return the user's password.*/

string user :: return_password()
{
	return string(password);
}

/*This a user structure function used to return the user's creation date's day.*/

int user :: return_creation_day()
{
	return creation_date.day;
}


/*This is structure used to hold the data of books stored in the system by the admins.*/

struct book
{
	char title[30];
	date production_date;
	int number_of_copies;
	char cat[10];
	char edition[10];
	void add_book();
	void show_books();
	string return_title();
	int return_prod_year();
	int return_copies_no();
	void number_validation(int number);

};

/*This a book structure function used to check if certain data of integer type are acutally numbers.*/

void book :: number_validation(int number)
{
	if (cin.fail())
	{
		cout << "Please, Enter Numbers Only." << endl;
	}
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cin >> number;
	}
}

/*This is a book structure function used for creating a new book.*/

void book :: add_book()
{
	cout << "Enter the Book's Title:" << endl;
	cin.ignore();
	cin.get(title, 30);
	cout << "Enter the Production_date:" << endl;
	cout << "Enter the Day:" << endl;
	cin >> production_date.day;
	number_validation(production_date.day);
	cout << "Enter the Month:" << endl;
	cin >> production_date.month;
	number_validation(production_date.month);
	cout << "Enter the Year:" << endl;
	cin >> production_date.year;
	number_validation(production_date.year);
	cout << "Enter the Book's Category:" << endl;
	cin.ignore();
	cin.get(cat, 10);
	cout << "Enter the Book's Edition:" << endl;
	cin.ignore();
	cin.get(edition, 10);
	cout << "Enter the Number of Copies Available:" << endl;
	cin >> number_of_copies;
	number_validation(number_of_copies);
}

/*This is a book structure function used for displaying book.*/

void book :: show_books()
{
	cout << "The Book's Title:" << endl;
	cout << title << endl;
	cout << "The Production_date:" << endl;
	cout << production_date.day << " / " << production_date.month << " / " << production_date.year << endl;
	cout << "The Book's Category:" << endl;
	cout << cat << endl;
	cout << "The Book's Edition:" << endl;
	cout << edition << endl;
	cout <<"Number Of Available Copies For Purchase:" << endl;
	cout << number_of_copies << endl;
		
	
}

/*This is a book structure function used for returning the title of a certain book.*/

string book :: return_title()
{
	return string(title);
}

/*This is a book structure function used for returning the production year of a certain book.*/

int book :: return_prod_year()
{
	return production_date.year;
}

/*This is a book structure function used for returning the number of copies available of a certain book.*/

int book :: return_copies_no()
{
	return number_of_copies;
}

/*Main Functions Declaration */
void admin_create_user();
void admin_show_all_users(int option);
void admin_add_book();
void show_books();
int user_login(string username,string password, int option);
void title_book_search(string book_name);
void year_book_search(int year);
void buy_book(string book_name);

/*Main function contains the mechanism of the system
NOTE(PLEASE READ IF YOU ARE USING THIS SYSTEM FOR THE FIRST TIME):
you must create a user by using using the admin_create_user() 
function to create an admin type account in order to use the system probably
with out any problems.*/

int main() 
{
	
	
	cout << "*******************************************************" << endl;
	cout <<	"*                                                     *" << endl;
	cout <<	"*      Welcome To The Electronic Library System       *" << endl;
	cout <<	"*                                                     *" << endl;
	cout <<	"*******************************************************" << endl;
	cout << "*                                                     *" << endl;
	cout << "*                                                     *" << endl;
	cout << "*        Press [0] To Start the System.               *" << endl;
	cout << "*        Press [1] To Quit.                           *" << endl;
	cout << "*                                                     *" << endl;
	cout << "*******************************************************" << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "Enter Your Choice:" << endl;
	cout << "-------------------------------------------------" << endl;
	int choice = 0;
	cin >> choice;
	if (choice == 1)
	{
		cout << "Thanks For Using" << endl;
	}
	else if (choice == 0)
	{
		int counter = 1;
		string usr, pwd;
		bool quit = false;

		cout << "-------------------------------------------------" << endl;
		cout << "\t\tLOGIN\t\t(Max Attempts 3):" << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "Please, Enter your username:" << endl;
		cin.ignore();
		getline(cin, usr);
		cout << "Please, Enter your password:" << endl;
		getline(cin, pwd);
		user_login(usr, pwd, 1);
		cout << "-------------------------------------------------" << endl;

		while (user_login(usr,pwd,1) == -1)
		{
			cout << "-------------------------------------------------" << endl;
			cout << "Wrong Username Or Password, Try Again." << endl;
			cout << "Please, Enter your username:" << endl;
			cin.sync(); 
			getline(cin, usr);
			cout << "Please, Enter your password:" << endl;
			cin.sync();
			getline(cin, pwd);
			user_login(usr, pwd, 1);
			cout << "-------------------------------------------------" << endl;
			if (user_login(usr,pwd,2) == 0 || user_login(usr, pwd, 2) == 1 || user_login(usr, pwd, 2) == 2 || user_login(usr, pwd, 2) == 3)
			{
				cout << "Access Granted, Welcome, " + usr + "."<< endl;
				cout << "-------------------------------------------------" << endl;
				break;
			}
		}
		cout << "Access Granted, Welcome, " + usr + "."<< endl;
		
		while (quit == false)
		{
			if (user_login(usr, pwd, 2) == 0)
			{
				int std_choice = 0;
				cout << "You Have Student Privileges." << endl;
				cout << "Choose Your Action:" << endl;
				cout << "-------------------------------------------------" << endl;
				cout << "1. View All Books." << endl;
				cout << "2. Search For A Certain Book." << endl;
				cout << "3. Quit." << endl;
				cout << "-------------------------------------------------" << endl;
				cout << "Enter Your Choice:" << endl;
				cout << "-------------------------------------------------" << endl;
				cin >> std_choice;
				if (std_choice == 1)
				{
					show_books();
				}
				else if (std_choice == 2)
				{
					int search_choice = 0;
					cout << "Choose Your Action:" << endl;
					cout << "-------------------------------------------------" << endl;
					cout << "1. Search by Title." << endl;
					cout << "2. Search By Production Year." << endl;
					cout << "-------------------------------------------------" << endl;
					cout << "Enter Your Choice:" << endl;
					cout << "-------------------------------------------------" << endl;
					cin >> search_choice;
					if (search_choice == 1)
					{
						string title;
						cout << "Please Enter the Title of The Book You would Like to Search For:" << endl;
						cout << "-------------------------------------------------" << endl;
						cin.ignore();
						getline(cin, title);
						title_book_search(title);
					}
					else if (search_choice == 2)
					{
						int prod_year = 0;
						cout << "Please Enter the Production Year of The Book You would Like to Search For:" << endl;
						cout << "-------------------------------------------------" << endl;
						cin >> prod_year;
						year_book_search(prod_year);
					}
				}
				else if (std_choice == 3)
				{
					cout << "-------------------------------------------------" << endl;
					quit = true;
					break;
				}
			}

			else if (user_login(usr, pwd, 2) == 1)
			{
				int stf_choice = 0;
				cout << "You Have Staff Privileges." << endl;
				cout << "-------------------------------------------------" << endl;
				cout << "Choose Your Action:" << endl;
				cout << "-------------------------------------------------" << endl;
				cout << "1. View All Books." << endl;
				cout << "2. Buy a Book." << endl;
				cout << "3. Quit" << endl;
				cout << "-------------------------------------------------" << endl;
				cout << "Enter Your Choice:" << endl;
				cout << "-------------------------------------------------" << endl;
				cin >> stf_choice;
				if (stf_choice == 1)
				{
					show_books();
				}
				else if (stf_choice == 2)
				{
					string title;
					cout << "Enter The Name of The Book You Want Buy:" << endl;
					cout << "-------------------------------------------------" << endl;
					cin.ignore();
					getline(cin, title);
					buy_book(title);

				}
				else if (stf_choice == 3)
				{
					cout << "-------------------------------------------------" << endl;
					quit = true;
					break;
				}
			}
			else if (user_login(usr, pwd, 2) == 2)
			{
				int gst_choice = 0;
				cout << "You Have Guest Privileges." << endl;
				cout << "-------------------------------------------------" << endl;
				cout << "Choose Your Action:" << endl;
				cout << "-------------------------------------------------" << endl;
				cout << "1. View All Books." << endl;
				cout << "2. Quit." << endl;
				cout << "-------------------------------------------------" << endl;
				cout << "Enter Your Choice:" << endl;
				cout << "-------------------------------------------------" << endl;
				cin >> gst_choice;
				if (gst_choice == 1)
				{
					show_books();
				}
				else if (gst_choice ==2)
				{
					cout << "-------------------------------------------------" << endl;
					quit = true;
					break;
				}
			}
			else if (user_login(usr, pwd, 2) == 3) 
			{

				int admin_choice = 0;
				cout << "You Have Admin Privileges." << endl;
				cout << "Choose your Action:" << endl;
				cout << "-------------------------------------------------" << endl;
				cout << "1. Add a New User." << endl;
				cout << "2. Show Report of Accounts recently Created." << endl;
				cout << "3. Add a New Book to The System." << endl;
				cout << "4. Show All Books in The System." << endl;
				cout << "5. Show All Users Created." << endl;
				cout << "6. Quit." << endl;
				cout << "-------------------------------------------------" << endl;
				cout << "Enter Your Choice:" << endl;
				cout << "-------------------------------------------------" << endl;
				cin >> admin_choice;
				if (admin_choice == 1)
				{
					admin_create_user();
				}
				else if (admin_choice == 2)
				{
					cout << "Note:\nThis report is Genrated For The Accounts Created Within Seven Day Span." << endl;
					admin_show_all_users(1);
				}
				else if (admin_choice == 3)
				{
					admin_add_book();
				}
				else if (admin_choice == 4)
				{
					show_books();
				}
				else if (admin_choice == 5)
				{
					admin_show_all_users(2);
				}
				else if (admin_choice == 6)
				{
					cout << "-------------------------------------------------" << endl;
					quit = true;
					break;
				}
			}
		}
	}
	else
	{
		cout << "Invalid Option !" << endl;
		cout << "Quitting ................." << endl;
		cout << "System Has Been Terminated " << endl;
		cout << "-------------------------------------------------" << endl;
	}
	system("pause");

}

/*A main function used by admins to create a new accounts.*/

void admin_create_user()
{
	user US;
	ofstream out_file;
	out_file.open("users.txt", ios::binary | ios::app | ios::out);
	if (out_file.fail())
	{
		cout << "Error :-\n Can not access database ." << endl;
	}
	US.create_user();
	out_file.write(reinterpret_cast<char*>(&US), sizeof(user));
	out_file.close();

}

/*A main function used by admins to display all accounts.
contains two options:
option 1: show all users with 7 day span.
option 2: show all users created since the system was created.*/

void admin_show_all_users(int option)
{
	user US;
	ifstream in_file;
	time_t t = time(NULL);
	tm* tPtr = localtime(&t);
	in_file.open("users.txt", ios::binary | ios::in);
	if (!in_file)
	{
		cout << "Error :-\n Can not access database." << endl;
	}
	while (in_file.read(reinterpret_cast<char*>(&US), sizeof(user)))
	{
		if (option == 1) 
		{
			if (US.return_creation_day() >= ((tPtr->tm_mday) - 7) && US.return_creation_day() <= (tPtr->tm_mday)) {
				cout << "-----------------------------------------------" << endl;
				US.show_user();
				cout << "-----------------------------------------------" << endl;
			}
		}
		else if (option == 2)
		{
			cout << "-----------------------------------------------" << endl;
			US.show_user();
			cout << "-----------------------------------------------" << endl;
		}
	}
	in_file.close();

}

/*A main function used by admins add a new book to the system.*/

void admin_add_book()
{
	book BK;
	ofstream out_file;
	out_file.open("books.txt", ios::binary | ios::app | ios::out);
	if (out_file.fail())
	{
		cout << "Error :-\n Can not access database ." << endl;
	}
	BK.add_book();
	out_file.write(reinterpret_cast<char*>(&BK), sizeof(book));
	out_file.close();
}

/*A main function used by admins/students/guest/staff to show all the books stored within the system*/

void show_books()
{
	book BK;
	ifstream in_file;
	in_file.open("books.txt", ios::binary | ios::in);
	if (!in_file)
	{
		cout << "Error :-\n Can not access database." << endl;
	}
	while (in_file.read(reinterpret_cast<char*>(&BK), sizeof(book)))
	{
		cout << "-----------------------------------------------" << endl;
		BK.show_books();
		cout << "-----------------------------------------------" << endl;

	}
	in_file.close();
}

/*A main function used for logining in and determine the privileges according to the type of the account.*/

int user_login(string username, string password, int option)
{

	user US;
	ifstream in_file;
	in_file.open("users.txt", ios::binary | ios::in);
	bool flag = false;
	int type_flag = 0;
	if (!in_file)
	{
		cout << "Error :-\n Can not access database." << endl;
	}
	while (in_file.read(reinterpret_cast<char*>(&US), sizeof(user)))
	{
		if (username == US.return_username() && password == US.return_password() && flag == false)
		{
			flag = true;
			if (US.return_acc_type() == "Student" || US.return_acc_type() == "student")
			{
				type_flag = 1;
			}
			else if (US.return_acc_type() == "Staff" || US.return_acc_type() == "staff")
			{
				type_flag = 2;
			}
			else if (US.return_acc_type() == "Guest" || US.return_acc_type() == "guest")
			{
				type_flag = 3;
			}
			else if (US.return_acc_type() == "admin" || US.return_acc_type() == "Admin")
			{
				type_flag = 4;
			}
			break;
		}
		else
		{
			flag = false;

		}

	}
	in_file.close();
	if (option == 1) 
	{
		if (flag == true)
		{
			return -2;
		}
		if (flag == false)
		{
			return -1;
			cout << "Access Denied, Please try again later" << endl;
		}
	}
	else if (option == 2) 
	{
		if (type_flag == 1)
		{
			return 0;
		}
		else if (type_flag == 2)
		{
			return 1;
		}
		else if (type_flag == 3)
		{
			return 2;
		}
		else if (type_flag == 4)
		{
			return 3;
		}
	}
}

/*A main function used by student to search for a certain book by knowing it's title.*/

void title_book_search(string book_name)
{
	book BK;
	ifstream in_file;
	in_file.open("books.txt", ios::binary | ios::in);
	bool flag = false;
	if (!in_file)
	{
		cout << "Error :-\n Can not access database ." << endl;
	}
	while (in_file.read(reinterpret_cast<char*>(&BK), sizeof(book)))
	{
	
		string file_book = BK.return_title();
		file_book.erase(remove_if(file_book.begin(), file_book.end(), isspace));
		book_name.erase(remove_if(book_name.begin(), book_name.end(), isspace));
		if (book_name == file_book)
		{
			flag = true;
			
			break;
		}
		
	}
	in_file.close();
	if (flag == true)
	{
		cout << "Matching has Been Found!" << endl;
		cout << "Search Results:" << endl;
		cout << "-----------------------------------------------" << endl;
		BK.show_books();
	}
	else if (flag == false)
	{
		cout << "Book Is Not Found." << endl;
	}
}

/*A main function used by student to search for a certain book by knowing it's production year.*/

void year_book_search(int year)
{
	book BK;
	ifstream in_file;
	in_file.open("books.txt", ios::binary | ios::in);
	bool flag = false;
	if (!in_file)
	{
		cout << "Error :-\n Can not access database ." << endl;
	}
	while (in_file.read(reinterpret_cast<char*>(&BK), sizeof(book)))
	{

		
		if (year == BK.return_prod_year())
		{
			cout << "Matching(s) has Been Found!" << endl;
			cout << "Search Results:" << endl;
			cout << "-----------------------------------------------" << endl;
			BK.show_books();
			flag = true;
			
		}

	}
	in_file.close();
	
	if (flag == false)
	{
		cout << "Book Is Not Found." << endl;
	}
}

/*A main function used by staff to buy a certain book.*/

void buy_book(string book_name)
{
	book BK;
	fstream file;
	bool found = false;
	file.open("books.txt", ios::binary | ios::in | ios::out);
	if (!file)
	{
		cout << "Error :-\n Can not access database." << endl;
	}
	while (!file.eof() && found == false)
	{
		file.read((char*)(&BK), sizeof(book));
		string file_book = BK.return_title();
		file_book.erase(remove_if(file_book.begin(), file_book.end(), isspace));
		book_name.erase(remove_if(book_name.begin(), book_name.end(), isspace));
		if (book_name == file_book)
		{
			if (BK.number_of_copies == 0)
			{
				cout << "All Copies Have Been Sold Out !" << endl;
				break;
			}
			int no = 0;
			BK.show_books();
			cout << "How Much Copies Do You Want To Buy ?" << endl;
			cin >> no;
			BK.number_of_copies = BK.number_of_copies - no;
			cout << "Purchase Has Been Successful." << endl;
			int pos = (-1) * static_cast<int>(sizeof(book));
			file.seekp(pos, ios::cur);
			file.write((char*)(&BK), sizeof(book));
			found = true;
		}
	}
	file.close();
	if (found == false)
	{
		cout << "Book Not Found !!" << endl;
	}
}


