#pragma once

#include "Codec.h"
#include <QAbstractTableModel>

#include "ActiveSaleDTO.h"

class StatisticSalesTableModel : public QAbstractTableModel {
    Q_OBJECT
public:
    StatisticSalesTableModel(QObject* parent = 0);
    ~StatisticSalesTableModel(void);

	void refreshData(const QList<ActiveSaleDTO>& sales);
    int getRecordId( int row);
    QModelIndex getIndexByRecordId( int id);

    int rowCount( const QModelIndex& parent ) const override;
    int columnCount( const QModelIndex& parent ) const override;
    QVariant data( const QModelIndex& index, int role ) const override;
    QVariant headerData( int section, Qt::Orientation orientation, int role ) const override;

    
    enum Column {
		COLUMN_ID,
        COLUMN_FIO,
		COLUMN_SALE_DATE,
        COLUMN_COUNT,
        COLUMN_NAME,
		COLUMN_PRICE,
		COLUMN_COMMISION,
        COLUMN_LAST /*Обозначает кол-во столбцов, на самом деле не существует*/
    };

private:
    int id;
    static int maxId;
    QList<QList<QVariant>> table;
};
