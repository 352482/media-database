class Movie : Media{
	private:
	char * rating;
	char * director;
	int duration;
	public:
	Movie(char* _title, int _year, char* _rating, char* _director, int _duration) : Media(_title, _year){
		rating = _rating;
		director = _director;
		duration = _duration;
	}
	
	~Movie(){
		delete rating;
		delete director;
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
