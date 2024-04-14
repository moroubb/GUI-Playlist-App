#pragma once
#include "Song.h"
#include "SongException.h"
#include <vector>
#include<algorithm>

class Playlist {
public:
	vector<Song*> songs;
	void add(Song& s);
	void clear();
	void remove(Song& s);		
};