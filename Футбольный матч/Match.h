#pragma once
using namespace std; 
#include <string>
#include <iostream>
struct Match
{
	int OwnerPoints; // очки хозяина
	int OppPoints; //очки соперника
	string match; // счет
	string Name; // команда хозяин
	string Opponent; // команда - соперник
	bool operator !=(const Match& other) {
		return Name != other.Name; 
	}
	bool operator <(const Match& other) {
		return Name < other.Name;
	}
};

