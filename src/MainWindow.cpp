#include "MainWindow.hpp"
#include "ui_MainWindow.h"

MainWindow::MainWindow(char** argv, QWidget* parent) :
	QMainWindow(parent), ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	error_code = ui->plot->SetDataSource(argv[1]);
}

MainWindow::~MainWindow()
{
	delete ui;
}