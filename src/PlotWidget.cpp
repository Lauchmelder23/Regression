#include "PlotWidget.hpp"
#include "ui_PlotWidget.h"

#include <iostream>
#include <qmessagebox.h>

#include "csv.h"

PlotWidget::PlotWidget(QWidget* parent) :
	QWidget(parent), ui(new Ui::PlotWidget), data(nullptr)
{
	ui->setupUi(this);
}

PlotWidget::~PlotWidget()
{
	delete data;
	delete ui;
}

int PlotWidget::SetDataSource(const std::string& filename)
{
	try
	{
		io::CSVReader<2> reader(filename);

		data = new std::vector<DataPoint>;

		DataPoint dp;
		while (reader.read_row(dp.x, dp.y))
			data->push_back(dp);
	}
	catch (io::error::base& err)
	{
		if (data != nullptr) delete data;

		QMessageBox::critical(this, "Error", err.what());
		return 1;
	}

	// TODO: Remove, just for testing the CSV reader
	QString tmp_string = "<table>";
	for (DataPoint& dp : *data)
		tmp_string += QString::asprintf("<tr><td>%f</td><td>%f</td></tr>", dp.x, dp.y);
	tmp_string += "</table>";

	ui->tmp_CSVDisplay->insertHtml(tmp_string);

	return 0;
}
