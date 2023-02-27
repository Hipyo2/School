//Nicholas Ang
//CS457
//Project Assignment 5

//Libraries
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sys/stat.h>
#include <unistd.h>
#include <limits>
#include <algorithm>
using namespace std;

//Function Declarations
//p1 functions
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

//p2 functions
void insertInto(string s, string initS);
void update(string s, string initS);
void deleteFrom(string s, string initS);
void select(string s, string initS);
string removeQuotes(string s);
string removeWS(string s);

//p3 functions
void innerJoin(string s, string initS);
void leftOuterJoin(string s, string initS);

//p4 functions
void clearTable();
void commitTransaction();

//p5 functions
void count(string s, string initS);
void avg(string s, string initS);
void max(string s, string initS);

//Global Variables
bool usingDB = 0;
bool commit = 0;
int currLineNum;
int currTotalCol;
string currentDB = "";
string currentTB = "";
//Global table 
string stringTable[50][50];

//Main function
int main(int argc, char* argv[])
{
	//Uppercase string
	string s;
	
	//Initial string
	string initS;
	string appendString;
	bool exitCondition = 0;
	//file command use
	if(argc == 1)
	{
		cout << "Interactive Mode" << endl;
		//Interactive mode - type commands one by one.
		do
		{
			getline(cin,appendString);
			//initS = s;
			//s = stringUpper(s);
			if(stringUpper(appendString).find(".EXIT") != -1)
			{
				exitCondition = 1;
			}
			else
			{
				//Append if doesn't find semicolon
				if(appendString.find(";") == -1)
				{
					if(appendString.find("--") != -1)
					{
						appendString = "";
					}
					else
					{
					const std::string::size_type position = appendString.find('\r');
					if (position != std::string::npos)
					{
					appendString.erase(position);
					}
					s.append(appendString);
					}
				}

				else
				{
				s.append(appendString);
				removeQuotes(s);
				removeWS(s);
				initS = s;
				s = stringUpper(s);
				parseCommand(s,initS);
				s.clear();
				}
				parseCommand(s, initS);
			}
		}
		while(exitCondition == 0);
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
	string s,initS,appendString;
	//Parse every line in the file until it finds .EXIT or file ends
	while(!file.eof() && appendString.find(".EXIT") == -1)
	{
		getline(file,appendString, '\n');
		if(appendString.find("--") != -1 || appendString.find(".EXIT") != -1 )
		{
		}
		else
		{
			if(appendString.find(";") == -1)
			{
			const std::string::size_type position = appendString.find('\r');
			if (position != std::string::npos)
			{
			appendString.erase(position);
			}
			s.append(appendString);
			}

			//cout << s << endl;
			else
			{
			s.append(appendString);
			initS = s;
			//cout << initS << endl;
			s = stringUpper(s);
			//cout << s << endl;
			parseCommand(s,initS);
			s.clear();
			}
		}

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
	dbName = initS.substr(16, initS.find(";") - 16);
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
	dbName = initS.substr(14, initS.find(";") - 14);
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
	dbName = initS.substr(4, initS.find(";") - 4);
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
	fileName = s.substr(13, s.find("(")-14);
	attributes = initS.substr(initS.find("(") + 1, initS.find(";") - 2 - initS.find("("));
	}
	//Filename from substr from after "CREATE TABLE" to end
	//No attributes if no parameters ()
	else
	{
	fileName = s.substr(13, initS.find(";") - 13);
	attributes = "";
	}
	
	ifstream checkFile;
	checkFile.open(fileName);
	//Check if file exists by checking if it can open the file in read mode
	if(checkFile)
	{
		cout << "!Failed to create table " << initS.substr(13, initS.find("(") - 14) << " because it already exists." << endl;
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
			attributes.replace(attrConversion, 2, "|");
			attrConversion += 3;
		}
		//Output attributes into file
		file << attributes << endl;
		cout << "Table " << initS.substr(13, initS.find("(") - 14) << " created" << endl;
		file.close();
	}
}

//dropTb - Delete table in a database
void dropTb(string s, string initS)
{
	string fileName;
	fileName = s.substr(11, s.find(";") - 11);
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
		fileName = s.substr(12, s.find("ADD") - 13);
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
	fileName = s.substr(14, s.find(";") - 14);
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
			//Output line
			cout << attributes << endl;
		}
		file.close();
	}
	//If file does not exist, output message
	else
	{
		cout << "!Failed to query table " << fileName << " because it does not exist." << endl;
	}

}

//insertInto - Insert records into the table
void insertInto(string s, string initS)
{
	s = removeQuotes(s);
	initS = removeQuotes(initS);
	int attrConversion = 0;
	string attributes;
	string fileName;
	//fileName is from substr after ADD command to end of command
	if(s.find("VALUES") != -1)
	{
		fileName = s.substr(12, s.find("VALUES") - 13);
		attributes = initS.substr((s.find("VALUES") + 8), s.find(";") - 9 - s.find("VALUES"));
		attributes = removeWS(attributes);
	}
	//Can add multiple parameters
	while((attrConversion = attributes.find(",", attrConversion)) != -1)
	{
		attributes.replace(attrConversion, 1, "|");
		attrConversion += 1;
	}
	
	attrConversion = 0;
	//If no parameter is given, set NULL
	while((attrConversion = attributes.find("||", attrConversion)) != -1)
	{
		attributes.replace(attrConversion, 2, "|NULL|");
		attrConversion += 6;
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
		if(attributes != "")
		{
		file << attributes << endl;
		}
		cout << "1 new record inserted" << endl;
		file.close();
	}
	//If file is invalid, table does not exist
	else
	{
		cout << "!Failed to insert into table " << fileName << " because it does not exist." << endl;
		checkFile.close();
	}
}

