#include "Repo.h"

void SongRepo::store(const Song& s)
{
	auto it = find_if(songs.begin(), songs.end(), [&s](const Song& sg) {
		return s.getArtist() == sg.getArtist() && s.getTitle() == sg.getTitle();
		});
	if (it != songs.end()) {
		string errorM= "A song " + s.getTitle() + " by " + s.getArtist() + " already exists";
		throw SongException(errorM);
	}
	songs.push_back(s);
}

void SongRepo::remove(const Song& s)
{
	auto it = find_if(songs.begin(), songs.end(), [&s](const Song& sg) {
		return s.getArtist() == sg.getArtist() && s.getTitle() == sg.getTitle();
		});
	if (it == songs.end()) {
		string errorM = "A song " + s.getTitle() + " by " + s.getArtist() + " doesn't exist";
		throw SongException(errorM);
	}
	else songs.erase(it);

}

const Song& SongRepo::find(string t, string a)
{
	auto it = find_if(songs.begin(), songs.end(), [&t, &a](const Song& sg) {
		return a == sg.getArtist() && t == sg.getTitle();
		});
	if (it == songs.end()) {
		string errorM = "A song " + t + " by " + a + " doesn't exist";
		throw SongException(errorM);
	}
	else return *it;
}


const std::vector<Song>& SongRepo::getAllSongs() const
{
	return songs;
}
