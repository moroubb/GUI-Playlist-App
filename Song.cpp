#include "Song.h"

vector<string> Song::parseLyrics(string lyrics)
{
    {
        vector<string> words;
        // Convert all characters to lowercase
        transform(lyrics.begin(), lyrics.end(), lyrics.begin(), [](unsigned char c) { return tolower(c); });
        // Replace all punctuation and digits with spaces
        for (char& c : lyrics) {
            if (ispunct(c) || isdigit(c)) {
                c = ' ';
            }
        }
        // Split the lyrics into words and store them in a vector
        stringstream ss(lyrics);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        return words;
    }
}

Song::Song(string a, string t, string l, string u, int y)
{
    artist = a;
    title = t;
    lyrics = parseLyrics(l);
    url = u;
    year = y;
}

string Song::getArtist() const
{
    return this->artist;
}

string Song::getLyrics() const
{
    stringstream ss;
    for (auto c : lyrics)
        ss<<c;
    return ss.str();
}

string Song::getTitle() const
{
    return this->title;
}

string Song::getUrl() const
{
    return this->url;
}

int Song::getNrWords() const
{
    return lyrics.size();
}

int Song::getYear() const
{
    return this->year;
}

ostream& operator<<(ostream& os, const Song& s)
{
    os << s.getArtist() << " " << s.getTitle() << "; ";
    return os;

}
