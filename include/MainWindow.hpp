#pragma once

#include <QMainWindow>

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(char** argv, QWidget* parent = nullptr);
	~MainWindow();

	int Failed() { return error_code; }

private:
	Ui::MainWindow* ui;
	int error_code;
};