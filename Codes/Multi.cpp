#include "Multi.h"

MovieList::~MovieList() {
}

void MovieList::SortByYear(int year, Movie movie){
	MovieNode *cur = yearhead;
	if(yearhead == 0 || yearhead->yearinfo >= year)
	{
		 yearhead = new MovieNode(movie, year, yearhead);
		if(yeartail == 0)
		{
			yeartail=yearhead;
		}
	}
	else {
		cur = yearhead;
		while(cur->nextyear != 0 && cur->nextyear->yearinfo < year)
		{
			cur = cur->nextyear;
		}
		
		cur->nextyear = new MovieNode(movie, year, cur->nextyear);
	}
}
void MovieList::SortByRate(double rate, Movie movie){
	MovieNode *cur = ratehead;
	if(ratehead == 0 || ratehead->rateinfo >= rate)
	{
		ratehead = new MovieNode(movie, rate, ratehead);
		if(ratetail == 0)
		{
			ratetail=ratehead;
		}
	}
	else {
		cur = ratehead;
		while(cur->nextrate != 0 && cur->nextrate->rateinfo < rate)
		{
			cur = cur->nextrate;
		}
		
		cur->nextrate = new MovieNode(movie, rate, cur->nextrate);
	}
}
void MovieList::SortByName(string name, Movie movie){
	
		if(namehead == 0 || namehead->nameinfo >= name)
	{
		namehead = new MovieNode(movie, name, namehead);
		if(nametail == 0)
		{
			nametail=namehead;
		}
	}
	else {
		MovieNode *cur = namehead;
		while(cur->nextname != 0 && cur->nextname->nameinfo < name)
		{
			cur = cur->nextname;
		}
		
		cur->nextname = new MovieNode(movie, name, cur->nextname);
	}
}
	

void MovieList::add(string name, double rate, int year){
 Movie myMovie(name, year, rate);
 SortByYear(year, myMovie);
 SortByName(name, myMovie);
 SortByRate(rate, myMovie);
}
	

bool MovieList::rem1(string name){
	
	MovieNode* tmp  = namehead;
	MovieNode* prev = 0;	
	if(tmp!=0 && tmp->nameinfo == name)
	{
		namehead = tmp->nextname;
		delete tmp;
		return true;
	}
	else
	{
		while(tmp!=0 && tmp->nameinfo != name)
		{
			prev = tmp;
			tmp = tmp->nextname;
		}
		if(tmp==0)
		return false;
			prev->nextname = tmp->nextname;
			delete tmp;
		
		
	}  
}

bool MovieList::rem2(string name){
	MovieNode* tmp = yearhead;
	MovieNode* prev;
	if(tmp!=0 && tmp->nameinfo == name)
	{
		yearhead = tmp->nextyear;
		delete tmp;
		return true;
	}
	else{
		while(tmp!=0 && tmp->nameinfo != name)
		{
			prev = tmp;
			tmp = tmp->nextyear;
		}
		if(tmp==0)
		return false;
			prev->nextyear = tmp->nextyear;
			delete tmp;
		
		
	}  
}	
bool MovieList::rem3(string name) {
	
 	MovieNode* tmp = ratehead;
	MovieNode* prev;
	if(tmp!=0 && tmp->nameinfo == name)
	{
		ratehead = tmp->nextrate;
		delete tmp;
		return true;
	}
	else{
		while(tmp!=0 && tmp->nameinfo != name)
		{
			prev = tmp;
			tmp = tmp->nextrate;
		}
		if(tmp==0)
		return false;
			prev->nextrate = tmp->nextrate;
			delete tmp;
		
		
	}  
         
}

bool MovieList::remove(string name){
	
	bool a1 = rem1(name);
	bool a2 = rem2(name);
	bool a3 = rem3(name);
	return a1; //1 return is enough since if the name exists it exists in all lists.
}

void MovieList::update(string name, double rate){
	MovieNode* tmp = namehead;
	int flag=1;
	while(tmp!=0)
	{
		if(tmp->nameinfo==name)
		{
			flag=0;
			break;
		}
		tmp=tmp->nextname;
	}
	if(flag == 1)
	{
		throw "This is not a valid name...";
	}
	int year = tmp->yearinfo;
	
	rem1(name);
	rem2(name);
	rem3(name);

	add(name, rate, year);	
}

