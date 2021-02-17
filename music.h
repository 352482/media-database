#include <iostream>

using namespace std;

class Music : Media{
	private:
	char * artist;
	char * publisher;
	int duration;
	public:
	Music(char* _title, int _year, int _duration, char* _artist, char* _publisher) : Media(_title, _year){
		artist = _artist;
		publisher = _publisher;
		duration = _duration;
	}
	
	~Music(){
		delete artist;
		delete publisher;
	}

	void print(){
		cout << "----SONG----" << endl;
		cout << "Title: " << title << endl;
		cout << "Year: " << year << endl;
		cout << "Artist: " << artist << endl;
		cout << "Publisher: " << publisher << endl;
		cout << "Duration: " << duration << endl;
	}

	char * getArtist(){
		return artist;
	}

	void setArtist(char* new_artist){
		artist = new_artist;
	}

	char * getPublisher(){
		return publisher;
	}

	void setPublisher(char* new_publisher){
		publisher = new_publisher;
	}

	int getDuration(){
		return duration;
	}

	void setDuration(int new_duration){
		duration = new_duration;
	}
};
