//Nicholas Ang
//CS457
//Project Assignment 1

//Libraries
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sys/stat.h>
#include <unistd.h>
#include <limits>
using namespace std;

//Function Declarations
void parseFile(ifstream &file);
string stringUpper(string s);
void createDb(string s, string initS);
void dropDb(string s, string initS);
void useDb(string s, string initS);
void createTb(string s, string initS);
void dropTb(string s, string initS);
void alterTb(string s, string initS);
void selectFrom(string s, string initS);
void parseCommand(string s, string initS);

//Global Variables
bool usingDB = 0;
string currentDB = "";

//Main function
int main(int argc, char* argv[])
{
	//Uppercase string
	string s;
	//Initial string
	string initS;
	//file command use
	if(argc == 1)
	{
		cout << "Interactive Mode" << endl;
		//Interactive mode - type commands one by one.
		do
		{
			getline(cin,s);
			initS = s;
			s = stringUpper(s);
			parseCommand(s, initS);
		}
		while(s != ".EXIT");
	}
	//If there is a file in the command line, read and parse file for commands
	else if(argc == 2)
	{
		ifstream file;
		file.open(argv[1]);
		if(file.is_open())
		{
			parseFile(file);
		}
		else
		{
			cout << "File not found..."  << endl;
		}
		cout << "All done." << endl;
		file.close();
	}

	return 0;
}

//parseFile - using a file for commands
void parseFile(ifstream &file)
{
	string s,initS;
	//Parse every line in the file until it finds .EXIT or file ends
	while(!file.eof() && s != ".EXIT")
	{
		int start = 0;
		getline(file,s, '\n');
		initS = s.substr(0, s.length() - 1);
		s = stringUpper(initS);
		parseCommand(s,initS);
	}
}

//stringUpper - Convert every character in a string to uppercase
string stringUpper(string s)
{
	for(int i = 0; i < s.length(); i++)
	{
		s[i] = toupper(s[i]);
	}
	return s;
}

//createDb - Create a folder as a database with parsed database name
void createDb(string s, string initS)
{
	string dbName;
	dbName = initS.substr(16, initS.length() - 17);
	const char *c = dbName.c_str();
	//If there is no database with the given name, create a database
	if(mkdir(c,0777) != -1)
	{
		cout << "Database " << dbName << " created" << endl;
	}
	//Otherwise it exists already
	else
	{
		cout << "!Failed to create database " << dbName << " because it already exists." << endl;
	}
}

//dropDb - Delete a database folder with given parsed name
void dropDb(string s, string initS)
{
	string dbName;
	string removeEntireDirectory("rm -rf ");
	string r;
	dbName = initS.substr(14, initS.length() - 15);
	r = removeEntireDirectory.append(dbName);
	const char *c = dbName.c_str();
	const char *c2 = r.c_str();
	//Delete database with given name if there is a database with that name
	//Deletes folder with any files inside
	if(chdir(c) != -1)
	{
		chdir("..");
		system(c2);
		cout << "Database " << dbName << " deleted" << endl;
	}
	//Otherwise database is not deleted
	else
	{
		cout << "!Failed to delete database " << dbName << " because it does not exist." << endl;
	}
}

