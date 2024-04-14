#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Project1.h"
#include <vector>
#include <string>
#include <QtWidgets/QApplication>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QTableWidget>
#include <QListWidget>
#include <QMessageBox>
#include <QHeaderView>
#include <QGroupBox>
#include <QRadioButton>

class Project1 : public QMainWindow
{
    Q_OBJECT

public:
    Project1(QWidget *parent = nullptr);
    ~Project1();

private:
    Ui::Project1Class ui;
};
