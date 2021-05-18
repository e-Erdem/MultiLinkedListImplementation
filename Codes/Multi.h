#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class Movie{
	public:
		Movie(string name1, int year1, double rate1){
			name = name1;
			year = year1;
			rate = rate1;	
		}
		string name;
		int year;
		double rate;
};


class MovieNode {
public:
    MovieNode() {
        nextname = 0;
    	nextyear = 0;
    	nextrate = 0;
	}
	
	MovieNode(Movie movie, int year ,MovieNode *yearptr = 0){
		yearinfo = movie.year;
		nameinfo = movie.name;
		rateinfo = movie.rate;
		nextyear = yearptr;
	}
	MovieNode(Movie movie,double rate ,MovieNode *rateptr = 0){
		yearinfo = movie.year;
		nameinfo = movie.name;
		rateinfo = movie.rate;
		nextrate = rateptr;
	}
	MovieNode(Movie movie,string name ,MovieNode *nameptr = 0){
		yearinfo = movie.year;
		nameinfo = movie.name;
		rateinfo = movie.rate;
		nextname = nameptr;
	}
    
    int yearinfo;
    double rateinfo;
    string nameinfo;
    MovieNode *nextyear;
    MovieNode *nextname;
    MovieNode *nextrate;
};

class MovieList {
public:
	MovieList() {
    yearhead = yeartail = 0;
    namehead = nametail = 0;
    ratehead = ratetail = 0;
	size = 0;
    }
    ~MovieList();
    int isEmpty() {
        return ratehead == 0;
    }
    void SortByYear(int year, Movie movie);
    void SortByRate(double rate, Movie movie);
    void SortByName(string name, Movie movie);
    
	void printByYear();
	void printByRate();
	void printByName();
	void add(string name, double rate, int year);
	bool rem1(string name);
	bool rem2(string name); 
	bool rem3(string name);
	bool remove(string name);
	void update(string name, double rate);
	void loadFile(string name);
	void saveToFileByYear(string filename);
	void saveToFileByName(string filename);
	void saveToFileByRate(string filename);
	
	private:
    MovieNode *yearhead, *yeartail;
    MovieNode *ratehead, *ratetail;
    MovieNode *namehead, *nametail;
	int size;
};
