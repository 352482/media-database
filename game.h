class Game : Media{
	private:
	char * publisher;
	char * rating;
	public:
	Game(char* _title, int _year, char* _publisher, char* _rating) : Media(_title, _year){
		publisher = _publisher;
		rating = _rating;
	}
	
	~Game(){
		delete publisher;
		delete rating;
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
