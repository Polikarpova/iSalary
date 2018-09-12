#ifndef ISALARYPROTOTYPE_H
#define ISALARYPROTOTYPE_H

#include <QtWidgets/QMainWindow>
#include "ui_isalaryprototype.h"

class iSalaryPrototype : public QMainWindow
{
	Q_OBJECT

public:
	iSalaryPrototype(QWidget *parent = 0);
	~iSalaryPrototype();

private:
	Ui::iSalaryPrototypeClass ui;
};

#endif // ISALARYPROTOTYPE_H