//useDb - Access the database folder specified in the command
void useDb(string s, string initS)
{
	string prevFolder = "..";
	string dbName;
	dbName = initS.substr(4, initS.length() - 5);
	const char *c = dbName.c_str();
	//If database is not in use, swapping from current folder to database folder
	if(usingDB == 0)
	{
		//If valid and folder exists, cd into folder and usingDB is set to 1
		if(chdir(c) != -1)
		{
			cout << "Using database " << dbName << endl;
			usingDB = 1;
			currentDB = dbName;
		}
		//Otherwise database does not exist or is invalid
		else
		{
			cout << "!Failed to use database " << dbName << " because it does not exist." << endl;
		}
	}
	//If using a database, swapping from one database file to a different database folder
	//If new database folder is invalid, go back to original folder that holds all the databases
	else if(usingDB == 1 && currentDB != dbName)
	{
		//Go back to previous folder
		const char *c2 = prevFolder.c_str();
		chdir(c2);
		//CD to new database folder, set usingDB to 1
		if(chdir(c) != -1)
		{
			cout << "Using database " << dbName << endl;
			usingDB = 1;
			currentDB = dbName;
		}
		//If database folder is invalid, output that it does not exist and set usingDB to 0 to indicate database is not in use
		else
		{
			cout << "!Failed to use database " << dbName << " because it does not exist." << endl;
			usingDB = 0;
		}
	}
	//If using database and the dbname in the command is same as the currently used database
	else if(usingDB == 1 && currentDB == dbName)
	{
		//Output that the user is using the same database
		cout << "Currently using database " << currentDB << endl;
	}
}

//createTb - If using a database, create a table file in current database file with given parameters
void createTb(string s, string initS)
{
	string fileName;
	string attributes;
	
	//If given parameters, take filename from substr before parameters
	//take attributes after filename
	if(initS.find("(") != -1)
	{
	fileName = initS.substr(13, initS.find("(") - 14);
	attributes = initS.substr(initS.find("(") + 1, initS.find(";") - 2 - initS.find("("));
	}
	//Filename from substr from after "CREATE TABLE" to end
	//No attributes if no parameters ()
	else
	{
	fileName = initS.substr(13, initS.length() - 14);
	attributes = "";
	}
	
	ifstream checkFile;
	checkFile.open(fileName);
	//Check if file exists by checking if it can open the file in read mode
	if(checkFile)
	{
		cout << "!Failed to create table " << fileName << " because it already exists." << endl;
		checkFile.close();
	}
	//If it does not exist, create file with given attributes
	else
	{
		int attrConversion = 0;
		checkFile.close();
		//Open file in write mode
		ofstream file(fileName);
		//Convert attributes from string by replacing commas and add to file
		while((attrConversion = attributes.find(",", attrConversion)) != -1)
		{
			attributes.replace(attrConversion, 1, "\n");
			attrConversion += 3;
		}
		//Output attributes into file
		file << attributes;
		cout << "Table " << fileName << " created" << endl;
		file.close();
	}
}

//dropTb - Delete table in a database
void dropTb(string s, string initS)
{
	string fileName;
	fileName = initS.substr(11, initS.length() - 12);
	ifstream checkFile;
	//check if file exists
	checkFile.open(fileName);
	if(checkFile)
	{
		//close file before deleting it
		checkFile.close();
		if(remove(fileName.c_str()) == 0)
		{
			cout << "Table " << fileName << " deleted" << endl;
		}
		//If it could not remove file or is invalid, output file does not exist
		else
		{
			cout << "!Failed to delete table " << fileName << " because it does not exist." << endl;
		}
	}
	//If file does not exist, cannot delete
	else
	{
		cout << "!Failed to delete table " << fileName << " because it does not exist." << endl;
	}
}

//alterTb - Currently can only add to table
void alterTb(string s, string initS)
{
	int attrConversion = 0;
	string attributes;
	string fileName;
	//fileName is from substr after ADD command to end of command
	if(s.find("ADD") != -1)
	{
		fileName = initS.substr(12, s.find("ADD") - 13);
		attributes = initS.substr((s.find("ADD") + 3), s.find(";") - 3 - s.find("ADD"));
	}
	//ADD is only ALTER TABLE command available
	else
	{
		cout << "ADD is only ALTER TABLE command available" << endl;
	}
	//Can add multiple parameters
	while((attrConversion = attributes.find(",", attrConversion)) != -1)
	{
		attributes.replace(attrConversion, 1, "\n");
		attrConversion += 3;
	}
	ifstream checkFile;
	checkFile.open(fileName);
	//Check if file is valid
	if(checkFile)
	{
		checkFile.close();
		//Open file in append mode
		ofstream file(fileName, ios_base::app);
		//If string is meaningful and valid, write to table file
		if(attributes != "\n")
		{
		file << endl << attributes;
		}
		cout << "Table " << fileName << " modified" << endl;
		file.close();
	}
	//If file is invalid, table does not exist
	else
	{
		cout << "!Failed to alter table " << fileName << " because it does not exist." << endl;
		checkFile.close();
	}
}

