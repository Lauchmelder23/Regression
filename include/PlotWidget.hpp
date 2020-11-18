#pragma once

#include <QWidget>
#include <vector>

namespace Ui {
	class PlotWidget;
}

typedef struct {
	double x, y;
} DataPoint;

class PlotWidget : public QWidget
{
	Q_OBJECT

public:
	PlotWidget(QWidget* parent = nullptr);
	~PlotWidget();

	int SetDataSource(const std::string& filename);

private:
	Ui::PlotWidget* ui;

	std::vector<DataPoint>* data;
};