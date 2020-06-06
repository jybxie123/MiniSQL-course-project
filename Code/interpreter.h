#pragma once

#include "pch.h"
#include "catalog.h"

typedef enum {
	CREATE_TABLE = 0,
	DROP_TABLE,
	CREATE_INDEX,
	DROP_INDEX,
	SELECT,
	INSERT,
	DELETE,
	QUIT,
	EXECFILE,
	EMPTY
}operation_type; // sql operation type

typedef enum {
	READING = 0,
	FINISH,
	ERROR
}user_status; // user input status

struct Where_clause {
	string attr;
	string value;
	string operation;
};

struct DB_exception {
	int code;
	string title;
	string msg;
};

class Interpreter {
public:

	user_status status;
	operation_type operation;
	table_info table;
	vector<Where_clause> w_clouse;
	clock_t start, finish;
	DB_exception error;

	void read_operation(); // read sql sentense

	void log_status(clock_t start, clock_t finish);

	void set_error(int code);

	Interpreter();

	~Interpreter();

};