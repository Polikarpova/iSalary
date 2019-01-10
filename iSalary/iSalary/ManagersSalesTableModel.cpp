#include "ManagersSalesTableModel.h"

int ManagersSalesTableModel::maxId = 1;

ManagersSalesTableModel::ManagersSalesTableModel( QObject *parent ) { this->id = ManagersSalesTableModel::maxId++; }

ManagersSalesTableModel::~ManagersSalesTableModel( void ) {}

//===OVERRIDE===//
int ManagersSalesTableModel::rowCount( const QModelIndex &parent ) const {
    Q_UNUSED( parent )
    return table.count();
}

int ManagersSalesTableModel::columnCount( const QModelIndex &parent ) const {
    Q_UNUSED( parent )
    return COLUMN_LAST;
}

QVariant ManagersSalesTableModel::headerData( int section, Qt::Orientation orientation, int role ) const {
    if ( role != Qt::DisplayRole ) {
        return QVariant();
    }

    if ( orientation == Qt::Vertical ) {
        return section;
    }

    switch ( section ) {
    case COLUMN_ID:
        return QString::fromWCharArray( L"id" );
    case COLUMN_FIO:
        return QString::fromWCharArray( L"ФИО" );
    case COLUMN_CONFIRM_COUNT:
        return QString::fromWCharArray( L"Кол-во подтвержденных" );
    case COLUMN_UNCONFIRM_COUNT:
        return QString::fromWCharArray( L"Кол-во неподтвержденных" );
    }

    return QVariant();
}

QVariant ManagersSalesTableModel::data( const QModelIndex &index, int role ) const {
    if ( !index.isValid() || table.count() <= index.row() || ( role != Qt::DisplayRole && role != Qt::EditRole ) ) {
        return QVariant();
    }

    int row = index.row();
    int col = index.column();

    if ( row < this->table.size() && col < COLUMN_LAST ) {
        return this->table[index.row()][Column( index.column() )];
    } else {
        return QVariant( "Too big index" );
    }
}
//===OVERRIDE===//

int ManagersSalesTableModel::getRecordId( int row ) {
    int id = -1;

    if ( row >= 0 && row < this->table.size() ) {

        id = this->table.at( row ).at( COLUMN_ID ).value<int>();
    }

    return id;
}

QModelIndex ManagersSalesTableModel::getIndexByRecordId( int id ) {

    QModelIndex index;

    for ( int iRow = 0; iRow < this->table.size(); iRow++ ) {

        if ( this->table.at( iRow ).at( COLUMN_ID ) == id ) {

            index = this->createIndex( iRow, COLUMN_ID );
        }
    }
    return index;
}

void ManagersSalesTableModel::refreshData( const QList<ManagerActiveSalesStatisticDTO> &managers ) {

    if ( table.size() > 0 ) {
        this->beginRemoveRows( QModelIndex(), 0, table.size() - 1 );

        this->table.clear();

        this->endRemoveRows();
    }

    if ( managers.size() > 0 ) {
        this->beginInsertRows( QModelIndex(), 0, managers.size() - 1 );

        for ( int i = 0; i < managers.size(); i++ ) {
            const ManagerActiveSalesStatisticDTO &manager = managers[i];
            QList<QVariant> row;

            row << manager.managerId;
            row << manager.managerName;
            row << manager.confirmCount;
            row << manager.unconfirmCount;

            this->table.append( row );
        }

        this->endInsertRows();
    }
}