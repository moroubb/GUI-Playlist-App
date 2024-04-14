#include "Playlist.h"

void Playlist::add(Song& s)
{
	songs.push_back(&s);
}

void Playlist::clear()
{
	songs.clear();
}
void Playlist::remove(Song& s)
{
	if (find(songs.begin(), songs.end(), &s) != songs.end())
		songs.erase(find(songs.begin(), songs.end(), &s));
	else throw SongException("no song found");
}

