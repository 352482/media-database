class Media{
	private:
	char * title;
	int year;
	public:
	Media(char* _title,int _year){
		title = _title;
		year = _year;
	}

	~Media(){
		delete title;
	}

	char * getTitle(){
		return title;
	}

	void setTitle(char * new_title){
		title = new_title;
	}

	int getYear(){
		return year;
	}
	
	void setYear(int new_year){
		year = new_year;
	}
};
