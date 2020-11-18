#include <iostream>

#include <qmessagebox.h>
#include <qapplication.h>
#include "MainWindow.hpp"

#include <csv.h>

void DisplayQMessageBox(const QString& description)
{
	QMessageBox msgBox;
	msgBox.setWindowTitle("Error");
	msgBox.setText(description);
	msgBox.setIcon(QMessageBox::Icon::Critical);
	msgBox.exec();
}

int main(int argc, char** argv)
{
	QApplication app(argc, argv);

	if (argc < 2)
	{
		DisplayQMessageBox("Too few arguments. Need at least one CSV file.");
		return 1;
	}

	MainWindow window(argv);
	int err_code = window.Failed();
	if (err_code)
		return err_code;

	window.show();

	return app.exec();
}