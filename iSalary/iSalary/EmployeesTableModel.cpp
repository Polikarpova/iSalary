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
    return COLUMN_LAST;
}

QVariant EmployeesTableModel::headerData( int section, Qt::Orientation orientation, int role ) const {
    if( role != Qt::DisplayRole ) {
        return QVariant();
    }
 
    if( orientation == Qt::Vertical ) {
        return section;
    }
 
    switch( section ) {
    case COLUMN_ID:
		return QString::fromWCharArray( L"id" );
    case COLUMN_FIO:
        return QString::fromWCharArray( L"ФИО" );
    case COLUMN_EMPLOY_DATE:
        return QString::fromWCharArray( L"Дата найма" );
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
    
    if( row < this->managerTable.size() && col < COLUMN_LAST) {
        return this->managerTable[ index.row()][ Column( index.column())];
    } else {
        return QVariant("Too big index");
    }
}
 
int EmployeesTableModel::getRecordId( int row) {
    int id = -1;

    if ( row >= 0 && row < this->managerTable.size() ){
        id = this->managerTable.at(row).at(COLUMN_ID).value<int>();
    }
    return id;
}

QDate EmployeesTableModel::getRecordDateOfEmployment( int row) {
    QDate date;

    if ( row >= 0 && row < this->managerTable.size() ){
        date = this->managerTable.at(row).at(COLUMN_EMPLOY_DATE).value<QDate>();
    }
    return date;
}


QModelIndex EmployeesTableModel::getIndexByRecordId( int id) {
    QModelIndex index;
    for( int iRow = 0; iRow < this->managerTable.size(); iRow++) {
        if ( this->managerTable.at( iRow).at( COLUMN_ID) == id){
            index = this->createIndex( iRow, COLUMN_ID);
        }
    }
    return index;
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
        
            row << manager.secondName + " " + manager.firstName + " " + manager.thirdName;
            row << manager.dateOfEmplyment;
            row << manager.id;
            this->managerTable.append( row);
        }

        this->endInsertRows();
    }

    //this->endResetModel();
}