//Update - Update and change records inside the table
void update(string s, string initS)
{
	//Variables
	s = removeQuotes(s);
	initS = removeQuotes(initS);
	int totalColumns;
	int currColumns;
	int whereColumns;
	string fileName;
	string whereField;
	string whereVal;
	string setField;
	string setVal;
	string currLine;
	string cutLine;

	int lineNum = 0;
	int modifyCounter = 0;
	
	clearTable();
	
	//Find set keyword and get where fields, where values, set fields, and set values
	if(s.find("SET") != -1)
	{
		if(s.find("WHERE") != -1)
		{
		fileName = s.substr(7, s.find("SET") - 8);
		setField = initS.substr(s.find("SET")+4, s.find("=") - (s.find("SET") + 4) -1);
		setVal = initS.substr(s.find("=")+2, s.find("WHERE")-(s.find("=")+2)-1);
		
			if(s.find(" = ", s.find("WHERE")+6) != -1)
			{
			whereField = initS.substr(s.find("WHERE")+6, s.find("=", s.find("WHERE")+6) - (s.find("WHERE") + 6) - 1);
			whereVal = initS.substr(s.find("=", s.find("WHERE")+6)+2, s.find(";") - (s.find("=", s.find("WHERE")+6)+2));
			}
			else if(s.find("!=") != -1)
			{
			whereField = initS.substr(s.find("WHERE")+6, s.find("!=", s.find("WHERE")+6) - (s.find("WHERE") + 6) - 1);
			whereVal = initS.substr(s.find("!=", s.find("WHERE")+6)+3, s.find(";") - (s.find("!=", s.find("WHERE")+6)+3));
			}
			else if(s.find(">") != -1)
			{
			whereField = initS.substr(s.find("WHERE")+6, s.find(">", s.find("WHERE")+6) - (s.find("WHERE") + 6) - 1);
			whereVal = initS.substr(s.find(">", s.find("WHERE")+6)+2, s.find(";") - (s.find(">", s.find("WHERE")+6)+2));
			}
			else if(s.find("<") != -1)
			{
			whereField = initS.substr(s.find("WHERE")+6, s.find("<", s.find("WHERE")+6) - (s.find("WHERE") + 6) - 1);
			whereVal = initS.substr(s.find("<", s.find("WHERE")+6)+2, s.find(";") - (s.find("<", s.find("WHERE")+6)+2));
			}
		}
	}
	
	ifstream checkFile;
	checkFile.open(fileName);
	
	ifstream lockFile;
	lockFile.open(fileName + "_lock");

	getline(checkFile, currLine, '\n');
	totalColumns = count(currLine.begin(), currLine.end(), '|');

	//Check if file is valid
	if(checkFile)
	{
		currentTB = currentTB + fileName; 
		if(!lockFile)
		{
			lockFile.close();
			ofstream lockFile;
			lockFile.open(fileName + "_lock");
			//Create Table with file data
			while(!checkFile.eof())
			{
				
				for(int i = 0; i <= totalColumns; i++)
				{
					cutLine = currLine.substr(0, currLine.find("|"));
					currLine = currLine.substr(currLine.find("|")+1, currLine.find_last_of(currLine));
					stringTable[lineNum][i] = cutLine;
				}
				lineNum++;
				getline(checkFile, currLine, '\n');
			}
		
			ifstream fin(fileName);   
			//ofstream fout;                
			//fout.open("temp.txt", ios_base::app);
			for(int j = 0; j <= totalColumns; j++)
			{
				if((stringTable[0][j]).find(whereField) != -1)
				{
				whereColumns = j;
				}
			}
			
			for(int j = 0; j <= totalColumns; j++)
			{
				if((stringTable[0][j]).find(setField) != -1)
				{
				currColumns = j;
				}
			}
			
				string temp;
				//If !=, find record and update every other record
				if(s.find("!=") != -1)
				{
					for(int i = 0; i < lineNum; i++)
					{
						if(stringTable[i][whereColumns] != whereVal && i != 0)
						{
						stringTable[i][currColumns] = setVal;
						modifyCounter++;
						}
						/*for(int j = 0; j <= totalColumns; j++)
						{
							if(j != totalColumns)
							{
								fout << stringTable[i][j] << "|";
							}
							else
							{
								fout << stringTable[i][j] << endl;
							}
						}*/
					}
				}
				//If =, find record and update the record
				else if(s.find(" = ") != -1)
				{
					for(int i = 0; i < lineNum; i++)
					{
						if(stringTable[i][whereColumns] == whereVal && i != 0)
						{
						stringTable[i][currColumns] = setVal;
						modifyCounter++;
						}
						/*for(int j = 0; j <= totalColumns; j++)
						{
							if(j != totalColumns)
							{
								fout << stringTable[i][j] << "|";
							}
							else
							{
								fout << stringTable[i][j] << endl;
							}
						}*/
					}
				}
				//If >, update values greater than. CAN ONLY BE USED WITH NUMBER COMPARISONS
				else if(s.find(" > ") != -1)
				{
					for(int i = 0; i < lineNum; i++)
					{
						if(stoi(stringTable[i][whereColumns]) > stoi(whereVal) && i != 0)
						{
						stringTable[i][currColumns] = setVal;
						modifyCounter++;
						}
						/*for(int j = 0; j <= totalColumns; j++)
						{
							if(j != totalColumns)
							{
								fout << stringTable[i][j] << "|";
							}
							else
							{
								fout << stringTable[i][j] << endl;
							}
						}*/
					}
				}
				//If >, update values less than. CAN ONLY BE USED WITH NUMBER COMPARISONS
				else if(s.find(" < ") != -1)
				{
					for(int i = 0; i < lineNum; i++)
					{
						if(stoi(stringTable[i][whereColumns]) < stoi(whereVal) && i != 0)
						{
						stringTable[i][currColumns] = setVal;
						modifyCounter++;
						}
						/*for(int j = 0; j <= totalColumns; j++)
						{
							if(j != totalColumns)
							{
								fout << stringTable[i][j] << "|";
							}
							else
							{
								fout << stringTable[i][j] << endl;
							}
						}*/
					}			
				}
			//Output how many records are modified
			if(modifyCounter > 0)
			{
				cout << modifyCounter << " records modified" << endl;
				currLineNum = lineNum;
				currTotalCol = totalColumns;
				commit = 1;
			}
			else
			{
				cout << "0 records modified" << endl;
			}
			//fout.close();  
			fin.close();  
			checkFile.close(); 
			//remove(fileName.c_str());        
			//rename("temp.txt", fileName.c_str());
			//file.close();
		}
		else
		{
			cout << "ERROR: Table " << fileName << " is locked." << endl;
			commit = 0;
		}
	}
	//If file is invalid, table does not exist
	else
	{
		cout << "!Failed to update record" << endl;
		checkFile.close();
	}
	
}

