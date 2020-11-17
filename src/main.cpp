#include <qmessagebox.h>
#include <qapplication.h>
#include "MainWindow.hpp"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);

	if (argc < 2)
	{
		QMessageBox no_args_error_box;
		no_args_error_box.setWindowTitle("Error");
		no_args_error_box.setText("Too few arguments. Need at least one CSV file.");
		no_args_error_box.setIcon(QMessageBox::Icon::Critical);
		no_args_error_box.exec();

		return 1;
	}

	MainWindow window;
	window.show();

	return app.exec();
}