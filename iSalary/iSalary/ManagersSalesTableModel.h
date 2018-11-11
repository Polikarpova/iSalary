#pragma once

#include <QAbstractTableModel>
#include "Codec.h"

class ManagersSalesTableModel : public QAbstractTableModel {
    Q_OBJECT
public:
    ManagersSalesTableModel(QObject* parent = 0);
    ~ManagersSalesTableModel(void);

    int getRecordId( int row);
    QModelIndex getIndexByRecordId( int id);

    int rowCount( const QModelIndex& parent ) const override;
    int columnCount( const QModelIndex& parent ) const override;
    QVariant data( const QModelIndex& index, int role ) const override;
    QVariant headerData( int section, Qt::Orientation orientation, int role ) const override;

    
    enum Column {
        COLUMN_FIO,
        COLUMN_CONFIRM_COUNT,
        COLUMN_UNCONFIRM_COUNT,
		COLUMN_ID,
        COLUMN_LAST /*Обозначает кол-во столбцов, на самом деле не существует*/
    };

private:
    int id;
    static int maxId;
    QList<QList<QVariant>> table;
};