//deleteFrom - delete records from table where specified
void deleteFrom(string s, string initS)
{
	//Variables
	s = removeQuotes(s);
	initS = removeQuotes(initS);
	int totalColumns;
	int currColumns = 0;
	string fileName;
	string whereField;
	string whereVal;
	string currLine;
	string cutLine;	  
	int lineNum = 0;
	int deleteCounter = 0;
	
	clearTable();
	//Get file name
	fileName = s.substr(s.find("FROM")+5, s.find("WHERE") - (s.find("FROM") + 5)-1);
	//Find whereFields and whereValues with appropriate operators =, !=, >, <
	if(s.find(" = ") != -1)
	{
		whereField = initS.substr(s.find("WHERE")+6, s.find("=") - (s.find("WHERE") + 6)-1);
		whereVal = initS.substr(s.find("=")+2, s.find(";")-(s.find("=")+2));
	}
	else if(s.find(">") != -1)
	{
		whereField = initS.substr(s.find("WHERE")+6, s.find(">") - (s.find("WHERE") + 6)-1);
		whereVal = initS.substr(s.find(">")+2, s.find(";")-(s.find(">")+2));
	}
	else if(s.find("<") != -1)
	{
		whereField = initS.substr(s.find("WHERE")+6, s.find("<") - (s.find("WHERE") + 6)-1);
		whereVal = initS.substr(s.find("<")+2, s.find(";")-(s.find("<")+2));
	}
	else if(s.find("!=") != -1)
	{
		whereField = initS.substr(s.find("WHERE")+6, s.find("!=") - (s.find("WHERE") + 6)-1);
		whereVal = initS.substr(s.find("!=")+3, s.find(";")-(s.find("!=")+3));
	}
		
	ifstream checkFile;
	checkFile.open(fileName);

	getline(checkFile, currLine, '\n');
	totalColumns = count(currLine.begin(), currLine.end(), '|');
	//Check if file is valid
	if(checkFile)
	{
		//Create Table with file data
		while(!checkFile.eof())
		{
			
			for(int i = 0; i <= totalColumns; i++)
			{
				cutLine = currLine.substr(0, currLine.find("|"));
				currLine = currLine.substr(currLine.find("|")+1, currLine.find_last_of(currLine));
				stringTable[lineNum][i] = cutLine;
			}
			lineNum++;
			getline(checkFile, currLine, '\n');
		}
		
		ifstream fin(fileName);    
		ofstream fout;                
		fout.open("temp.txt", ios_base::app);
		for(int j = 0; j <= totalColumns; j++)
		{
			if((stringTable[0][j]).find(whereField) != -1)
			{
			currColumns = j;
			}
		}
			string temp;
			//If !=, find record and only keep the record
			if(s.find("!=") != -1)
			{
				for(int i = 0; i < lineNum; i++)
				{
					if(stringTable[i][currColumns] != whereVal && i != 0)
					{
					//Skip line
					deleteCounter++;
					}
					else
					{
						for(int j = 0; j <= totalColumns; j++)
						{
							if(j != totalColumns)
							{
								fout << stringTable[i][j] << "|";
							}
							else
							{
								fout << stringTable[i][j] << endl;
							}
						}
					}
				}
			}
			//If =, find record and delete the record
			else if(s.find(" = ") != -1)
			{
				for(int i = 0; i < lineNum; i++)
				{
					if(stringTable[i][currColumns] == whereVal && i != 0)
					{
					//Skip line
					deleteCounter++;
					}
					else
					{
						for(int j = 0; j <= totalColumns; j++)
						{
							if(j != totalColumns)
							{
								fout << stringTable[i][j] << "|";
							}
							else
							{
								fout << stringTable[i][j] << endl;
							}
						}
					}
				}
			}
			//If >, delete values greater than. CAN ONLY BE USED WITH NUMBER COMPARISONS
			else if(s.find(" > ") != -1)
			{
				for(int i = 0; i < lineNum; i++)
				{
					if(i != 0)
					{
						temp = stringTable[i][currColumns];
						cout << temp;
						if(stoi(temp) > stoi(whereVal))
						{
						//Skip line
						deleteCounter++;
						}
						else
						{
							for(int j = 0; j <= totalColumns; j++)
							{
								if(j != totalColumns)
								{
									fout << stringTable[i][j] << "|";
								}
								else
								{
									fout << stringTable[i][j] << endl;
								}
							}
						}
					}
					else
					{
						for(int j = 0; j <= totalColumns; j++)
						{
							if(j != totalColumns)
							{
								fout << stringTable[i][j] << "|";
							}
							else
							{
								fout << stringTable[i][j] << endl;
							}
						}
					}
				}
			}
			//If >, delete values less than. CAN ONLY BE USED WITH NUMBER COMPARISONS
			else if(s.find(" < ") != -1)
			{
				for(int i = 0; i < lineNum; i++)
				{
					if(stoi(stringTable[i][currColumns]) < stoi(whereVal) && i != 0)
					{
						if(stoi(stringTable[i][currColumns]) < stoi(whereVal))
						{
						//Skip line
						deleteCounter++;
						}
						else
						{
							for(int j = 0; j <= totalColumns; j++)
							{
								if(j != totalColumns)
								{
									fout << stringTable[i][j] << "|";
								}
								else
								{
									fout << stringTable[i][j] << endl;
								}
							}
						}
					}
					else
					{
						for(int j = 0; j <= totalColumns; j++)
						{
							if(j != totalColumns)
							{
								fout << stringTable[i][j] << "|";
							}
							else
							{
								fout << stringTable[i][j] << endl;
							}
						}
					}
				}			
			}
		//Output amount of records deleted
		if(deleteCounter > 0)
		{
			cout << deleteCounter << " records deleted" << endl;
		}
		fout.close();  
		fin.close();  
		checkFile.close(); 
		remove(fileName.c_str());        
		rename("temp.txt", fileName.c_str());
		//file.close();
	}
	//If file is invalid, table does not exist
	else
	{
		cout << "!Failed to delete record" << endl;
		checkFile.close();
	}
}

