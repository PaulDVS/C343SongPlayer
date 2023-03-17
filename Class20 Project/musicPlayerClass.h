#include<iostream>
#include<vector>
#include<string>
#include <map> 
#include <set>
#include <utility>

#include "songClass.h"

using namespace std;

class musicPlayerClass{
	private:
		map<int, songClass> songList; //ID and song
		int songs;
		map<string, set<int> > playLists; //Playlist name and playlist (vector of song IDs)

	public:
		musicPlayerClass();
		void playPlayList();
		void playSong();
		
		void addSong();
		void editSong();
		void removeSong();
		void createPlaylist();
		void addSongToPlaylist();
		void removeSongFromPlaylist();
		void deletePlaylist();
		
		void printPlayListNames();
		void printPlayList(string name);
		void printAllSongs();
};


musicPlayerClass::musicPlayerClass(){
	songs=0;
}

void musicPlayerClass::playPlayList(){
	string name;
	songClass current;
	set<int> playList;
	printPlayListNames();
	cout<<endl;
	cout<<"Please enter the name of the playlist to play:"<<endl;
	cin>>name;
	
	if(playLists.count(name) == 1){
		playList  = playLists.at(name);
		cout<<endl;
		cout<<"Playing songs in playlist "<<name<<endl;
		
		for(int id : playList){
			cout<<endl;
			current = songList.at(id);
			cout<<"Now playing: ID: "<<id<<" ";
			current.printSongShort();
		}
	}
	else{
		cout<<endl;
		cout<<"Playlist "<<name<<" doesn't exist."<<endl;
	}
}

void musicPlayerClass::playSong(){
	int id;
	songClass song;
	
	printAllSongs();
	cout<<endl;
	cout<<"Please enter the id of the song to play:"<<endl;
	cin>>id;
	
	if(songList.count(id) == 1){
		song = songList.at(id);
		cout<<endl;
		cout<<"Now playing: ID: "<<id<<" ";
		song.printSongShort();
	}
	else{
		cout<<endl;
		cout<<"Song with id "<<id<<" doesn't exist."<<endl;
	}
	
}


void musicPlayerClass::addSong(){
	string name;
	string artist;
	int year;
	string desc;
	double playtime;
	
	cout<<endl;
	cout<<"Please enter song name:"<<endl;
	cin>>name;
	cout<<"Please enter song artist:"<<endl;
	cin>>artist;
	cout<<"Please enter song release year:"<<endl;
	cin>>year;
	cout<<"Please enter song description:"<<endl;
	cin>>desc;
	cout<<"Please enter song playtime:"<<endl;
	cin>>playtime;
	
	songClass newSong(name, artist, year, desc, playtime);
	
	songList.emplace(++songs, newSong);
	cout<<"Song added wth ID "<<songs<<endl;
}

void musicPlayerClass::editSong(){
	int id;
	
	string name;
	string artist;
	int year;
	string desc;
	double playtime;
	
	printAllSongs();
	cout<<endl;
	cout<<"Please enter the id of the song to update:"<<endl;
	cin>>id;
	
	if(songList.count(id) == 1){
		songList.at(id).printSong();
		
		cout<<endl;
		cout<<"Please enter song name:"<<endl;
		cin>>name;
		cout<<"Please enter song artist:"<<endl;
		cin>>artist;
		cout<<"Please enter song release year:"<<endl;
		cin>>year;
		cout<<"Please enter song description:"<<endl;
		cin>>desc;
		cout<<"Please enter song playtime:"<<endl;
		cin>>playtime;
		cout<<"Song updated"<<endl;
		songClass newSong(name, artist, year, desc, playtime);
		songList.at(id) = newSong;
	}
	else{
		cout<<endl;
		cout<<"Song with id "<<id<<" doesn't exist."<<endl;
	}
}

