//+++++++++++
//Media database - A program that stores information about different forms of media
//Andrew Hett
//2-18-2021
//------

#include <iostream>
#include <ctype.h>
#include <vector>
#include "media.h"
#include "game.h"
#include "music.h"
#include "movie.h"

using namespace std;

int main(){
	vector<Media*> *media_vector = new vector<Media*>;
	char input_buffer[100];
	while (true){
		input_buffer[0] = '\0';
		cout << "Enter command: ";
		cin >> input_buffer;
		//convert the user's input to uppercase
		//for easier command checking
		int i=0;
		for (i=0;i<strlen(input_buffer);i++){
			input_buffer[i] = toupper(input_buffer[i]);
		}
		if (strcmp("ADD",input_buffer)==0){
			char media_type[50];
			bool invalid_input = true;
			cout << "What type of media? (GAME, MUSIC, or MOVIE): ";
			cin >> media_type;
			//keep getting the user's input until
			//they enter a valid input
			while (invalid_input){
				for (int i=0;i<strlen(media_type);i++){
					media_type[i] = toupper(media_type[i]);
				}
				if (strcmp(media_type,"GAME")==0
					|| strcmp(media_type,"MUSIC")==0
					|| strcmp(media_type,"MOVIE")==0){
					invalid_input = false;
				}else{
					cout << "Invalid input. Enter GAME, MUSIC, or MOVIE: ";
					cin >> media_type;
				}
			}
			cout << "Enter title: ";
			cin.clear(); cin.ignore();
			char title_buf[100];
			cin.getline(title_buf,100);
			cout << "Enter year: ";
			int year;
			//keep getting the user's input until
			//they enter an integer
			while (!(cin >> year)){
				cout << "Invalid input. Enter an integer: ";
				cin.clear();
				cin.ignore(100,'\n');
			}
			if (strcmp("GAME",media_type)==0){
				cout << "Enter rating: ";
				cin.clear(); cin.ignore();
				char rating_buf[50];
				cin.getline(rating_buf,50);
				cout << "Enter publisher: ";
				cin.clear(); cin.sync();
				char publisher_buf[50];
				cin.get(publisher_buf,50);
				//instantiate a new Game object and
				//cast it to Media in order to push it to the vector
				Game *new_game = new Game(title_buf, year, publisher_buf, rating_buf);
				media_vector->push_back((Media*)new_game);
				cout << "Game added." << endl;
			}else if (strcmp("MUSIC",media_type)==0){
				cout << "Enter duration: ";
				int duration;
				//keep getting the user's input until
				//they enter an integer
				while (!(cin >> duration)){
					cout << "Invalid input. Enter an integer: ";
					cin.clear();
					cin.ignore(100,'\n');
				}
				cout << "Enter artist: ";
				cin.clear(); cin.ignore();
				char artist_buf[50];
				cin.getline(artist_buf,50);
				cout << "Enter publisher: ";
				cin.clear(); cin.sync();
				char publisher_buf[50];
				cin.get(publisher_buf,50);
				//instantiate a new Music object and
				//cast it to Media in order to push it to the vector
				Music *new_song = new Music(title_buf, year, duration, artist_buf, publisher_buf);
				media_vector->push_back((Media*)new_song);
				cout << "Song added." << endl;
			}else if (strcmp("MOVIE",media_type)==0){
				cout << "Enter duration: ";
				int duration;
				//keep getting the user's input until
				//they enter an integer
				while (!(cin >> duration)){
					cout << "Invalid input. Enter an integer: ";
					cin.clear();
					cin.ignore(100,'\n');
				}
				cout << "Enter director: ";
				cin.clear(); cin.ignore();
				char director_buf[50];
				cin.getline(director_buf,50);
				cout << "Enter rating: ";
				cin.clear(); cin.sync();
				char rating_buf[50];
				cin.get(rating_buf,50);
				//instantiate a new Movie object and
				//cast it to Media in order to push it to the vector
				Movie *new_movie = new Movie(title_buf, year, rating_buf, director_buf, duration);
				media_vector->push_back((Media*)new_movie);
				cout << "Movie added." << endl;
			}
		}else if(strcmp("SEARCH",input_buffer)==0){
			cout << "Enter title or year of release: ";
			cin.clear(); cin.ignore();
			char title_buffer[50];
			cin.getline(title_buffer,50);
			bool search_complete = false;
			//iterate through all the Media objects in the vector
			for (vector<Media*>::iterator it = media_vector->begin(); it != media_vector->end(); ++it){
				Media* generic_media = *it;
				char year_buf[10];
				sprintf(year_buf,"%d",generic_media->getYear());
				if (strcmp(title_buffer,generic_media->getTitle())==0
					|| strcmp(title_buffer,year_buf)==0){
					//call the virtual print() function
					//of the generic Media object
					generic_media->print();
					search_complete = true;
				}
			}
			if (!search_complete){
				cout << "No media found with that title." << endl;
			}
		}else if(strcmp("DELETE",input_buffer)==0){
			cout << "Enter title or year of release: ";
			cin.clear(); cin.ignore();
			char title_buffer[50];
			cin.getline(title_buffer,50);
			bool search_complete = false;
			vector<Media*> match_vector;
			//iterate through all of the Media objects in the vector
			for (vector<Media*>::iterator it = media_vector->begin(); it != media_vector->end(); ++it){
				Media* generic_media = *it;
				char year_buf[10];
				sprintf(year_buf,"%d",generic_media->getYear());
				//if the title of the current Media object matches the
				//query, call print() and ask the user if they would like
				//to delete it
				if (strcmp(title_buffer,generic_media->getTitle())==0
					|| strcmp(title_buffer,year_buf)==0){
					if (!search_complete){
						cout << "--MATCHING-MEDIA--" << endl;
					}
					generic_media->print();
					search_complete = true;
					char erase_input_buf[10];
					erase_input_buf[0]='\0';
					while (strcmp("y",erase_input_buf)!=0 && strcmp("n",erase_input_buf)!=0){
						cout << "Delete? (y/n): " << endl;
						cin >> erase_input_buf;
					}
					if (strcmp("y",erase_input_buf)==0){
						media_vector->erase(it);
						--it;
					}
				}
			}
			//if the user's input doesn't match any of
			//the commands, tell them so
			if (!search_complete){
				cout << "No media found with that title." << endl;
			}
		}else if(strcmp("QUIT",input_buffer)==0){
			break;
		}else if(strcmp("HELP",input_buffer)==0){
			cout << "HELP: Display this message" << endl;
			cout << "ADD: Add new media to the database" << endl;
			cout << "SEARCH: Search for media in the database" << endl;
			cout << "DELETE: Delete specific media from the database" << endl;
			cout << "QUIT: Quit the program" << endl;
		}else{
			cout << "Unknown command. Use HELP for a list of commands." << endl;
		}
	}
	delete media_vector;
	return 0;
}