void select(string s, string initS)
{
	//Variables
	s = removeQuotes(s);
	initS = removeQuotes(initS);
	int totalColumns;
	int currColumns[100];
	int whereColumn;
	int lineNum = 0;
	int commaNum = 0;
	string attributes;
	string fileName;
	string whereField;
	string selectStatement;
	string selectField[100];
	string whereVal;
	string currLine;
	string cutLine;
	string whereString;
	
	clearTable();
	
	//Select statement and find fileName, fields to select, whereFields, and where values
	if(s.find("SELECT") != -1)
	{
		fileName = s.substr(s.find("FROM")+5, s.find("WHERE") - (s.find("FROM") + 5)- 1);
		selectStatement = initS.substr(s.find("SELECT")+7, (s.find("FROM")-7) - 1);
		if(s.find(" = ") != -1)
		{
			whereField = initS.substr(s.find("WHERE")+6, s.find("=") - (s.find("WHERE") + 6) - 1);
			whereVal = initS.substr(s.find("=")+2, s.find(";")-(s.find("=")+2));
		}
		else if(s.find(">") != -1)
		{
			whereField = initS.substr(s.find("WHERE")+6, s.find(">") - (s.find("WHERE") + 6) - 1);
			whereVal = initS.substr(s.find(">")+2, s.find(";")-(s.find(">")+2));
		}
		else if(s.find("<") != -1)
		{
			whereField = initS.substr(s.find("WHERE")+6, s.find("<") - (s.find("WHERE") + 6) - 1);
			whereVal = initS.substr(s.find("<")+2, s.find(";")-(s.find("<")+2));
		}
		else if(s.find("!=") != -1)
		{
			whereField = initS.substr(s.find("WHERE")+6, s.find("!=") - (s.find("WHERE") + 6) - 1);
			whereVal = initS.substr(s.find("!=")+3, s.find(";")-(s.find("!=")+3));
		}
	
		//Separate fields selected by comma
		if(selectStatement.find(",") != -1)
		{
			while(selectStatement.find(",") != -1)
			{
				selectField[commaNum] = selectStatement.substr(0, selectStatement.find(","));
				selectStatement = selectStatement.substr(selectStatement.find(",") + 2, selectStatement.find_last_of(selectStatement));
				commaNum++;
			}
			selectField[commaNum] = selectStatement;
		}
		//If no comma, field is by itself
		else
		{
			selectField[0] = initS.substr(s.find("SELECT")+7, s.find("FROM") - (s.find("SELECT")+7) - 1);
		}
	}
	
	ifstream checkFile;
	checkFile.open(fileName);

	getline(checkFile, currLine, '\n');
	totalColumns = count(currLine.begin(), currLine.end(), '|');
	//Check if file is valid
	if(checkFile)
	{
		//Create Table with file data
		while(!checkFile.eof())
		{
			
			for(int i = 0; i <= totalColumns; i++)
			{
				cutLine = currLine.substr(0, currLine.find("|"));
				currLine = currLine.substr(currLine.find("|")+1, currLine.find_last_of(currLine));
				stringTable[lineNum][i] = cutLine;
			}
			lineNum++;
			getline(checkFile, currLine, '\n');
		}
		
		ifstream fin(fileName);    
		ofstream fout;                
		fout.open("temp.txt", ios_base::app);
		for(int j = 0; j <= totalColumns; j++)
		{
			if((stringTable[0][j]).find(whereField) != -1)
			{
			currColumns[0] = j;
			}
		}
		for(int i = 0; i <= commaNum; i++)
		{
			for(int j = 0; j <= totalColumns; j++)
			{
				if((stringTable[0][j]).find(selectField[i]) != -1)
				{
				currColumns[i+1] = j;
				}
			}
		}
			string temp;
			//If !=, find record and only keep the record
			if(s.find("!=") != -1)
			{
				for(int i = 0; i < lineNum; i++)
				{
					if(stringTable[i][currColumns[0]] != whereVal && i != 0)
					{
						for(int j = 0; j <= commaNum; j++)
						{
							if(j != commaNum)
							{
								fout << stringTable[i][currColumns[j+1]] << "|";
							}
							else
							{
								fout << stringTable[i][currColumns[j+1]] << endl;
							}
						}
					}
					else if(i == 0)
					{
						for(int j = 0; j <= commaNum; j++)
						{
							if(j != commaNum)
							{
								fout << stringTable[i][currColumns[j+1]] << "|";
							}
							else
							{
								fout << stringTable[i][currColumns[j+1]] << endl;
							}
						}
					}
				}	
			}
			//If =, find record and delete the record
			else if(s.find(" = ") != -1)
			{
				for(int i = 0; i < lineNum; i++)
				{
					if(stringTable[i][currColumns[0]] == whereVal && i != 0)
					{
						for(int j = 0; j <= commaNum; j++)
						{
							if(j != commaNum)
							{
								fout << stringTable[i][currColumns[j+1]] << "|";
							}
							else
							{
								fout << stringTable[i][currColumns[j+1]] << endl;
							}
						}
					}
					else if(i == 0)
					{
						for(int j = 0; j <= commaNum; j++)
						{
							if(j != commaNum)
							{
								fout << stringTable[i][currColumns[j+1]] << "|";
							}
							else
							{
								fout << stringTable[i][currColumns[j+1]] << endl;
							}
						}
					}
				}
			}
			//If >, delete values greater than. CAN ONLY BE USED WITH NUMBER COMPARISONS
			else if(s.find(" > ") != -1)
			{
				for(int i = 0; i < lineNum; i++)
				{
					if(i != 0)
					{
						if(stoi(stringTable[i][currColumns[0]]) > stoi(whereVal))
						{
							for(int j = 0; j <= commaNum; j++)
							{
								if(j != commaNum)
								{
									fout << stringTable[i][currColumns[j+1]] << "|";
								}
								else
								{
									fout << stringTable[i][currColumns[j+1]] << endl;
								}
							}
						}
					}
					else if(i == 0)
					{
						for(int j = 0; j <= commaNum; j++)
						{
							if(j != commaNum)
							{
								fout << stringTable[i][currColumns[j+1]] << "|";
							}
							else
							{
								fout << stringTable[i][currColumns[j+1]] << endl;
							}
						}
					}
				}
			}
			//If >, delete values less than. CAN ONLY BE USED WITH NUMBER COMPARISONS
			else if(s.find(" < ") != -1)
			{
				for(int i = 0; i < lineNum; i++)
				{
					if(i != 0)
					{
						if(stoi(stringTable[i][currColumns[0]]) < stoi(whereVal))
						{
							for(int j = 0; j <= commaNum; j++)
							{
								if(j != commaNum)
								{
									fout << stringTable[i][currColumns[j+1]] << "|";
								}
								else
								{
									fout << stringTable[i][currColumns[j+1]] << endl;
								}
							}
						}
					}
					else if(i == 0)
					{
						for(int j = 0; j <= commaNum; j++)
						{
							if(j != commaNum)
							{
								fout << stringTable[i][currColumns[j+1]] << "|";
							}
							else
							{
								fout << stringTable[i][currColumns[j+1]] << endl;
							}
						}
					}
				}			
			}
	
		fout.close();  
		fin.close();  
		checkFile.close(); 
		
		ifstream file;
		file.open("temp.txt");
		while(!file.eof())
		{
			//Get every valid line in table file
			getline(file, attributes, '\n');
			//Output line
			cout << attributes << endl;
		}
		file.close();
		//remove temporary text file
		remove("temp.txt");        
	}
	//If file is invalid, table does not exist
	else
	{
		cout << "!Failed to select record" << endl;
		checkFile.close();
	}
}

