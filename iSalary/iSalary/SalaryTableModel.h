#pragma once

#include "Codec.h"
#include <QAbstractTableModel>

#include "ManagerSalaryDTO.h"

class SalaryTableModel : public QAbstractTableModel {
    Q_OBJECT
public:
    SalaryTableModel(QObject* parent = 0);
    ~SalaryTableModel(void);

	void refreshData(const QList<ManagerSalaryDTO>& sales);
    int getRecordId( int row);
    QModelIndex getIndexByRecordId( int id);

    int rowCount( const QModelIndex& parent ) const override;
    int columnCount( const QModelIndex& parent ) const override;
    QVariant data( const QModelIndex& index, int role ) const override;
    QVariant headerData( int section, Qt::Orientation orientation, int role ) const override;

    
    enum Column {
		COLUMN_ID,
        COLUMN_FIO,
        COLUMN_INCOME,
        COLUMN_SALARY,
        COLUMN_LAST /*Обозначает кол-во столбцов, на самом деле не существует*/
    };

private:
    int id;
    static int maxId;
    QList<QList<QVariant>> table;
};