void musicPlayerClass::removeSong(){
	int id;
	
	printAllSongs();
	cout<<endl;
	cout<<"Please enter the id of the song to remove:"<<endl;
	cin>>id;
	
	if(songList.count(id) == 1){
		songList.erase(id);
		cout<<"Song with ID: " << id <<" has been removed."<<endl;
		for(auto& playList : playLists){
			if(playList.second.count(id) == 1){
				playList.second.erase(id);
			}
		}
	}
	else{
		cout<<endl;
		cout<<"Song with id "<<id<<" doesn't exist."<<endl;
	}
}

void musicPlayerClass::createPlaylist(){
	string name;
	
	cout<<endl;
	cout<<"Please enter the name of the playlist:"<<endl;
	cin>>name;
	
	
	if(playLists.count(name) == 0){
		set<int> newSet;
		playLists.emplace(name, newSet );
	}
	else{
		cout<<endl;
		cout<<"Playlist "<<name<<" already exist."<<endl;
	}
}

void musicPlayerClass::addSongToPlaylist(){
	string name;
	int id;
	
	cout<<endl;
	cout<<"Please enter the name of the playlist to add a song to:"<<endl;
	cin>>name;
	
	if(playLists.count(name) == 1){
		cout<<endl;
		cout<<"Please enter the id of the song to add:"<<endl;
		cin>>id;
		if(songList.count(id) == 1){
			playLists.at(name).insert(id);
			cout<<"Song with id "<<id<<" added to playlist "<<name<<endl;
		}
		else{
			cout<<endl;
			cout<<"Song with id "<<id<<" doesn't exist."<<endl;
		}
	}
	else{
		cout<<endl;
		cout<<"Playlist "<<name<<" doesn't exist."<<endl;
	}
}

void musicPlayerClass::removeSongFromPlaylist(){
	string name;
	int id, currID;
	songClass current;
	
	cout<<endl;
	cout<<"Please enter the name of the playlist to remove a song from:"<<endl;
	cin>>name;
	
	if(playLists.count(name) == 1){
		printPlayList(name);
		cout<<endl;
		cout<<"Please enter the id of the song to remove:"<<endl;
		cin>>id;
		
		if(playLists.at(name).count(id) == 1){
			playLists.at(name).erase(id);
			cout<<"Song with id "<<id<<" removed from playlist "<<name<<endl;
		}
		else{
			cout<<endl;
			cout<<"Song with id "<<id<<" not in playlist."<<endl;
		}
		
	}
	else{
		cout<<endl;
		cout<<"Playlist "<<name<<" doesn't exist."<<endl;
	}
}

void musicPlayerClass::deletePlaylist(){
	string name;
	cout<<endl;
	cout<<"Please enter the name of the playlist to erase:"<<endl;
	cin>>name;
	
	if(playLists.count(name) == 1){
		playLists.erase(name);
		cout<<endl;
		cout<<"Playlist "<<name<<" has been erased."<<endl;
	}
	else{
		cout<<endl;
		cout<<"Playlist "<<name<<" doesn't exist."<<endl;
	}
}


void musicPlayerClass::printPlayListNames(){
	cout<<endl;
	cout<<"All playlists"<<endl;
	cout<<endl;
	for(pair<string, set<int> > playList : playLists){
		cout<<"Playlist: "<<playList.first<<" Songs: "<<playList.second.size()<<endl;
	}
}

void musicPlayerClass::printPlayList(string name){
	songClass current;
	set<int> playList  = playLists.at(name);
	
	cout<<endl;
	cout<<"All songs in playlist "<<name<<endl;
	for(int id : playList){
		cout<<endl;
		current = songList.at(id);
		cout<<"ID: "<<id<<" ";
		current.printSong();
	}
}

void musicPlayerClass::printAllSongs(){
	cout<<endl;
	cout<<"All songs in system"<<endl;
	for(pair<int, songClass> song : songList){
		cout<<endl;
		cout<<"ID: "<<song.first<<" ";
		song.second.printSong();
	}
}