//Remove and clean up quotes
string removeQuotes(string s)
{
	while(s.find("'") != -1)
	{
		s.erase(s.find("'"), 1);
	}
	return s;
}

//Remove and clean up white space and tab spacing
string removeWS(string s)
{
	while(s.find(" ") != -1)
	{
		s.erase(s.find(" "), 1);
	}
	while(s.find('\t') != -1)
	{
		s.erase(s.find('\t'), 1);
	}
	return s;
}

//Inner Join command to join two tables using aliases and output the joined table to the terminal
void innerJoin(string s, string initS)
{
	//tables 1 and 2
	string stringTable1[50][50];
	string stringTable2[50][50];
	//joined table
	string stringTable3[50][50];
	
	//Variables
	s = removeQuotes(s);
	initS = removeQuotes(initS);
	string fileName1;
	string alias1;
	string fileName2;
	string alias2;
	string field1, field2;
	int totalColumns1, totalColumns2;
	int whereColumn1, whereColumn2;
	int lineNum1 = 0; 
	int lineNum2 = 0;
	int lineSimilar = 0;
	int row = 1;
	string currLine;
	string cutLine;
	
	//Inner Join with WHERE keyword
	if(s.find("WHERE") != -1)
	{
	fileName1 = s.substr(14, s.find(",") - 16);
	alias1 = initS.substr(s.find(fileName1) + fileName1.length() + 1, s.find(",") - (s.find(fileName1) + fileName1.length() + 1));
	
	fileName2 = s.substr(s.find(",")+2,s.find("WHERE")-2-3-(s.find(",")));
	alias2 = initS.substr(s.find(fileName2) + fileName2.length() + 1, s.find("WHERE") - (s.find(fileName2) + fileName2.length() + 2));
	
	field1 = initS.substr(s.find((alias1+"."))+2, s.find("=") - (s.find((alias1+"."))+3));
	field2 = initS.substr(s.find((alias2+"."))+2, s.find(";") - (s.find((alias2+"."))+2));
	}
	//Inner Join with INNER JOIN keyword
	else if(s.find("INNER JOIN") != -1)
	{
		if(s.find("ON") != -1)
		{
		fileName1 = s.substr(14, s.find("INNER JOIN") - 17);
		alias1 = initS.substr(s.find(fileName1) + fileName1.length() + 1, s.find("INNER JOIN") - (s.find(fileName1) + fileName1.length() + 2));
		
		fileName2 = s.substr(s.find("INNER JOIN")+11,s.find("ON")-11-3-(s.find("INNER JOIN")));
		alias2 = initS.substr(s.find(fileName2) + fileName2.length() + 1, s.find("ON") - (s.find(fileName2) + fileName2.length() + 2));
		
		field1 = initS.substr(s.find((alias1+"."))+2, s.find("=") - (s.find((alias1+"."))+3));
		field2 = initS.substr(s.find((alias2+"."))+2, s.find(";") - (s.find((alias2+"."))+2));
		}
		else
		{
		cout << "ERROR" << endl;
		}
	}
	
	//TABLE 1
	ifstream checkFile;
	checkFile.open(fileName1);

	getline(checkFile, currLine, '\n');
	totalColumns1 = count(currLine.begin(), currLine.end(), '|');
	//Check if file is valid
	if(checkFile)
	{
		//Create Table with file data
		while(!checkFile.eof())
		{
			
			for(int i = 0; i <= totalColumns1; i++)
			{
				cutLine = currLine.substr(0, currLine.find("|"));
				currLine = currLine.substr(currLine.find("|")+1, currLine.find_last_of(currLine));
				stringTable1[lineNum1][i] = cutLine;
			}
			lineNum1++;
			getline(checkFile, currLine, '\n');
		}
	}
	else
	{
		cout << "Table does not exist" << endl;
	}
	checkFile.close();
	
	//TABLE 2
	checkFile.open(fileName2);

	getline(checkFile, currLine, '\n');
	totalColumns2 = count(currLine.begin(), currLine.end(), '|');
	//Check if file is valid
	if(checkFile)
	{
		//Create Table with file data
		while(!checkFile.eof())
		{
			
			for(int i = 0; i <= totalColumns2; i++)
			{
				cutLine = currLine.substr(0, currLine.find("|"));
				currLine = currLine.substr(currLine.find("|")+1, currLine.find_last_of(currLine));
				stringTable2[lineNum2][i] = cutLine;
			}
			lineNum2++;
			getline(checkFile, currLine, '\n');
		}
	}
	else
	{
		cout << "Table does not exist" << endl;
	}
	checkFile.close();
	
	//Find index for where field for both tables
	for(int j = 0; j <= totalColumns1; j++)
	{
		if((stringTable1[0][j]).find(field1) != -1)
		{
		whereColumn1 = j;
		}
	}
	for(int j = 0; j <= totalColumns2; j++)
	{
		if((stringTable2[0][j]).find(field2) != -1)
		{
		whereColumn2 = j;
		}
	}

	//for rows of first table
	for(int i = 0; i <= lineNum1; i++)
	{
		//Add table attributes of join
		if(i == 0)
		{
			int columns = 0;
			for(int j = 0; j <= totalColumns1; j++)
			{
				stringTable3[i][columns] = stringTable1[i][j];
				columns++;
			}
			for(int j = 0; j <= totalColumns2; j++)
			{
				stringTable3[i][columns] = stringTable2[i][j];
				columns++;
			}
		}
		//Add records of join
		else
		{
			//for rows of second table
			//Loop through each row of each table and compare values
			for(int k = 1; k <= lineNum2; k++)
			{
				//If equal at where column location, add to joined table
				if(stringTable1[i][whereColumn1] == stringTable2[k][whereColumn2])
				{
					
					int columns = 0;
					for(int j = 0; j <= totalColumns1; j++)
					{
						stringTable3[row][columns] = stringTable1[i][j];
						columns++;
					}
					for(int j = 0; j <= totalColumns2; j++)
					{
						stringTable3[row][columns] = stringTable2[k][j];
						columns++;
					}
					lineSimilar++;
					row++;
				}
			}
		}
	}
	//Output joined table to terminal
	for(int i = 0; i < lineSimilar; i++)
	{
		for(int j = 0; j <= (totalColumns1+totalColumns2+1); j++)
		{
			if(j != (totalColumns1+totalColumns2+1))
			{
				cout << stringTable3[i][j] << "|";
			}
			else
			{
				cout << stringTable3[i][j] << endl;
			}
		}	
	}
}

