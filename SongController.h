#pragma once
#include "Repo.h"
#include <stack>
#include <QinputDialog>
#include <qmessagebox.h>
using namespace std;

class Action {
protected:
	SongRepo& repo;
	Song song;
public:
	Action(SongRepo& r, Song s) :repo{ r }, song{ s } {};
	virtual ~Action() = default;
	virtual void apply() = 0;
};

class ActionAdd :public Action {
public:
	ActionAdd(SongRepo& r, Song s) :Action{ r,s } {};
	void apply() override {
		repo.store(song);
	}
};

class ActionDelete :public Action {
public:
	ActionDelete(SongRepo& r, Song s) :Action{ r,s } {};
	void apply() override {
		repo.remove(song);
	}
};

class SongController {
private:
	SongRepo& songsc;
public:
	stack<Action*>undostack;
	stack<Action*>redostack;
	

	SongController()=default;
	SongController(SongRepo& r) : songsc{ r } {};
	void add(string a, string t, string l, string u, int y);
	void del(string a, string t);
	const Song& search(string t, string a);
	SongRepo getbyArtist(string order);
	SongRepo getbyTitle(string order);
	SongRepo getAll() {
		return songsc;
	};

	void undo();
	void redo();
	void clearRedoStack();
};


