#pragma once

#include "Codec.h"
#include <QAbstractTableModel>

#include "ManagerSalaryDTO.h"

/**
* Таблица с итоговыми данными о зарплате
*/
class SalaryTotalTableModel : public QAbstractTableModel {
    Q_OBJECT
public:
    SalaryTotalTableModel(QObject* parent = 0);
    ~SalaryTotalTableModel(void);

	void refreshData(const QList<ManagerSalaryDTO>& data);
    int getRecordId( int row);
    QModelIndex getIndexByRecordId( int id);

    int rowCount( const QModelIndex& parent ) const override;
    int columnCount( const QModelIndex& parent ) const override;
    QVariant data( const QModelIndex& index, int role ) const override;
    QVariant headerData( int section, Qt::Orientation orientation, int role ) const override;

    
    enum Column {
		COLUMN_ID,
        COLUMN_EMPTY,
        COLUMN_ALL_INCOME,
        COLUMN_ALL_SALARY,
        COLUMN_LAST /*Обозначает кол-во столбцов, на самом деле не существует*/
    };

private:
    int id;
    static int maxId;
    QList<QList<QVariant>> table;
};
