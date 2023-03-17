#include<iostream>
#include<string>

using namespace std;

class songClass{
	private:
		string songName;
		string songartist;
		int songYear;
		string songDesc;
		double songPlaytime;
		
	public:
		songClass();
		songClass(string name, string artist, int year, string desc, double playtime);
		
		string getSongName();
		string getSongartist();
		int getSongYear();
		string getSongDesc();
		double getSongPlaytime();
		
		void printSongShort();
		void printSong();
	
};

songClass::songClass(){
	return;
}

songClass::songClass(string name, string artist, int year, string desc, double playtime){
	songName = name;
	songartist = artist;
	songYear = year;
	songDesc = desc;
	songPlaytime = playtime;
}
		
string songClass::getSongName(){
	return songName;
}

string songClass::getSongartist(){
	return songartist;
}

int songClass::getSongYear(){
	return songYear;
}

string songClass::getSongDesc(){
	return songDesc;
}

double songClass::getSongPlaytime(){
	return songPlaytime;
}

void songClass::printSongShort(){
	cout << songName <<" (" << songYear << ") by " << songartist << " Runtime: " << songPlaytime << endl;
}

void songClass::printSong(){
	cout<<songName<<" ("<< songYear <<") by "<< songartist <<" Runtime: "<<songPlaytime<< endl;
	cout<<"\t"<<songDesc<<endl;
}

