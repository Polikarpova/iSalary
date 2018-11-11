#include "ConfirmedSalesTableModel.h"

int ConfirmedSalesTableModel::maxId = 1;

ConfirmedSalesTableModel::ConfirmedSalesTableModel(QObject* parent){
    this->id = ConfirmedSalesTableModel::maxId++;
}

ConfirmedSalesTableModel::~ConfirmedSalesTableModel(void){
}

//===OVERRIDE===//
int ConfirmedSalesTableModel::rowCount( const QModelIndex& parent ) const {
    Q_UNUSED( parent )
    return table.count();
}

int ConfirmedSalesTableModel::columnCount( const QModelIndex& parent ) const {
    Q_UNUSED( parent )
    return COLUMN_LAST;
}

QVariant ConfirmedSalesTableModel::headerData( int section, Qt::Orientation orientation, int role ) const {
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
    case COLUMN_DATE:
        return toUnicode( "Дата" );
	case COLUMN_NAME:
        return toUnicode( "Название" );
	case COLUMN_COUNT:
        return toUnicode( "Кол-во" );
	case COLUMN_PRICE:
        return toUnicode( "Цена" );
	case COLUMN_COMMISION:
        return toUnicode( "Продавцу, %" );
	case COLUMN_ACTION:
		return "";
    }
 
    return QVariant();
}

QVariant ConfirmedSalesTableModel::data( const QModelIndex& index, int role ) const {
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

int ConfirmedSalesTableModel::getRecordId( int row) {
    int id = -1;

    if( row >= 0 && row < this->table.size() ) {
        
		id = this->table.at(row).at(COLUMN_ID).value<int>();
    }

    return id;
}

QModelIndex ConfirmedSalesTableModel::getIndexByRecordId( int id) {
    
	QModelIndex index;
	
	for( int iRow = 0; iRow < this->table.size(); iRow++) {
		
		if( this->table.at( iRow).at( COLUMN_ID) == id) {

			index = this->createIndex( iRow, COLUMN_ID);
		}
	}

	return index;
}

void ConfirmedSalesTableModel::refreshData(const QList<ActiveSaleDTO>& sales) {

	if( table.size() > 0) {
        this->beginRemoveRows( QModelIndex(), 0, table.size() - 1);

        this->table.clear();

        this->endRemoveRows();
    }

    if( sales.size() > 0) { 
        this->beginInsertRows( QModelIndex(), 0, sales.size() - 1);

        for( int i = 0; i < sales.size(); i++) {
            
			const ActiveSaleDTO& sale = sales[i];
			QList<QVariant> row;
        
			row << sale.id;
			row << sale.managerName;
			row << QDate::currentDate();
			row << sale.product.name;
			row << sale.count;
			row << sale.price;
			row << sale.product.commission;
			row << "action";
            
			this->table.append( row);
        }

        this->endInsertRows();
    }
}