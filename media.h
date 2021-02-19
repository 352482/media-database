class Media{
	protected:
	char * title;
	int year;
	public:
	Media(char* _title,int _year){
		title = _title;
		year = _year;
	}

	//delete the char array allocated to the title
	~Media(){
		delete title;
	}

	//make the print() function virtual so
	//that derive classes can print their information
	virtual void print(){}

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
