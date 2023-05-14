#include "LibraryManagementSystem.h"
#include <iostream>
/*
-polish
*/

//start up function
void LibraryManagementSystem::StartUp()
{

	bool exit = false;
	choice = 0;

	//while false lets the user run through the code how ever many times they would like
	while (!exit) {

		std::cout << "Welcome To the Library\n";

		std::cout << "ViewList(1), Add(2), Delete(3), search(4), Exit(5)\n";

		std::cin >> choice;

		switch (choice) {

			case 1:

				system("cls");

				ViewList();

				break;

			case 2:

				system("cls");

				AddToList();

				break;

			case 3:

				system("cls");

				DeleteFromList();

				break;

			case 4:

				system("cls");

				SearchList();

				break;

			case 5:

				std::cout << "Would you like to go exit false(0) || true(1)\n";

				std::cin >> exit;

				break;

		}

	}

}

//prints out the list of book
void LibraryManagementSystem::ViewList()
{

	//runs throught the vector and displays while giving it a counter 
	if (LibraryFiles.size() != 0) {

		for (int i = 0; i < LibraryFiles.size(); i++) {

			std::cout << LibraryFiles[i] << '\t' << (i + 1) << '\n';

		}

	}
	else {

		//nothing is in vector it will display this message
		std::cout << "Library List is empty\n";

	}

}

//adds book to the end of vector
void LibraryManagementSystem::AddToList()
{

	std::cout << "Enter the name of the book you wish to add\n";

	std::cin >> bookName;

	LibraryFiles.push_back(bookName);

}

//the deleter functions allowing user to delete the last from location and all books from vector
void LibraryManagementSystem::DeleteFromList()
{

	choice = 0;

	//gives the user a few options of deletion
	std::cout << "would you like to delete Last(1), from location(2), clear(3)\n";

	std::cin >> choice;

	switch (choice)
	{
	
		//deletes last element in vector
		case 1:

			ViewList();

			LibraryFiles.pop_back();

			std::cout << "last book as been removed\n";

			ViewList();

			break;

		//deletes user picked location
		case 2:

			ViewList();

			location = 0;

			std::cout << "What book index would you like to delete\n";

			std::cin >> location;

			LibraryFiles.erase(LibraryFiles.begin() + (location - 1));

			std::cout << "Book has been deleted\n";

			ViewList();

			break;

		//clears whole vector list
		case 3:

			ViewList();

			choice = 0;

			std::cout << "you sure Y(1)/N(2)\n";

			std::cin >> choice;

			if (choice == 1) {

				LibraryFiles.clear();

				ViewList();

			}
			else {

				std::cout << "Clear command cancelled\n";

			}

			break;

	}

}

//user types in name and then a for loop run through and finds all equal names so sadly no help if you dont spell it correctly
void LibraryManagementSystem::SearchList()
{

	bool found = false;

	bookName = "";

	std::cout << "Enter Book name to search\n";

	std::cin >> bookName;

	while (!found) {

		//get the size of the vector and then runs through it
		for (int i = 0; i < LibraryFiles.size(); i++) {

			//if any vector matches the name it will display the name and location CNTR
			if (bookName.compare(LibraryFiles[i]) == 0) {

				std::cout << "Found: " << LibraryFiles[i] << "\t" << i + 1 << '\n';

				found = true;

			}

		}

		std::cout << "Search Completed\n";

	}

}
