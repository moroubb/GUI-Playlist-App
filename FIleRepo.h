#pragma once
#include "Repo.h"
#include <fstream>

class FileRepository : public SongRepo {
protected:
	string filepath;
public:
	FileRepository(string filename);
	void load();
	void save();

};
