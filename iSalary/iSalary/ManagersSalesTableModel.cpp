#include "ManagersSalesTableModel.h"

int ManagersSalesTableModel::maxId = 1;

ManagersSalesTableModel::ManagersSalesTableModel(QObject* parent){
    this->id = ManagersSalesTableModel::maxId++;
}

ManagersSalesTableModel::~ManagersSalesTableModel(void){
}

int ManagersSalesTableModel::rowCount( const QModelIndex& parent ) const {
    Q_UNUSED( parent )
    return table.count();
}

int ManagersSalesTableModel::columnCount( const QModelIndex& parent ) const {
    Q_UNUSED( parent )
    return COLUMN_LAST;
}

QVariant ManagersSalesTableModel::headerData( int section, Qt::Orientation orientation, int role ) const {
    if( role != Qt::DisplayRole ) {
        return QVariant();
    }
 
    if( orientation == Qt::Vertical ) {
        return section;
    }
 
    switch( section ) {
    case COLUMN_ID:
		return toUnicode( "id" );
    case COLUMN_FIO:
        return toUnicode( "ФИО" );
    case COLUMN_CONFIRM_COUNT:
        return toUnicode( "Кол-во подтвержденных продаж" );
	case COLUMN_UNCONFIRM_COUNT:
        return toUnicode( "Кол-во неподтвержденных продаж" );
    }
 
    return QVariant();
}

QVariant ManagersSalesTableModel::data( const QModelIndex& index, int role ) const {
    if(
        !index.isValid() ||
        table.count() <= index.row() ||
        ( role != Qt::DisplayRole && role != Qt::EditRole )
    ) {
        return QVariant();
    }

    int row = index.row();
    int col = index.column();
    
    if( row < this->table.size() && col < COLUMN_LAST) {
        return this->table[ index.row()][ Column( index.column())];
    } else {
        return QVariant("Too big index");
    }
}