//Outer join command to join two tables using aliases and output the joined table to the terminal, joined table can have null values
void leftOuterJoin(string s, string initS)
{
	//Tables 1 and 2
	string stringTable1[50][50];
	string stringTable2[50][50];
	//Joined table
	string stringTable3[50][50];
	//Variables
	s = removeQuotes(s);
	initS = removeQuotes(initS);
	string fileName1;
	string alias1;
	string fileName2;
	string alias2;
	string field1, field2;
	int totalColumns1, totalColumns2;
	int whereColumn1, whereColumn2;
	int lineNum1 = 0; 
	int lineNum2 = 0;
	int lineSimilar = 0;
	int row = 1;
	string currLine;
	string cutLine;
	//If Left outer join is found, set values of fields, aliases, and file names
	if(s.find("LEFT OUTER JOIN") != -1)
	{
		if(s.find("ON") != -1)
		{
		fileName1 = s.substr(14, s.find("LEFT OUTER JOIN") - 17);
		alias1 = initS.substr(s.find(fileName1) + fileName1.length() + 1, s.find("LEFT OUTER JOIN") - (s.find(fileName1) + fileName1.length() + 2));
		
		fileName2 = s.substr(s.find("LEFT OUTER JOIN")+16,s.find("ON")-16-3-(s.find("LEFT OUTER JOIN")));
		alias2 = initS.substr(s.find(fileName2) + fileName2.length() + 1, s.find("ON") - (s.find(fileName2) + fileName2.length() + 2));
		
		field1 = initS.substr(s.find((alias1+"."))+2, s.find("=") - (s.find((alias1+"."))+3));
		field2 = initS.substr(s.find((alias2+"."))+2, s.find(";") - (s.find((alias2+"."))+2));
		}
		else
		{
		cout << "ERROR" << endl;
		}
	}
	
	//TABLE 1
	ifstream checkFile;
	checkFile.open(fileName1);

	getline(checkFile, currLine, '\n');
	totalColumns1 = count(currLine.begin(), currLine.end(), '|');
	//Check if file is valid
	if(checkFile)
	{
		//Create Table with file data
		while(!checkFile.eof())
		{
			
			for(int i = 0; i <= totalColumns1; i++)
			{
				cutLine = currLine.substr(0, currLine.find("|"));
				currLine = currLine.substr(currLine.find("|")+1, currLine.find_last_of(currLine));
				stringTable1[lineNum1][i] = cutLine;
			}
			lineNum1++;
			getline(checkFile, currLine, '\n');
		}
	}
	else
	{
		cout << "Table does not exist" << endl;
	}
	checkFile.close();
	
	//TABLE 2
	checkFile.open(fileName2);

	getline(checkFile, currLine, '\n');
	totalColumns2 = count(currLine.begin(), currLine.end(), '|');
	//Check if file is valid
	if(checkFile)
	{
		//Create Table with file data
		while(!checkFile.eof())
		{
			
			for(int i = 0; i <= totalColumns2; i++)
			{
				cutLine = currLine.substr(0, currLine.find("|"));
				currLine = currLine.substr(currLine.find("|")+1, currLine.find_last_of(currLine));
				stringTable2[lineNum2][i] = cutLine;
			}
			lineNum2++;
			getline(checkFile, currLine, '\n');
		}
	}
	else
	{
		cout << "Table does not exist" << endl;
	}
	checkFile.close();
	
	//Find where columns of where fields in both tables
	for(int j = 0; j <= totalColumns1; j++)
	{
		if((stringTable1[0][j]).find(field1) != -1)
		{
		whereColumn1 = j;
		}
	}
	for(int j = 0; j <= totalColumns2; j++)
	{
		if((stringTable2[0][j]).find(field2) != -1)
		{
		whereColumn2 = j;
		}
	}

	//for rows of first table
	for(int i = 0; i <= lineNum1; i++)
	{
		//Add attributes to joined table
		int outerJoin = 0;
		if(i == 0)
		{
			int columns = 0;
			for(int j = 0; j <= totalColumns1; j++)
			{
				stringTable3[i][columns] = stringTable1[i][j];
				columns++;
			}
			for(int j = 0; j <= totalColumns2; j++)
			{
				stringTable3[i][columns] = stringTable2[i][j];
				columns++;
			}
		}
		else
		{
			//for rows of 2nd table
			//Loop through each row of each table and compare values
			for(int k = 1; k <= lineNum2; k++)
			{
				//If match found, add to joined table
				if(stringTable1[i][whereColumn1] == stringTable2[k][whereColumn2])
				{
					outerJoin = 1;
					int columns = 0;
					for(int j = 0; j <= totalColumns1; j++)
					{
						stringTable3[row][columns] = stringTable1[i][j];
						columns++;
					}
					for(int j = 0; j <= totalColumns2; j++)
					{
						stringTable3[row][columns] = stringTable2[k][j];
						columns++;
					}
					lineSimilar++;
					row++;
				}
			}
			//If no match is found, add table 1 values to joined table and table 2 values are set null in joined table
			if(outerJoin == 0)
			{
				int columns = 0;
				for(int j = 0; j <= totalColumns1; j++)
				{
					stringTable3[row][columns] = stringTable1[i][j];
					columns++;
				}
				lineSimilar++;
				row++;
			}
		}
	}
	
	//Output joined table to terminal
	for(int i = 0; i < lineSimilar; i++)
	{
		for(int j = 0; j <= (totalColumns1+totalColumns2+1); j++)
		{
			if(j != (totalColumns1+totalColumns2+1))
			{
				cout << stringTable3[i][j] << "|";
			}
			else
			{
				cout << stringTable3[i][j] << endl;
			}
		}	
	}
}

