#include <iostream>
#include <ctype.h>
#include <vector>
#include "media.h"
#include "game.h"
#include "music.h"
#include "movie.h"

using namespace std;

int main(){
	vector<Media*> media_vector;
	char input_buffer[100];
	while (true){
		input_buffer[0] = '\0';
		cout << "Enter command: ";
		cin >> input_buffer;
		int i=0;
		for (i=0;i<strlen(input_buffer);i++){
			input_buffer[i] = toupper(input_buffer[i]);
		}
		if (strcmp("ADD",input_buffer)==0){
			char media_type[20];
			bool invalid_input = true;
			cout << "What type of media? (GAME, MUSIC, or MOVIE): ";
			cin >> media_type;
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
			char title_buf[100];
			cin >> title_buf;
			cout << "Enter year: ";
			int year;
			while (!(cin >> year)){
				cout << "Invalid input. Enter an integer: ";
				cin.clear();
				cin.ignore(100,'\n');
			}
			if (strcmp("GAME",media_type)==0){
				cout << "Enter rating: ";
				char rating_buf[20];
				cin >> rating_buf;
				cout << "Enter publisher: ";
				char publisher_buf[20];
				cin >> publisher_buf;
				Game *new_game = new Game(title_buf, year, rating_buf, publisher_buf);
				media_vector.push_back((Media*)new_game);
				cout << "Game added." << endl;
			}else if (strcmp("MUSIC",media_type)==0){
				cout << "Enter duration: ";
				int duration;
				while (!(cin >> duration)){
					cout << "Invalid input. Enter an integer: ";
					cin.clear();
					cin.ignore(100,'\n');
				}
				cout << "Enter artist: ";
				char artist_buf[20];
				cin >> artist_buf;
				cout << "Enter publisher: ";
				char publisher_buf[20];
				cin >> publisher_buf;
				Music *new_song = new Music(title_buf, year, duration, artist_buf, publisher_buf);
				media_vector.push_back((Media*)new_song);
				cout << "Song added." << endl;
			}else if (strcmp("MOVIE",media_type)==0){
				cout << "Enter duration: ";
				int duration;
				while (!(cin >> duration)){
					cout << "Invalid input. Enter an integer: ";
					cin.clear();
					cin.ignore(100,'\n');
				}
				cout << "Enter director: ";
				char director_buf[20];
				cin >> director_buf;
				cout << "Enter rating: ";
				char rating_buf[20];
				cin >> rating_buf;
				Movie *new_movie = new Movie(title_buf, year, rating_buf, director_buf, duration);
				media_vector.push_back((Media*)new_movie);
				cout << "Movie added." << endl;
			}
		}else{
			cout << "Unknown command. Use HELP for a list of commands." << endl;
		}
	}
	return 0;
}
