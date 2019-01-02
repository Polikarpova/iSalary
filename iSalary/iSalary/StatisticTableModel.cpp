#include "StatisticTableModel.h"

int StatisticTableModel::maxId = 1;

StatisticTableModel::StatisticTableModel(QObject* parent){
    this->id = StatisticTableModel::maxId++;
}

StatisticTableModel::~StatisticTableModel(void){
}

//===OVERRIDE===//
int StatisticTableModel::rowCount( const QModelIndex& parent ) const {
    Q_UNUSED( parent )
    return table.count();
}

int StatisticTableModel::columnCount( const QModelIndex& parent ) const {
    Q_UNUSED( parent )
    return COLUMN_LAST;
}

QVariant StatisticTableModel::headerData( int section, Qt::Orientation orientation, int role ) const {
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
    case COLUMN_SALES_COUNT:
        return QString::fromWCharArray( L"Кол-во продаж, шт." );
	case COLUMN_INCOME:
        return QString::fromWCharArray( L"Прибыль, руб" );
	case COLUMN_LET:
        return QString::fromWCharArray( L"ЛЭТ, %" );
	case COLUMN_OET:
        return QString::fromWCharArray( L"ОЭТ, %" );
    }
 
    return QVariant();
}

QVariant StatisticTableModel::data( const QModelIndex& index, int role ) const {
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
//===OVERRIDE===//

int StatisticTableModel::getRecordId( int row) {
    int id = -1;

    if( row >= 0 && row < this->table.size() ) {
        
		id = this->table.at(row).at(COLUMN_ID).value<int>();
    }

    return id;
}

QModelIndex StatisticTableModel::getIndexByRecordId( int id) {
    
	QModelIndex index;
    
	for( int iRow = 0; iRow < this->table.size(); iRow++) {

        if( this->table.at( iRow).at( COLUMN_ID) == id) {

            index = this->createIndex( iRow, COLUMN_ID);
        }
    }
    return index;
}

void StatisticTableModel::refreshData(const QList<ManagerStatisticDTO>& managers) {

	if( table.size() > 0) {
        this->beginRemoveRows( QModelIndex(), 0, table.size() - 1);

        this->table.clear();

        this->endRemoveRows();
    }

    if( managers.size() > 0) { 
        this->beginInsertRows( QModelIndex(), 0, managers.size() - 1);

        for( int i = 0; i < managers.size(); i++) {
            const ManagerStatisticDTO& manager = managers[i];
            QList<QVariant> row;
        
			row << manager.managerId;
			row << manager.managerName;
			row << manager.salesCount;
			row << manager.income;
			row << manager.let;
			row << manager.oet;
            
            this->table.append( row);
        }

        this->endInsertRows();
    }
}