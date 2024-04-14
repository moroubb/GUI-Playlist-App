#include "SongController.h"


void SongController::add(string a, string t, string l, string u, int y)
{
	Song song(a, t, l, u, y);
	Action* addAction = new ActionAdd(songsc, song);
	addAction->apply();
	undostack.push(addAction);

	
}

void SongController::del(string a, string t)
{
	const Song& song = songsc.find(t, a);
	if (&song) {
		Action* deleteAction = new ActionDelete(songsc, song);
		deleteAction->apply();
		undostack.push(deleteAction);
	}
}

const Song& SongController::search(string t, string a)
{
	return songsc.find(t, a);
}

SongRepo SongController::getbyArtist(string order)
{
	auto compareArtist = [](const Song& song1, const Song& song2) {
		return song1.getArtist() < song2.getArtist();
	};
	sort(songsc.songs.begin(), songsc.songs.end(), compareArtist);
	if (order == "increasing")
		return songsc;
	else if (order == "decreasing") {
		reverse(songsc.songs.begin(), songsc.songs.end());
		return songsc;
	}
	else throw exception("input correct order");
}

SongRepo SongController::getbyTitle(string order)
{
	auto compareTitle = [](const Song& song1, const Song& song2) {
		return song1.getTitle() < song2.getTitle();
	};
	sort(songsc.songs.begin(), songsc.songs.end(), compareTitle);
	if (order == "increasing")
		return songsc;
	else if (order == "decreasing") {
			reverse(songsc.songs.begin(), songsc.songs.end());
			return songsc;
		}
	else throw exception("input correct order");
}

void SongController::undo()
{
	if (!undostack.empty()) {
		Action* action = undostack.top();
		undostack.pop();
		redostack.push(action);
		action->apply();
	}
}

void SongController::redo()
{
	if (!redostack.empty()) {
		Action* action = redostack.top();
		redostack.pop();
		undostack.push(action);
		action->apply();
	}
}

void SongController::clearRedoStack()
{
	while (!redostack.empty()) {
		Action* action = redostack.top();
		redostack.pop();
		delete action;
	}
}
