/*Digital Application Development
Created by: Ajil Seby Jomy
Student Number: B830603
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <iomanip>     
using namespace std;

struct user //User structure (temporary database)
{
	string username, password; // Use array to store the different records
};

struct user e; //Actual values in database to be inserted
char username, password;

int main()
{
	char choice;
	void Add();
	void View();
	void Delete();
	void Exit();

	char* yusername; //dynamically allocating an array for username
	char *ypassword; //dynamically allocating an array for password
	int u_characters; //hold number of characters for username
	int p_characters; //hold number of characters for password
	int length; //assure requested length and pass length are the same

Create_login:
	system("cls");
	cout << "\n\n\t============================================ CREATE USERNAME ==============================================";
	cout << "\n\n\tPlease enter how many charcaters your username will be."; // Create username
	cout << "\n\tYour username must be at least 3 characters long.\n\t";
	cin >> u_characters;

	//Error handling
	while (cin.fail() || u_characters < 3)
	{
		cout << "\tUsername must be atleast be 3 characters.\n\t";
		cin.clear(); // Clears input
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Clears buffer
		cin >> u_characters;
	}
	yusername = new char[u_characters + 1]; // every cstring must end with a '\0' else -> crash

	cout << "\tPlease enter the username you will use to login:\n\t";
	cin >> yusername;
	//convert pointer/array length to interger
	length = strlen(yusername);
	//check pointer/array length against user requested pointer/array size
	//to ensure consistent data
	while (length != u_characters)
	{
		cout << "\tUsername length does not match character length. Please start again.\n\t";
		system("pause");
		goto Create_login;
	}
	cout << "\tThankyou for making a username. Now you will be directed to make a password.\n\t";
	system("pause");
Create_password:
	system("cls");
	cout << "\n\n\t============================================ CREATE PASSWORD ==============================================";
	cout << "\n\n\tPlease enter how many charcaters your password will be."; // Create password
	cout << "\n\tYour password must be at least 3 characters long.\n\t";
	cin >> p_characters;

	//Error handling
	while (cin.fail() || p_characters < 3)
	{
		cout << "\tPassword must be atleast be 3 characters.\n\t";
		cin.clear(); // Clears input
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Clears buffer
		cin >> p_characters;
	}
	ypassword = new char[p_characters + 1]; // every cstring must end with a '\0' else -> crash

	cout << "\tPlease enter the password you will use to login:\n\t";
	cin >> ypassword;
	//convert pointer/array length to interger
	length = strlen(ypassword);
	//check pointer/array length against user requested pointer/array size
	//to ensure consistent data
	while (length != p_characters)
	{
		cout << "\tPassword length does not match character length. Please start again.\n\t";
		system("pause");
		goto Create_password;
	}
	cout << "\tThankyou for creating an account. Please login now.\n\t";
	system("pause");

Login:
	system("cls");
	cout << "\n\n\t============================================  LOGIN SCREEN ==============================================";
	cout << "\n\n\tPlease enter username:\n\t";
	cin >> e.username;
	if (e.username == yusername)
	{
		cout << "\tPlease enter password:\n\t";
		cin >> e.password;
		if (e.password == ypassword) // nested if function using structure 
		{
			goto Main;
		}
		else
		{
			cout << "\tYou have entered the wrong password. Please try again.\n\t";
			system("pause");
			goto Login;
		}
	}
	else
	{
		cout << "\tYou have entered the wrong username. Please try again.\n\t";
		system("pause");
		goto Login;
	}

Main: // Defining subheadings
	  // Title page Coding
	cin.clear(); // Clears input
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Clears buffer
	system("CLS");
	cout << "\n\n\t=================================== AJIL'S STUDENT DATABASE MANAGEMENT ===================================";
	cout << "\n\n";
	cout << "\t\t1. Add records";
	cout << "\t\t\t2. View records";
	cout << "\t\t\t3. Delete records\n";
	cout << "\t\t4. Exit program";
	cout << "\n\n";
	cout << "\tSelect your choice: ";
	choice = getchar();
	cin.clear(); // Clears input
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Clears buffer


	while ((choice < '1' || choice > '4'))//Error handling
	{
		cout << "\nYou must enter a value between 1 - 4.\n";
		cout << "Your selection is: ";
		cin >> choice;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	system("CLS");

	// Sends you to the correct case
	switch (choice)
	{
		//Add Records
	case '1':
		Add();
		goto Main;
		break;
		//View Records
	case '2':
		View();
		goto Main;
		break;

		//Delete Records 
	case '3':
		Delete();
		goto Main;
		break;

		//Exit Records
	case '4':
		Exit();
		break;
	}

}
void Add()
{
	char type;
	string category;
	string title;
	string creator;
	int page;

	system("CLS");
	cout << "\n\n\tPlease pick which of the following record you would like to add\n";
	cout << "\tor select return to title page:\n\n";
	cout << "\t1. Book";
	cout << "\t\t\t2. Journal";
	cout << "\t\t\t3. CD\n";
	cout << "\t4. File";
	cout << "\t\t\t5. Return to title page";
	cout << "\n\n";
	cout << "\tSelect your choice: ";
	type = getchar();
	cin.clear(); // Clears input
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Clears buffer

	while ((type < '1' || type > '5')) //Error handling
	{
		cout << "\n\tYou must enter a value between 1 - 6.\n";
		cout << "\tYour selection is: ";
		type = getchar();
		cin.clear(); // Clears input
	};

	switch (type)
	{
	case '1': // Book
	{
		category = ("Book");
		cout << "\n\tEnter the title of the book:";
		cin >> title;
		cout << "\n\tEnter the author of the book:";
		cin >> creator;
		cout << "\n\tEnter the relevant page numbers:";
		cin >> page;
		string page2 = to_string(page);
		ofstream Bibliography("Bibliography.txt", ios::out | ios::app);
		Bibliography << category << " " << title << " " << creator << " " << page2 << "\n";
		cout << "\n\tThank you for adding a book.\n\n";
		system("pause");
	}break;

	case '2': // Journal
	{
		category = ("Journal");
		cout << "\n\tEnter the title of the journal:";
		cin >> title;
		cout << "\n\tEnter the author of the journal:";
		cin >> creator;
		cout << "\n\tEnter the relevant page numbers:";
		cin >> page;
		string page2 = to_string(page);
		ofstream Bibliography("Bibliography.txt", ios::out | ios::app);
		Bibliography << category << " " << title << " " << creator << " " << page2 << "\n";
		cout << "\n\tThank you for adding a journal.\n\n";
		system("pause");
	}break;

	case '3': // CD
	{
		category = ("CD");
		cout << "\n\tEnter the title of the CD:";
		cin >> title;
		cout << "\n\tEnter the artist who created the CD:";
		cin >> creator;
		cout << "\n\tEnter the relevant track numbers:";
		cin >> page;
		string page2 = to_string(page);
		ofstream Bibliography("Bibliography.txt", ios::out | ios::app);
		Bibliography << category << " " << title << " " << creator << " " << page2 << "\n";
		cout << "\n\tThank you for adding a CD.\n\n";
		system("pause");
	}break;

	case '4': // File
	{
		category = ("File");
		cout << "\n\tEnter the title of the file:";
		cin >> title;
		cout << "\n\tEnter the maker of the file:";
		cin >> creator;
		cout << "\n\tEnter the relevant file number:";
		cin >> page;
		string page2 = to_string(page);
		ofstream Bibliography("Bibliography.txt", ios::out | ios::app);
		Bibliography << category << " " << title << " " << creator << " " << page2 << "\n";
		cout << "\n\tThank you for adding a file.\n\n";
		system("pause");
	}break;

	case '5': // Return to main page 
	{
		return;

	}
	}

}

void View()
{
	string category;
	string title;
	string creator;
	int page;

	cout << "\n\n\t======================================== RECORDS IN DATABASE ========================================";
	cout << "\n\n";
	cout << "\tType:" << setw(20) << " Title:" << setw(20) << "Creator:" << setw(20) << "Page/Track:";
	ifstream Bibliography("Bibliography.txt", ios::in);
	while (Bibliography >> category >> title >> creator >> page)// While database has records
	{
		cout << "\n";
		cout << "\t" << category << setw(20) << title << setw(20) << creator << setw(20) << page;// Displays the records in file
	}
	cout << "\n\n\t";

	ifstream::pos_type filesize(const char* Bibliography); // Use of pointer to find file
	ifstream Bibliography_size("Bibliography.txt", std::ifstream::ate | std::ifstream::binary); // Finds the size of database
	cout << "The size of the bibliographic database is " << Bibliography_size.tellg() << " bytes.\n\t";
	system("pause");
}

void Delete()
{
	string title, creator, ttitle;
	string category;
	int del = 0;
	string page2;

	ifstream Bibliography("Bibliography.txt", ios::out);
	ofstream Temp("Temp.txt", ios::out); // Temp file for input of every student except the one user wants to delete

	cout << "\n\n\t================================= DATABASE RECOD DELETION ==========================================";
	cout << "\n\n\tEnter name of the record you want to erase from database ";
	cout << "\n\tPlease note that if multipile records have the same name they will all be deleted from the database.\n\t";
	cin >> ttitle;

	while (Bibliography >> category >> title >> creator >> page2)
	{
		if (ttitle != title) { // Records with ifferent names are put into the Temp file
			Temp << category << " " << title << " " << creator << " " << page2 << "\n";
		}
		if (ttitle == title) { // if correct name is entered, del=1 for message being shown later
			del = 1;
		}
	}
	Bibliography.close();
	Temp.close();
	remove("Bibliography.txt");
	rename("Temp.txt", "Bibliography.txt");

	if (del == 0) { // del=0 when initialised so records have not been deleted 
		cout << "There is no record with name you entered.Please view records and try again." << endl;
		system("pause");
	}

	else { // del!=0 so record has been deleted
		cout << "The record has been deleted." << endl;
		system("pause");
	}

}

void Exit()
{
	cout << "\n\n\t=============================== THANKYOU FOR USING AJIL'S STUDENT DATABASE ===============================";
	cout << "\n\n\t";
	system("pause");
	exit(0);

}