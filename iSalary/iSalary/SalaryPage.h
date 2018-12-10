#pragma once

#include <qobject.h>
#include "Codec.h"
#include <QTableView>
#include <qcombobox.h>
#include <qlabel.h>
#include <qspinbox.h>
#include <qlineedit.h>
#include <QDateEdit>
#include <qradiobutton.h>
#include <qpushbutton.h>

#include "ErrorMessageHandler.h"

#include "SalesFacade.h"
#include "PersonnalAccountingFacade.h"
#include "ActiveSaleDTO.h"
#include "ManagerActiveSalesStatisticDTO.h"

#include "SalaryTableModel.h"
#include "SalaryTotalTableModel.h"
#include <qheaderview.h>
#include <qmodelindex>
#include <qabstractitemview.h>

#include "ManagerDTO.h"
#include "TabNavigator.h"

class SalaryPage : public QObject{
    Q_OBJECT
public:
    SalaryPage( SalesFacade * salesFacade, PersonnalAccountingFacade* personnalAccountingFacade);
    void setUI( QComboBox* salaryAccountingPeriod, QTableView* salaryTable, QTableView* salaryTotalTable, QLabel* managerFIOLabel, QSpinBox* salaryPasportSeries,
				QSpinBox* salaryPasportNumber, QLineEdit* salaryPasportSourse, QDateEdit* salaryDateOfReceipt, QRadioButton* salaryMaleRButton, QRadioButton* salaryFemaleRButton,
				QLineEdit* salaryINN, QPushButton* closeAccountingPeriod, QPushButton* salesButton, QPushButton* dataButton);
    ~SalaryPage( void);

	void refreshPage();

	void setErrorHandler( ErrorMessageHandler* errorHandler);

	void setTabNavigator(TabNavigator* tabNavigator);

protected slots:

	void showManager();
	void showSelectedPeriod();
	void showManagerInformation();

protected:

	/**
	* ������������� ����������� ������ ����� ���������
	*/
	void initComboBox();

	/**
	* ������������� ����� � ������� ���������
	*/
	void initManagerForm();

	/**
	* ������������� �������� �� �������� ���������� � �������
	*/
	void initSalaryTable ( QTableView* salaryTable);
	
	/**
	* ������������� �������� � ������
	*/
	void initSalaryTotalTable( QTableView* salaryTotalTable);
	
	/**
	* ���������� id ���������, �������� � ������� �� ������� ���������� � �� �������
	* @return ������������� ���������
	*/
	int getSelectedManagerId();

	/**
	* ��������� ������ ��������� ��������
	*/
	void updatePeriods();
	
private:
	ErrorMessageHandler* errorHandler;

    SalesFacade* salesFacade;
    PersonnalAccountingFacade* personnalAccountingFacade;
	
	TabNavigator* tabNav;

	QComboBox* salaryAccountingPeriod;
	QTableView* salaryTable;
	QTableView* salaryTotalTable;
	
	QLabel* managerFIOLabel;
	QSpinBox* salaryPasportSeries;
	QSpinBox* salaryPasportNumber;
	QLineEdit* salaryPasportSourse;
	QDateEdit* salaryDateOfReceipt;
	QRadioButton* salaryMaleRButton;
	QRadioButton* salaryFemaleRButton;
	QLineEdit* salaryINN;

	QPushButton* closeAccountingPeriod;
	QPushButton* salesButton;
	QPushButton* dataButton;

	QMap<int, AccoutingPeriodDTO> comboBoxMap;
	QHash<int, ManagerSalaryDTO> salary;
	QHash<int, ManagerSalaryDTO> salaryTotal;
};