#include "SalaryTableModel.h"

int SalaryTableModel::maxId = 1;

SalaryTableModel::SalaryTableModel(QObject* parent){
    this->id = SalaryTableModel::maxId++;
}

SalaryTableModel::~SalaryTableModel(void){
}

//===OVERRIDE===//
int SalaryTableModel::rowCount( const QModelIndex& parent ) const {
    Q_UNUSED( parent )
    return table.count();
}

int SalaryTableModel::columnCount( const QModelIndex& parent ) const {
    Q_UNUSED( parent )
    return COLUMN_LAST;
}

QVariant SalaryTableModel::headerData( int section, Qt::Orientation orientation, int role ) const {
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
		return QString::fromWCharArray( L"ФИО" );
    case COLUMN_INCOME:
        return QString::fromWCharArray( L"С продаж, руб." );
	case COLUMN_SALARY:
        return QString::fromWCharArray( L"Зарплата, руб." );
	case COLUMN_SALES:
        return QString::fromWCharArray( L"Продажи" );
    }
 
    return QVariant();
}

QVariant SalaryTableModel::data( const QModelIndex& index, int role ) const {
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

int SalaryTableModel::getRecordId( int row) {
    int id = -1;

    if( row >= 0 && row < this->table.size() ) {
        
		id = this->table.at(row).at(COLUMN_ID).value<int>();
    }

    return id;
}

QModelIndex SalaryTableModel::getIndexByRecordId( int id) {
    
	QModelIndex index;
	
	for( int iRow = 0; iRow < this->table.size(); iRow++) {
		
		if( this->table.at( iRow).at( COLUMN_ID) == id) {

			index = this->createIndex( iRow, COLUMN_ID);
		}
	}

	return index;
}

void SalaryTableModel::refreshData(const QList<ManagerSalaryDTO>& data) {

	if( table.size() > 0) {
        this->beginRemoveRows( QModelIndex(), 0, table.size() - 1);

        this->table.clear();

        this->endRemoveRows();
    }

    if( data.size() > 0) { 
        this->beginInsertRows( QModelIndex(), 0, data.size() - 1);

        for( int i = 0; i < data.size(); i++) {
            
			const ManagerSalaryDTO& el = data[i];
			QList<QVariant> row;

			row << el.managerId;
			row << el.managerName;
			row << el.income;
			row << el.salary;
			row << "";
            
			this->table.append( row);
        }

        this->endInsertRows();
    }
}