#include <iostream>
#include "Multi.h"
using namespace std;

int main() {
	
	int option=-1;
	string Name;
	double Rate;
	int Year;
	MovieList list;
	string filename = "efe";
	
	
	while(option != 99)
	{
		cout << endl;
		cout << " ______________________________" <<endl;
		cout << "| (1)  Add a New Movie         |"<<endl;
		cout << "| (2)  Delete a Movie          |"<<endl;
		cout << "| (3)  Update Rate of a Movie  |"<<endl;	
		cout << "| (4)  Print by Year           |"<<endl;
		cout << "| (5)  Print by Name           |"<<endl;
		cout << "| (6)  Print by Rate           |"<<endl;
		cout << "| (7)  Load a File             |"<<endl;
		cout << "| (8)  Save to File by Year    |"<<endl;
		cout << "| (9)  Save to File by Name    |"<<endl;
		cout << "| (10) Save to File by Rate    |"<<endl;
		cout << "|                              |"<<endl;
		cout << "| (0)  Exit                    |"<<endl;
		cout << "|______________________________|"<<endl;;
		
		cout << endl;
		cout << "Selection: "; 
		
		cin >> option;
		if(option == 0)
		{
			cout << endl;
			cout << "Exitting...";
			option = 99;
		}
		
		
		if(option == 1){
			cout << "Name of the Movie: ";
			cin.ignore(256, '\n');
			getline (cin, Name);
			cout << "Year of the Movie: ";
			cin >> Year;
			cout << "Rate of the Movie: ";
			cin >> Rate;
			cout << endl;
			cout << Name << " Added..."<< endl;
			list.add(Name,Rate,Year);
		}
		
		if(option == 2){
			cout << "Name of the Movie: ";
			cin.ignore(256, '\n');
			getline (cin, Name);
			
			bool a = list.remove(Name);
			if(a==0)
			{
				cout<< "This Movie Does not Exist...";
			}
			else{
				cout << Name << " Deleted..." << endl;;
			}
		}
		
		if(option == 3){
			cout << "Name of the movie: ";
			cin.ignore(256, '\n');
			getline (cin, Name);
			cout << "New rate of the movie: ";
			cin >> Rate;
			try{	
			list.update(Name, Rate);
			cout << Name << " Successfully Updated...";
			}
			catch(const char* msg){
				cerr<< msg << endl;
			}
		}
		
		if(option == 4){
			list.printByYear();
		}
		if(option == 5){
			list.printByName();
		}
		if(option == 6){
			list.printByRate();
		}
		if(option == 7){
			cout << "File Name Without Extension: ";
			cin.ignore(256, '\n');
			getline (cin, filename);
			list.loadFile(filename);
			cout << endl;
			cout << "Loaded...";
			
		}
		if(option == 8){
			cout << "File Name Without Extension: ";
			cin.ignore(256, '\n');
			getline (cin, filename);
			list.saveToFileByYear(filename);
			cout << endl;
			cout << "Saved...";	
		}
		if(option==9){
			cout << "File Name Without Extension: ";
			cin.ignore(256, '\n');
			getline (cin, filename);
			list.saveToFileByName(filename);
			cout << endl;
			cout << "Saved...";
		}
		if(option==10){
			cout << "File Name Without Extensions: ";
			cin.ignore(256, '\n');
			getline (cin, filename);
			list.saveToFileByRate(filename);
			cout << endl;
			cout << "Saved...";
		}
	}
	
	
	return 0;
}
