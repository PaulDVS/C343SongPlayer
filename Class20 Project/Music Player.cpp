#include<iostream>
#include "musicPlayerClass.h"
#include <map> 
#include <set>
#include <utility>

using namespace std;

musicPlayerClass myPlayer;

void displayMainMenu(){
	cout<<endl;
	cout<<"1: Play"<<endl;
	cout<<"2: Edit"<<endl;
	cout<<"9: Exit"<<endl;
	cout<<"Enter choice:"<<endl;
}

void displayPlayMenu(){
	int ch;
	
	do{
		cout<<endl;
		cout<<"1: Play Playlist"<<endl;
		cout<<"2: Play Specific Song"<<endl;
		cout<<"9: Exit"<<endl;
		cout<<"Enter choice:"<<endl;
		cin>>ch;
		switch(ch){
			case 1:
				myPlayer.playPlayList();
				break;
			case 2:
				myPlayer.playSong();
				break;
			case 9:
				break;
			default:
				cout<<"Invalid input"<<endl;
				break;
		}
		
	}while(ch!=9);
}

void displayEditMenu(){
	int ch;
	
	do{
		cout<<endl;
		cout<<"1: Add Song"<<endl;
		cout<<"2: Edit Song"<<endl;
		cout<<"3: Remove Song"<<endl;
		cout<<"4: Create Playlist"<<endl;
		cout<<"5: Add Song to Playlist"<<endl;
		cout<<"6: Remove Song from Playlist"<<endl;
		cout<<"7: Remove Playlist"<<endl;
		cout<<"9: Exit"<<endl;
		cout<<"Enter choice:"<<endl;
		cin>>ch;
		switch(ch){
			case 1:
				myPlayer.addSong();
				break;
			case 2:
				myPlayer.editSong();
				break;
			case 3:
				myPlayer.removeSong();
				break;
			case 4:
				myPlayer.createPlaylist();
				break;
			case 5:
				myPlayer.addSongToPlaylist();
				break;
			case 6:
				myPlayer.removeSongFromPlaylist();
				break;
			case 7:
				myPlayer.deletePlaylist();
				break;
			case 9:
				break;
			default:
				cout<<"Invalid input"<<endl;
				break;
		}
		
	}while(ch!=9);
	
	
}

int main()
{
	int ch,ch2;
	myPlayer = musicPlayerClass();
	
	do{
		displayMainMenu();
		cin>>ch;
		switch(ch){
			case 1:
				displayPlayMenu();
				break;
			case 2:
				displayEditMenu();
				break;
			case 9:
				break;
			default:
				cout<<"Invalid input"<<endl;
				break;
		}
	}while(ch!=9);
}