//selectFrom - Query and output the table to select from
void selectFrom(string s, string initS)
{
	int count = 0;
	string fileName;
	//fileName is from substr after command to end of command
	fileName = initS.substr(14, initS.length() - 15);
	string attributes = "";
	//Check file if it exists
	ifstream checkFile;
	checkFile.open(fileName);
	if(checkFile)
	{
		checkFile.close();
		//Open file in read mode
		ifstream file;
		file.open(fileName);
		while(!file.eof())
		{
			//Get every valid line in table file
			getline(file, attributes, '\n');
			//Output first line
			if(count == 0)
			{
				cout << attributes;
			}
			//Every attribute afterwards is outputted with pipe |
			else
			{
				cout << " |" << attributes;
			}
			count ++;
		}
		file.close();
		cout << endl;
	}
	//If file does not exist, output message
	else
	{
		cout << "!Failed to query table " << fileName << " because it does not exist." << endl;
	}

}

//parseCommand - Parse commands from command line interface or through file
void parseCommand(string s, string initS)
{
	//If it is comment, do nothing
	if(s.find("--") == 0)
	{
		//Do nothing since comment
	}
	else if(s.find(".EXIT") != -1)
	{
		//Do nothing since it is exit
	}
	//Parse if there is a semicolon, to indicate it is a command
	else if(s.find(";") != -1)
	{
		//Exit the program
		
		//Call createDb if not currently using a database to create a database.
		//Cant make database in a database
		if(s.find("CREATE DATABASE ") != -1) 
		{
			if(usingDB == 0)
			{
				createDb(s, initS);
			}
			else
			{
				cout << "Cannot create database while using a database" << endl;
			}
		}
		//Call dropDb if not using a database to delete a database
		//Can only delete if not using a database
		//Cant delete database in a database
		else if(s.find("DROP DATABASE ") != -1)
		{
			if(usingDB == 0)
			{
				dropDb(s, initS);
			}
			else
			{
				cout << "Cannot delete database while using a database" << endl;
			}
		}
		//Call Use database 
		//Cd into database if available to be able to create and modify tables
		else if(s.find("USE ") != -1)
		{
			useDb(s, initS);
		}
		//Call createTb 
		//Can only create table files if database is in use
		else if(s.find("CREATE TABLE ") != -1)
		{
			if(usingDB == 1)
			{
				createTb(s, initS);
			}
			else
			{
				cout << "Cannot create tables without using a database" << endl;
			}
		}
		//Call dropTb
		//Can only delete table files if database is in use
		else if(s.find("DROP TABLE ") != -1)
		{
			if(usingDB == 1)
			{
				dropTb(s, initS);
			}
			else
			{
				cout << "Cannot delete tables without using a database" << endl;
			}
		}
		//Call alterTb
		//Can only modify/alter table files if database is in use
		else if(s.find("ALTER TABLE ") != -1)
		{
			if(usingDB == 1)
			{
				alterTb(s, initS);
			}
			else
			{
				cout << "Cannot alter tables without using a database" << endl;
			}
		}
		//Call selectFrom
		//Can only select from a table if database is in use
		else if(s.find("SELECT * FROM") != -1)
		{
				if(usingDB == 1)
				{
					selectFrom(s, initS);
				}
				else
				{
					cout << "Cannot select from tables without using a database" << endl;
				}

		}
	}
	//If not comment or command, not valid
	else if(s != "" && s.find(";") == -1)
	{
		cout << "Not a valid command..." << endl;
	}
}


