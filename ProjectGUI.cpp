#include "ProjectGUI.h"



void ProjectGui::connectSignalSlots()
{
	QObject::connect(addbtn, &QPushButton::clicked, this, &ProjectGui::gui_addSong);
	QObject::connect(delbtn, &QPushButton::clicked, this, &ProjectGui::gui_removeSong);
	QObject::connect(sortabtn, &QPushButton::clicked, this, &ProjectGui::gui_sortbyArtist);
	QObject::connect(sorttbtn, &QPushButton::clicked, this, &ProjectGui::gui_sortbyTitle);
	QObject::connect(undobtn, &QPushButton::clicked, this, &ProjectGui::gui_undo);
	QObject::connect(redobtn, &QPushButton::clicked, this, &ProjectGui::gui_redo);
}
void ProjectGui::reloadSongs(SongRepo songs)
{
	this->allsongs->clear();
	for (auto& song : songs.getAllSongs())
	{
		string str = song.getTitle() + " " + song.getArtist()+ " " + to_string(song.getYear());
		this->allsongs->addItem(str.c_str());

	}
}

void ProjectGui::initGUI()
{
	QHBoxLayout* l1 = new QHBoxLayout{};
	setLayout(l1);

	auto layoutr = new QVBoxLayout{};
	auto layoutl = new QVBoxLayout{};
	auto layoutm = new QVBoxLayout{};
	l1->addLayout(layoutl);
	l1->addLayout(layoutm);
	l1->addLayout(layoutr);


	layoutr->addWidget(new QLabel{ "playlist" });
	layoutl->addWidget(new QLabel{ "all songs" });
	layoutl->addWidget(allsongs);
	layoutm->addWidget(btn1);
	layoutr->addWidget(playlist);

	///layout dreapta
	auto layoutd = new QHBoxLayout{};
	
	layoutd->addWidget(playbtn);
	layoutd->addWidget(nextbtn);
	layoutd->addWidget(addplaylistbtn);
	layoutd->addWidget(delplaylistbtn);
	layoutr->addLayout(layoutd);


	///layout stanga
	auto layouts = new QFormLayout;
	layouts->addRow("Title",title_text);
	layouts->addRow("Artist",artist_text);
	layouts->addRow("Year",year_text);
	layouts->addRow("link",link_text);
	layoutl->addLayout(layouts);

	auto layoutbtn = new QFormLayout;
	layoutbtn->addWidget(addbtn);
	layoutbtn->addWidget(delbtn);
	layoutbtn->addWidget(sorttbtn);
	layoutbtn->addWidget(sortabtn);
	layoutbtn->addWidget(lyricsbtn);
	layoutbtn->addWidget(undobtn);
	layoutbtn->addWidget(redobtn);


	layoutl->addLayout(layoutbtn);
}

void ProjectGui::gui_addSong()
{
	try {
		string t = title_text->text().toStdString();
		string a = artist_text->text().toStdString();
		string l = link_text->text().toStdString();
		int y = year_text->text().toInt();
	
		title_text->clear();
		artist_text->clear();
		link_text->clear();
		year_text->clear();
		sc.add(a, t, " ", l, y);
		reloadSongs(this->sc.getAll());
	}
	catch (const SongException& e) {
		QMessageBox::critical(this,"Error", QString::fromStdString(e.what()));
	}
}

void ProjectGui::gui_removeSong()
{
	string t = title_text->text().toStdString();
	string a = artist_text->text().toStdString();
	title_text->clear();
	artist_text->clear();
	try {
		sc.del(a, t);
		reloadSongs(this->sc.getAll());
	}
	catch (const SongException& e) {
		QMessageBox::critical(this, "Error", QString::fromStdString(e.what()));
	}
}

void ProjectGui::gui_sortbyTitle()
{
	bool ok;
	QString ord = QInputDialog::getText(this, "order", "Input order", QLineEdit::Normal, "", &ok);
	if (!ok || ord.isEmpty())
		QMessageBox::critical(this, "error", "Input something");
	else {
		try {
			sc.getbyTitle(ord.toStdString());
			reloadSongs(this->sc.getAll());
		}
		catch (const exception& e) {
			QMessageBox::critical(this, "Error", QString::fromStdString(e.what()));
		}
	}
}

void ProjectGui::gui_sortbyArtist() {
	bool ok;
	QString ord = QInputDialog::getText(this, "order", "Input order", QLineEdit::Normal, "", &ok);
	if (!ok || ord.isEmpty())
		QMessageBox::critical(this, "error", "Input something");
	else {
		try {
			sc.getbyArtist(ord.toStdString());
			reloadSongs(this->sc.getAll());
		}
		catch (const exception& e) {
			QMessageBox::critical(this, "Error", QString::fromStdString(e.what()));
		}
	}
}

void ProjectGui::gui_undo()
{
	sc.undo();
}

void ProjectGui::gui_redo()
{
	sc.redo();
}

string ProjectGui::gui_viewLyrics()
{
	string t = title_text->text().toStdString();
	string a = artist_text->text().toStdString();
	title_text->clear();
	artist_text->clear();
	return " ";
}



