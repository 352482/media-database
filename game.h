#include <iostream>

using namespace std;

//derive Game from Media
class Game : Media{
	private:
	char * publisher;
	char * rating;
	public:
	//call the Media constructor with the Game constructor
	Game(char* _title, int _year, char* _publisher, char* _rating) : Media(_title, _year){
		publisher = _publisher;
		rating = _rating;
	}

	//delete the allocated char arrays
	~Game(){
		delete publisher;
		delete rating;
	}

	//override Media's virtual print function
	void print(){
		cout << "----GAME----" << endl;
		cout << "Title: " << title << endl;
		cout << "Year: " << year << endl;
		cout << "Rating: " << rating << endl;
		cout << "Publisher: " << publisher << endl;
	}

	char * getPublisher(){
		return publisher;
	}

	void setPublisher(char* new_publisher){
		publisher = new_publisher;
	}

	char * getRating(){
		return rating;
	}

	void setRating(char* new_rating){
		rating = new_rating;
	}
};
