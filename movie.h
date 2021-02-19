#include <iostream>

using namespace std;

//derive Movie from Media
class Movie : Media{
	private:
	char * rating;
	char * director;
	int duration;
	public:
	//call the Media constructor with the Movie constructor
	Movie(char* _title, int _year, char* _rating, char* _director, int _duration) : Media(_title, _year){
		rating = _rating;
		director = _director;
		duration = _duration;
	}
	
	//delete the allocated char arrays
	~Movie(){
		delete rating;
		delete director;
	}

	//override Media's virtual print function
	void print(){
		cout << "----MOVIE----" << endl;
		cout << "Title: " << title << endl;
		cout << "Year: " << year << endl;
		cout << "Rating: " << rating << endl;
		cout << "Director: " << director << endl;
		cout << "Duration: " << duration << endl;
	}

	char * getRating(){
		return rating;
	}

	void setRating(char* new_rating){
		rating = new_rating;
	}

	char * getDirector(){
		return director;
	}

	void setDirector(char* new_director){
		rating = new_director;
	}

	int getDuration(){
		return duration;
	}

	void setDuration(int new_duration){
		duration = new_duration;
	}
};