int filesizer(string filename){
	ifstream kk;
	string line;
	int j=0;
	
	kk.open(filename);
	while(getline(kk,line,'\n')){
		 j= j+1;
	}
	kk.close();
	return j;
}

void MovieList::loadFile(string filename){
	ifstream myfile;
	string line1,line2;
	int linecount =0;
	int j = 0;
	int i =0;
	int b = 0;
	int d = 0;
	string name = filename +".txt";
	myfile.open(name);

	linecount = filesizer(name);
	string ary[linecount];
	
	cout << linecount;
	while (std::getline(myfile, line1, '\n')) {
  		ary[i] = line1;
  		
		i++;
	}
for(int k=0; k<linecount; ++k){
	
	string::size_type a = ary[k].find('"');
	for(j=1; j<2 && a!=string::npos; j++){
		a=ary[k].find('"',a+1);
	}
	if(j==2)
		b = a;	
	string n = ary[k].substr(1,b-1);
	string data = ary[k].substr(b+2,ary[k].size()); 
	
	string::size_type c = data.find(" ");
		d = c;
		
	string r = data.substr(0,c);
	string y = data.substr(c+1,4);
	
	int year = stoi(y);
	string name = n;
	double rate = stod(r);
	add(name,rate,year);

}
	
}

void MovieList::saveToFileByYear(string filename){
	
	ofstream myfile;
	string name = filename +".txt";
	myfile.open(name);
	
	for(MovieNode* temp=yearhead; temp!=0; temp=temp->nextyear)
	{
		myfile << '"'<< temp->nameinfo << '"';  
		myfile <<" "<<temp->rateinfo;
		myfile  << " "<<temp->yearinfo << endl;
		
	}		
	
	myfile.close();	
}

void MovieList::saveToFileByRate(string filename){
	
	ofstream myfile;
	string name = filename +".txt";
	myfile.open(name);
	
	for(MovieNode* temp=ratehead; temp!=0; temp=temp->nextrate)
	{
		myfile << '"'<< temp->nameinfo << '"';  
		myfile <<" "<<temp->rateinfo;
		myfile  << " "<<temp->yearinfo << endl;
		
	}		
	
	myfile.close();	
	
	
} 

void MovieList::saveToFileByName(string filename){
	
	ofstream myfile;
	string name = filename +".txt";
	myfile.open(name);
	
	for(MovieNode* temp=namehead; temp!=0; temp=temp->nextname)
	{
		myfile << '"'<< temp->nameinfo << '"';  
		myfile <<" "<<temp->rateinfo;
		myfile  << " "<<temp->yearinfo << endl;
		
	}		
	
	myfile.close();	
	
	
} 

void MovieList::printByYear(){
	int count = 0;
	cout << "               ";
	cout << "*******************************************************" << endl;
	cout << "                                   ";
	cout << "Print by Year" << endl;
	cout << "                                   ";
	cout << "-------------" << endl;
	for(MovieNode* temp=yearhead; temp!=0; temp=temp->nextyear)
	{
		count=count+1;
		cout << "   " << "["<<count<<"]" << " ";
		cout << temp->yearinfo << " "; 
		cout << temp->nameinfo << " ";
		cout  << temp->rateinfo << endl;
		
	}		
	
}

void MovieList::printByName(){
	int count = 0;
		cout << "               ";
		cout << "*******************************************************" << endl;
		cout << "                                   ";
		cout<< "Print by Name" << endl;
		cout << "                                   ";
		cout << "-------------" << endl;
	for(MovieNode* temp=namehead; temp!=0; temp=temp->nextname)
	{
		count=count+1;
		cout << "   " << "["<<count<<"]" << " ";
		cout << temp->yearinfo << " "; 
		cout << temp->nameinfo << " ";
		cout  << temp->rateinfo << endl;
	}
	
}

void MovieList::printByRate(){
	int count=0;
		 cout << "               ";
		cout << "*******************************************************" << endl;
		cout << "                                   ";
		cout << "Print by Rate" << endl;
		cout << "                                   ";
		cout << "-------------" << endl;
	for(MovieNode* temp=ratehead; temp!=0; temp=temp->nextrate)
	{
		count=count+1;
		cout << "   " << "["<<count<<"]" << " ";
		cout << temp->yearinfo << " ";
		cout << temp->nameinfo << " ";
		cout  << temp->rateinfo << endl;
	}
	
}


