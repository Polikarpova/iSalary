#pragma once

#include "Codec.h"
#include <QAbstractTableModel>

#include "ManagerStatisticDTO.h"

class StatisticTableModel : public QAbstractTableModel {
    Q_OBJECT
public:
    StatisticTableModel(QObject* parent = 0);
    ~StatisticTableModel(void);

	void refreshData(const QList<ManagerStatisticDTO>& managers);
    int getRecordId( int row);
    QModelIndex getIndexByRecordId( int id);

    int rowCount( const QModelIndex& parent ) const override;
    int columnCount( const QModelIndex& parent ) const override;
    QVariant data( const QModelIndex& index, int role ) const override;
    QVariant headerData( int section, Qt::Orientation orientation, int role ) const override;

    
    enum Column {
		COLUMN_ID,
        COLUMN_FIO,
        COLUMN_SALES_COUNT,
        COLUMN_INCOME,
		COLUMN_LET,
		COLUMN_OET,
        COLUMN_LAST /*Обозначает кол-во столбцов, на самом деле не существует*/
    };

private:
    int id;
    static int maxId;
    QList<QList<QVariant>> table;
};
