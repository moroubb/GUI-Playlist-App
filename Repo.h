#pragma once
#include "Song.h"
#include "SongException.h"


class SongRepo {
public:
	vector<Song> songs;
	void store(const Song& s);
	void remove(const Song& s);
	const Song&find(string t, string a);
	const std::vector<Song>& getAllSongs() const;
}; 