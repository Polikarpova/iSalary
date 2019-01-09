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

/**
* Класс, описывающий логику страницы "Зарплата"
*/
class SalaryPage : public QObject {
    Q_OBJECT
public:

    SalaryPage( SalesFacade * salesFacade, PersonnalAccountingFacade* personnalAccountingFacade);
    
	/**
	* Функция уставновки элементов ui, находящихся на странице, для непосредственного доступа к ним внутри класса SalaryPage
	*/
	void setUI( QTabWidget* tabWidget, QComboBox* salaryAccountingPeriod, QTableView* salaryTable, QTableView* salaryTotalTable, QLabel* managerFIOLabel, QSpinBox* salaryPasportSeries,
				QSpinBox* salaryPasportNumber, QLineEdit* salaryPasportSourse, QDateEdit* salaryDateOfReceipt, QRadioButton* salaryMaleRButton, QRadioButton* salaryFemaleRButton,
				QLineEdit* salaryINN, QPushButton* closeAccountingPeriod, QPushButton* salesButton, QPushButton* dataButton);
    
	~SalaryPage( void);

	/**
	* Функция обновления страницы
	*/
	void refreshPage();

	void setErrorHandler( ErrorMessageHandler* errorHandler);

	/**
	* Установка навигатора, для переключения на другие страницы
	*/
	void setTabNavigator(TabNavigator* tabNavigator);

protected slots:

	void showManager();
	void showSelectedPeriod();
	void showManagerInformation();
	void showManagerSales();
	void viewSales();

protected:

	/**
	* Инициализация выпадающего списка всеми периодами
	*/
	void initComboBox();

	/**
	* Инициализация формы с данными менеджера
	*/
	void initManagerForm();

	/**
	* Инициализация таблички со списоком менеджеров и зарплат
	*/
	void initSalaryTable ( QTableView* salaryTable);
	
	/**
	* Инициализация таблички с итогом
	*/
	void initSalaryTotalTable( QTableView* salaryTotalTable);
	
	/**
	* Возвращает id менеджера, выбранно в таблице со списком менеджеров и их зарплат
	* @return идентификатор менеджера
	*/
	int getSelectedManagerId();

	/**
	* Обновляет список расчетных периодов
	*/
	void updatePeriods();
	
private:
	ErrorMessageHandler* errorHandler;

    SalesFacade* salesFacade;
    PersonnalAccountingFacade* personnalAccountingFacade;
	
	TabNavigator* tabNav;

	QTabWidget* tabWidget;
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

	void setEnable(bool flag);
	
	/**
	* Добавление в таблицу кнопки, при нажатии на которую показываются продажи, повлиявшие на зарплату
	*/
	void addActionButtonsToTable(SalaryTableModel* model);
};