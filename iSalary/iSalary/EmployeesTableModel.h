#pragma once

#include <QAbstractTableModel>

#include "ManagerDTO.h"

class EmployeesTableModel : public QAbstractTableModel {
    Q_OBJECT
public:
    EmployeesTableModel(QObject* parent = 0);
    ~EmployeesTableModel(void);

    void refreshData(const QList<ManagerDTO>& managers);

    int rowCount( const QModelIndex& parent ) const override;
    int columnCount( const QModelIndex& parent ) const override;
    QVariant data( const QModelIndex& index, int role ) const override;
    QVariant headerData( int section, Qt::Orientation orientation, int role ) const override;

    
    enum Column {
        COLUMN_FIO,
        COLUMN_EMPLOY_DATE,
        COLUMN_ID,
        COLUMN_LAST /*Обозначает кол-во столбцов, на самом деле не существует*/
    };
signals:
    void managerSelected( int managerId);

private:
    int id;
    static int maxId;
    QList<QList<QVariant>> managerTable;
};

