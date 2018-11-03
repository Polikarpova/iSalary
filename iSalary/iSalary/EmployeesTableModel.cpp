#include "EmployeesTableModel.h"

int EmployeesTableModel::maxId = 1;

EmployeesTableModel::EmployeesTableModel(QObject* parent){
    this->id = EmployeesTableModel::maxId++;
}


EmployeesTableModel::~EmployeesTableModel(void){
}

int EmployeesTableModel::rowCount( const QModelIndex& parent ) const {
    Q_UNUSED( parent )
    return managerTable.count();
}

int EmployeesTableModel::columnCount( const QModelIndex& parent ) const {
    Q_UNUSED( parent )
    return LAST;
}

QVariant EmployeesTableModel::headerData( int section, Qt::Orientation orientation, int role ) const {
    if( role != Qt::DisplayRole ) {
        return QVariant();
    }
 
    if( orientation == Qt::Vertical ) {
        return section;
    }
 
    switch( section ) {
    case ID:
        return trUtf8( "id" );
    case FIO:
        return trUtf8( "���" );
    case EMPLOY_DATE:
        return trUtf8( "���� �����" );
    }
 
    return QVariant();
}

QVariant EmployeesTableModel::data( const QModelIndex& index, int role ) const {
    if(
        !index.isValid() ||
        managerTable.count() <= index.row() ||
        ( role != Qt::DisplayRole && role != Qt::EditRole )
    ) {
        return QVariant();
    }

    int row = index.row();
    int col = index.column();
    
    if( row < managerTable.size() && col < LAST) {
        return managerTable[ index.row() ][ Column( index.column() ) ];
    } else {
        return QVariant("Too big index");
    }
}
 

void EmployeesTableModel::refreshData(const QList<ManagerDTO>& managers){
    
    if( managerTable.size() > 0) {
        this->beginRemoveRows( QModelIndex(), 0, managerTable.size() - 1);

        this->managerTable.clear();

        this->endRemoveRows();
    }

    if( managers.size() > 0) { 
        this->beginInsertRows( QModelIndex(), 0, managers.size() - 1);

        for( int i = 0; i < managers.size(); i++) {
            const ManagerDTO& manager = managers[i];
            QList<QVariant> row;
        
            row << manager.secondName + " " + manager.firstName + " " + manager.secondName;
            row << manager.dateOfEmplyment;
            row << manager.id;
            this->managerTable.append( row);
        }

        this->endInsertRows();
    }

    //this->endResetModel();
}