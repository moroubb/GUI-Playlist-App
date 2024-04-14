#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>   
#include <sstream>

using namespace std;


class Song {
private:
	vector<string> lyrics;
	vector<string> parseLyrics(string lyrics);
protected:
	string artist;
	string title;
	int year;
	string url;

public:
	Song() = default;
	Song(string a, string t, string l, string u, int y);

	string getArtist() const;
	string getLyrics() const;
	string getTitle() const;
	string getUrl() const;
	int getNrWords() const;
	int getYear() const;

	friend ostream& operator<<(ostream& os, const Song& s);

};