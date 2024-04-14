#pragma once
#include "qwidget.h"
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qlayout.h>
#include <QtWidgets/qformlayout.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qlistwidget.h>
#include <QtWidgets>
#include"SongController.h"
#include<stdexcept>

class ProjectGui : public QWidget {
public:

	ProjectGui(SongController& controller) : sc(controller) {
		initGUI();
		reloadSongs(sc.getAll());
		connectSignalSlots();
	}
	void gui_addSong();
	void gui_removeSong();
	void gui_sortbyTitle();
	void gui_sortbyArtist();
	void gui_undo();
	void gui_redo();
	//void gui_add_to_playlist();
	//void gui_remove_from_playlist();
	string gui_viewLyrics();
	
private:
	SongController& sc;

	QListWidget* allsongs = new QListWidget{};
	QListWidget* playlist = new QListWidget{};

	QPushButton* btn1 = new QPushButton{ ">"};
	QPushButton* nextbtn = new QPushButton{ "next" };
	QPushButton* playbtn = new QPushButton{ "play" };
	QPushButton* addplaylistbtn = new QPushButton{ "add to playlist" };
	QPushButton* delplaylistbtn = new QPushButton{ "del from playlist" };
	QPushButton* addbtn = new QPushButton{ "add" };
	QPushButton* delbtn = new QPushButton{ "delete" };
	QPushButton* sorttbtn = new QPushButton{ "sort by title" };
	QPushButton* sortabtn = new QPushButton{ "sort by artist" };
	QPushButton* lyricsbtn = new QPushButton{ "view lyrics" };
	QPushButton* undobtn = new QPushButton{ "undo" };
	QPushButton* redobtn = new QPushButton{ "redo" };


	QLineEdit* title_text = new QLineEdit{};
	QLineEdit* artist_text = new QLineEdit{};
	QLineEdit* year_text = new QLineEdit{};
	QLineEdit* link_text = new QLineEdit{};

	void connectSignalSlots();
	void reloadSongs(SongRepo songs);
	void initGUI();
};