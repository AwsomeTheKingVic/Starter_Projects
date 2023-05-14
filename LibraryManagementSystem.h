#pragma once
#include <vector>
#include <string>

class LibraryManagementSystem
{

	//values
	std::vector<std::string> LibraryFiles;
	std::string bookName = "";
	int choice = 0, location = 0;

public:

	//fucntion
	void StartUp();
	void ViewList();
	void AddToList();
	void DeleteFromList();
	void SearchList();

};

