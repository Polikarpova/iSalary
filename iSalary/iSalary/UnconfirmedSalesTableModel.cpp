#include "UnconfirmedSalesTableModel.h"

int UnconfirmedSalesTableModel::maxId = 1;

UnconfirmedSalesTableModel::UnconfirmedSalesTableModel(QObject* parent){
    this->id = UnconfirmedSalesTableModel::maxId++;
}

UnconfirmedSalesTableModel::~UnconfirmedSalesTableModel(void){
}

//===OVERRIDE===//
int UnconfirmedSalesTableModel::rowCount( const QModelIndex& parent ) const {
    Q_UNUSED( parent )
    return table.count();
}

int UnconfirmedSalesTableModel::columnCount( const QModelIndex& parent ) const {
    Q_UNUSED( parent )
    return COLUMN_LAST;
}

QVariant UnconfirmedSalesTableModel::headerData( int section, Qt::Orientation orientation, int role ) const {
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
        return toUnicode( "���" );
    case COLUMN_DATE:
        return toUnicode( "����" );
	case COLUMN_NAME:
        return toUnicode( "��������" );
	case COLUMN_COUNT:
        return toUnicode( "���-��" );
	case COLUMN_PRICE:
        return toUnicode( "����" );
	case COLUMN_COMMISION:
        return toUnicode( "��������, %" );
	case COLUMN_ACTION:
		return "";
    }
 
    return QVariant();
}

QVariant UnconfirmedSalesTableModel::data( const QModelIndex& index, int role ) const {
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

int UnconfirmedSalesTableModel::getRecordId( int row) {
    int id = -1;

    if( row >= 0 && row < this->table.size() ) {
        
		id = this->table.at(row).at(COLUMN_ID).value<int>();
    }

    return id;
}

QModelIndex UnconfirmedSalesTableModel::getIndexByRecordId( int id) {
    
	QModelIndex index;
	
	for( int iRow = 0; iRow < this->table.size(); iRow++) {
		
		if( this->table.at( iRow).at( COLUMN_ID) == id) {

			index = this->createIndex( iRow, COLUMN_ID);
		}
	}

	return index;
}

void UnconfirmedSalesTableModel::refreshData(const QList<ActiveSaleDTO>& sales) {

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