void clearTable()
{
	for(int i = 0; i < 50; i++)
	{
		for(int j = 0; j < 50; j++)
		{
			stringTable[i][j] = -1;
		}
	}
}

void commitTransaction()
{
	if(currentTB != "")
	{
		if(commit == 1)
		{
			ofstream fout;                
			fout.open("temp.txt", ios_base::app);
			for(int i = 0; i < currLineNum; i++)
			{
				for(int j = 0; j <= currTotalCol; j++)
				{
					if(j != currTotalCol)
					{
						fout << stringTable[i][j] << "|";
					}
					else
					{
						fout << stringTable[i][j] << endl;
					}
				}
			}
			fout.close(); 
			remove(currentTB.c_str());        
			rename("temp.txt", currentTB.c_str());
			cout << "Transaction committed" << endl;
			string lockFileName = currentTB + "_lock";
			remove(lockFileName.c_str());
			currentTB = "";
			commit = 0;
		}
		else
		{
		cout << "Transaction Abort." << endl;
		commit = 0;
		}
	}
	else
	{
		cout << "No Tables modified....." << endl;
		commit = 0;
	}
}

void count(string s, string initS)
{
	string fileName;
	string currLine;
	int totalColumns = 0;
	int lineNum = 0;
	string cutLine;
	if(s.find("SELECT") != -1 && s.find("COUNT") != -1)
	{
		fileName = s.substr(21, s.find(";") - 21);
	}
	
	ifstream checkFile;
	checkFile.open(fileName);

	getline(checkFile, currLine, '\n');
	totalColumns = count(currLine.begin(), currLine.end(), '|');

	//Check if file is valid
	if(checkFile)
	{
		//Create Table with file data
		while(!checkFile.eof())
		{
			for(int i = 0; i <= totalColumns; i++)
			{
				cutLine = currLine.substr(0, currLine.find("|"));
				currLine = currLine.substr(currLine.find("|")+1, currLine.find_last_of(currLine));
				stringTable[lineNum][i] = cutLine;
			}
			lineNum++;
			getline(checkFile, currLine, '\n');
		}
		cout << "COUNT(*)" << endl;
		cout << lineNum-1 << endl;
	}
	//If file is invalid, table does not exist
	else
	{
		cout << "Table does not exist" << endl;
		checkFile.close();
	}
		
}

