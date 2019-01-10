#include "SalaryTotalTableModel.h"

int SalaryTotalTableModel::maxId = 1;

SalaryTotalTableModel::SalaryTotalTableModel( QObject *parent ) { this->id = SalaryTotalTableModel::maxId++; }

SalaryTotalTableModel::~SalaryTotalTableModel( void ) {}

//===OVERRIDE===//
int SalaryTotalTableModel::rowCount( const QModelIndex &parent ) const {
    Q_UNUSED( parent )
    return table.count();
}

int SalaryTotalTableModel::columnCount( const QModelIndex &parent ) const {
    Q_UNUSED( parent )
    return COLUMN_LAST;
}

QVariant SalaryTotalTableModel::headerData( int section, Qt::Orientation orientation, int role ) const {
    if ( role != Qt::DisplayRole ) {
        return QVariant();
    }

    if ( orientation == Qt::Vertical ) {
        return section;
    }

    switch ( section ) {
    case COLUMN_ID:
        return toUnicode( "id" );
    case COLUMN_EMPTY:
        return QString::fromWCharArray( L"" );
    case COLUMN_ALL_INCOME:
        return QString::fromWCharArray( L"С продаж" );
    case COLUMN_ALL_SALARY:
        return QString::fromWCharArray( L"Зарплата" );
    }

    return QVariant();
}

QVariant SalaryTotalTableModel::data( const QModelIndex &index, int role ) const {
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

int SalaryTotalTableModel::getRecordId( int row ) {
    int id = -1;

    if ( row >= 0 && row < this->table.size() ) {

        id = this->table.at( row ).at( COLUMN_ID ).value<int>();
    }

    return id;
}

QModelIndex SalaryTotalTableModel::getIndexByRecordId( int id ) {

    QModelIndex index;

    for ( int iRow = 0; iRow < this->table.size(); iRow++ ) {

        if ( this->table.at( iRow ).at( COLUMN_ID ) == id ) {

            index = this->createIndex( iRow, COLUMN_ID );
        }
    }

    return index;
}

void SalaryTotalTableModel::refreshData( const QList<ManagerSalaryDTO> &data ) {

    if ( table.size() > 0 ) {
        this->beginRemoveRows( QModelIndex(), 0, table.size() - 1 );

        this->table.clear();

        this->endRemoveRows();
    }

    //сложить в одну строчку
    if ( data.size() > 0 ) {
        this->beginInsertRows( QModelIndex(), 0, 0 );
        QList<QVariant> row;
        double allIncome = 0;
        double allSalary = 0;

        for ( int i = 0; i < data.size(); i++ ) {

            const ManagerSalaryDTO &el = data[i];

            allIncome += el.income;
            allSalary += el.salary;
        }

        row << 0;
        row << QString::fromWCharArray( L"Итого:" );
        row << allIncome;
        row << allSalary;

        this->table.append( row );

        this->endInsertRows();
    }
}