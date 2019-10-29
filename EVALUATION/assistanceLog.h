/*!
 * @author Luis Adolfo Ramírez
 * @email donlarry.timoteo@gmail.com
 * @brief A program that makes assistance logs
*/

#ifndef UnoHaceCosasAsiCuandoEstaAburrido
#define UnoHaceCosasAsiCuandoEstaAburrido

/**
 * Are u reading this? xd
 * Don't waste your time!
*/

#include <bits/stdc++.h>
using namespace std;

#define fileName "ASSISTANCES.csv"
#define endl "\n"

int lastDay;

void chargeLastDay(void);
void createLog(int);
int fluxToInt(const char*);
void _MAIN_(int, char**);

void _MAIN_(int argc, char const *argv[]) {
	chargeLastDay();
	if (argc == 1)
		return createLog(lastDay);
	if (argc == 2) {
		if ("all"s.compare(argv[1]))
			return createLog(fluxToInt(argv[1]));
		for (int i = 1; i <= lastDay; ++i)
			createLog(i);
	}
}

void chargeLastDay(void) {
	ifstream in(fileName);
	if (!in.good()) {
		in.close();
		exit(1);
	}
	string s;
	getline(in,s);
	getline(in,s);
	stringstream line_ss(s);
	getline(line_ss,s,';');
	getline(line_ss,s,';');
	getline(line_ss,s,';');
	int c=0;
	while(!line_ss.eof()){
		getline(line_ss,s,';');
		++c;
	}
	lastDay=c;
	in.close();
}

void createLog(int day) {
	// 0 < day <= lastDay
	assert(day>0);
	assert(day<=lastDay);

	ifstream file(fileName);
	if (!file.good()) {
		file.close();
		exit(1);
	}

	string sDay = to_string(day);
	string logFileName = "day"+string(2-sDay.size(),'0')+sDay+".txt";
	ofstream log(logFileName);
	if (!log.good()) {
		log.close();
		exit(1);
	}

	string line, n, id, fullName;
	int Assistances=0;

	getline(file,line);
	getline(file,line);
	while(!file.eof()) {
		stringstream line_ss(line);
		getline(line_ss,n,';');
		getline(line_ss,id,';');
		getline(line_ss,fullName,';');
		
		string assistence;
		for (int i = 1; i<day && !line_ss.eof(); ++i)
			getline(line_ss,assistence,';');
		getline(line_ss,assistence,';');

		if (find(assistence.begin(), assistence.end(), 'X')!=assistence.end()) {
			++Assistances;
			log << n << string(2-n.size(),' ') << id << " " << fullName << endl;
		}
		getline(file,line);
	}
	log << "Assistances: " << Assistances << endl;
	file.close();
	log.close();
}

int fluxToInt(const char* flux) {
	int day=0,c=0;
	do {
		day*=10;
		auto digit = flux[c]-'0';
		assert(digit>=0 && digit<=9);
		day+=digit;
	} while(flux[++c]!='\0');
	return day;
}

#endif//UnoHaceCosasAsiCuandoEstaAburrido