void avg(string s, string initS)
{
	//Variables
	s = removeQuotes(s);
	initS = removeQuotes(initS);
	int totalColumns;
	int currColumns;
	int lineNum = 0;
	double totalSum = 0;
	double avgVal = 0;
	string fileName;
	string whereField;
	string currLine;
	string cutLine;
	
	clearTable();
	
	if(s.find("SELECT") != -1 && s.find("AVG") != -1)
	{
		fileName = s.substr(s.find("FROM")+5, s.find(";") - (s.find("FROM") + 5));
		whereField = initS.substr(s.find("(")+1, s.find(")") - (s.find("(") + 1));
	}
	
	ifstream checkFile;
	checkFile.open(fileName);

	getline(checkFile, currLine, '\n');
	totalColumns = count(currLine.begin(), currLine.end(), '|');
	//Check if file is valid
	if(checkFile)
	{
		//Create Table with file data
		while(!checkFile.eof())
		{
			
			for(int i = 0; i <= totalColumns; i++)
			{
				cutLine = currLine.substr(0, currLine.find("|"));
				currLine = currLine.substr(currLine.find("|")+1, currLine.find_last_of(currLine));
				stringTable[lineNum][i] = cutLine;
			}
			lineNum++;
			getline(checkFile, currLine, '\n');
		}
		
		ifstream fin(fileName);    
		for(int j = 0; j <= totalColumns; j++)
		{
			if((stringTable[0][j]).find(whereField) != -1)
			{
			currColumns = j;
			}
		}

		if(s.find("AVG") != -1)
		{
				for(int i = 0; i < lineNum; i++)
				{
					if(i != 0)
					{
						totalSum = totalSum + stoi(stringTable[i][currColumns]);
					}
				}
		}			
		avgVal = totalSum/(lineNum-1);  
		fin.close();  
		checkFile.close(); 
		cout << "AVG(" << whereField << ")" << endl;
		cout << avgVal << endl;    
	}
	//If file is invalid, table does not exist
	else
	{
		cout << "Table does not exist" << endl;
		checkFile.close();
	}
}

void max(string s, string initS)
{
	//Variables
	s = removeQuotes(s);
	initS = removeQuotes(initS);
	int totalColumns;
	int currColumns;
	int lineNum = 0;
	double maxVal = 0;
	string fileName;
	string whereField;
	string currLine;
	string cutLine;
	
	clearTable();
	
	if(s.find("SELECT") != -1 && s.find("MAX") != -1)
	{
		fileName = s.substr(s.find("FROM")+5, s.find(";") - (s.find("FROM") + 5));
		whereField = initS.substr(s.find("(")+1, s.find(")") - (s.find("(") + 1));
	}
	
	ifstream checkFile;
	checkFile.open(fileName);

	getline(checkFile, currLine, '\n');
	totalColumns = count(currLine.begin(), currLine.end(), '|');
	//Check if file is valid
	if(checkFile)
	{
		//Create Table with file data
		while(!checkFile.eof())
		{
			
			for(int i = 0; i <= totalColumns; i++)
			{
				cutLine = currLine.substr(0, currLine.find("|"));
				currLine = currLine.substr(currLine.find("|")+1, currLine.find_last_of(currLine));
				stringTable[lineNum][i] = cutLine;
			}
			lineNum++;
			getline(checkFile, currLine, '\n');
		}
		
		ifstream fin(fileName);    
		for(int j = 0; j <= totalColumns; j++)
		{
			if((stringTable[0][j]).find(whereField) != -1)
			{
			currColumns = j;
			}
		}

		if(s.find("MAX") != -1)
		{
				for(int i = 0; i < lineNum; i++)
				{
					if(i != 0)
					{
						if(maxVal < stoi(stringTable[i][currColumns]))
						{
							maxVal = stoi(stringTable[i][currColumns]);
						}
					}
				}
		}			
		fin.close();  
		checkFile.close(); 
		cout << "MAX(" << whereField << ")" << endl;
		cout << maxVal << endl;    
	}
	//If file is invalid, table does not exist
	else
	{
		cout << "Table does not exist" << endl;
		checkFile.close();
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
					if(s.find("WHERE") != -1 || (s.find("INNER JOIN") != -1 && s.find("ON") != -1))
					{
						innerJoin(s, initS);
					}
					else if(s.find("LEFT OUTER JOIN") != -1)
					{
						leftOuterJoin(s, initS);
					}
					else
					{
						selectFrom(s, initS);
					}
				}
				else
				{
					cout << "Cannot select from tables without using a database" << endl;
				}

		}
		//Call insertInto
		//Can only insert a record into a table if database is in use and table exists
		else if(s.find("INSERT INTO") != -1)
		{
				if(usingDB == 1)
				{
					insertInto(s, initS);
				}
				else
				{
					cout << "Cannot insert into tables without using a database" << endl;
				}

		}
		//Call update
		//Can only update a table record if database is in use and table exists
		else if(s.find("UPDATE") != -1)
		{
				if(usingDB == 1)
				{
					update(s, initS);
				}
				else
				{
					cout << "Cannot update tables without using a database" << endl;
				}

		}
		//Call deleteFrom
		//Can only delete from a table if database is in use and table exists
		else if(s.find("DELETE FROM") != -1)
		{
				if(usingDB == 1)
				{
					deleteFrom(s, initS);
				}
				else
				{
					cout << "Cannot delete from tables without using a database" << endl;
				}

		}
		//Call select
		//Can only select from a table if database is in use
		else if(s.find("SELECT") != -1)
		{
				if(usingDB == 1)
				{
					if(s.find("SELECT") != -1 && s.find("FROM") != -1 && s.find("WHERE") != -1)
					{
					select(s, initS);
					}
					else if(s.find("COUNT(") != -1)
					{
						count(s, initS);
					}
					else if(s.find("AVG(") != -1)
					{
						avg(s, initS);
					}
					else if(s.find("MAX(") != -1)
					{
						max(s, initS);
					}
				}
				else
				{
					cout << "Cannot select from tables without using a database" << endl;
				}

		}
		else if(s.find("BEGIN TRANSACTION") != -1)
		{
			if(usingDB == 1)
			{
				cout << "Transaction starts." << endl;
			}
			else
			{
				cout << "Cannot begin transactions without using a database" << endl;
			}
		}
		else if(s.find("COMMIT") != -1)
		{
			if(usingDB == 1)
			{
				commitTransaction();
			}
			else
			{
				cout << "Cannot commit without using a database" << endl;
			}
		}
	}
	
}


