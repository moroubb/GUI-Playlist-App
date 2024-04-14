#include "FIleRepo.h"


FileRepository::FileRepository(string filename)
{
	this->filepath = filename;
}

void FileRepository::load()
{
	ifstream infile(filepath);
	if (infile.is_open())
	{
		string artist, title, lyrics1, lyrics2,link,years;
		int year;
		while (getline(infile, artist)) {
			getline(infile, title);
			getline(infile, years);
			getline(infile, link);
			getline(infile, lyrics1);
			getline(infile, lyrics2, '\"');
			lyrics1 += lyrics2;
			artist.erase(artist.begin(), artist.begin() + 8);
			title.erase(title.begin(), title.begin() + 7);
			link.erase(link.begin(), link.begin() + 4);
			years.erase(years.begin(), years.begin() + 5);
			year = stoi(years);
			lyrics1.erase(lyrics1.begin(), lyrics1.begin() + 8);
			auto s = Song(artist, title, lyrics1, link, year);
			songs.push_back(s);
		}
	}
	else {
		throw runtime_error("Failed to open file: " + filepath);
	}
}

void FileRepository::save()
{
	std::ofstream file(filepath);
	if (file.is_open()) {
		for (const Song& song : songs) {
			file << song.getTitle() << " " << song.getArtist() << " " << song.getYear() <<" "<<song.getUrl()<<" " << song.getLyrics() << std::endl;
		}
		file.close();
	}
	else {
		throw std::runtime_error("Failed to save songs to file: " + filepath);
	}
}

