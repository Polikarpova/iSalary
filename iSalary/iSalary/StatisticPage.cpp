#include "StatisticPage.h"
#include <QTextCharFormat>

StatisticPage::StatisticPage( SalesFacade *salesFacade ) { this->salesFacade = salesFacade; }

StatisticPage::~StatisticPage( void ) {}

void StatisticPage::refreshPage() {

    this->updateStatisticTable();
    this->updateStatisticSalesTable();
    this->clearCalendar();
}

void StatisticPage::setErrorHandler( ErrorMessageHandler *errorHandler ) { this->errorHandler = errorHandler; }

void StatisticPage::setUI( QTabWidget *tabWidget, QPushButton *statisticForAllButton, QDateEdit *statisticMonth, QTableView *statisticTable,
                           QTableView *statisticSalesTable, QCalendarWidget *statisticCalendar ) {

    this->tabWidget = tabWidget;
    this->statisticForAllButton = statisticForAllButton;
    connect( this->statisticForAllButton, &QPushButton::clicked, this, &StatisticPage::showForAll );

    this->statisticMonth = statisticMonth;
    this->statisticCalendar = statisticCalendar;
	this->statisticCalendar->setSelectedDate( this->statisticCalendar->minimumDate() );
	this->statisticCalendar->setCurrentPage( QDate::currentDate().year(), QDate::currentDate().month());
    this->statisticMonth->setDate( QDate::currentDate() );
    connect( this->statisticMonth, &QDateEdit::dateChanged, this, &StatisticPage::monthChanged );

    this->initStatisticTable( statisticTable );
    this->initStatisticSalesTable( statisticSalesTable );

    this->refreshPage();
}

void StatisticPage::initStatisticTable( QTableView *statisticTable ) {

    this->statisticTable = statisticTable;
    auto model = new StatisticTableModel();
    this->statisticTable->setModel( model );

    this->statisticTable->horizontalHeader()->setStretchLastSection( true );
    this->statisticTable->horizontalHeader()->setSectionResizeMode( StatisticTableModel::COLUMN_FIO, QHeaderView::ResizeToContents );
    this->statisticTable->horizontalHeader()->setSectionResizeMode( StatisticTableModel::COLUMN_SALES_COUNT, QHeaderView::ResizeToContents );
    this->statisticTable->horizontalHeader()->setSectionResizeMode( StatisticTableModel::COLUMN_INCOME, QHeaderView::ResizeToContents );
    this->statisticTable->horizontalHeader()->setSectionResizeMode( StatisticTableModel::COLUMN_LET, QHeaderView::ResizeToContents );
    this->statisticTable->horizontalHeader()->setSectionResizeMode( StatisticTableModel::COLUMN_OET, QHeaderView::ResizeToContents );
    this->statisticTable->setSelectionBehavior( QAbstractItemView::SelectRows );
    this->statisticTable->setSelectionMode( QAbstractItemView::SingleSelection );

    //скрытие поля с id
    this->statisticTable->setColumnHidden( StatisticTableModel::COLUMN_ID, true );

    connect( this->statisticTable, &QTableView::clicked, this, &StatisticPage::showManagersStatistic );
}

void StatisticPage::initStatisticSalesTable( QTableView *statisticSalesTable ) {

    this->statisticSalesTable = statisticSalesTable;
    auto model = new StatisticSalesTableModel();
    this->statisticSalesTable->setModel( model );

    this->statisticSalesTable->horizontalHeader()->setStretchLastSection( true );
    this->statisticSalesTable->horizontalHeader()->setSectionResizeMode( StatisticSalesTableModel::COLUMN_FIO, QHeaderView::ResizeToContents );
    this->statisticSalesTable->horizontalHeader()->setSectionResizeMode( StatisticSalesTableModel::COLUMN_SALE_DATE, QHeaderView::ResizeToContents );
    this->statisticSalesTable->horizontalHeader()->setSectionResizeMode( StatisticSalesTableModel::COLUMN_COUNT, QHeaderView::ResizeToContents );
    this->statisticSalesTable->horizontalHeader()->setSectionResizeMode( StatisticSalesTableModel::COLUMN_NAME, QHeaderView::ResizeToContents );
    this->statisticSalesTable->horizontalHeader()->setSectionResizeMode( StatisticSalesTableModel::COLUMN_PRICE, QHeaderView::ResizeToContents );
    this->statisticSalesTable->horizontalHeader()->setSectionResizeMode( StatisticSalesTableModel::COLUMN_COMMISION, QHeaderView::ResizeToContents );
    this->statisticSalesTable->setSelectionBehavior( QAbstractItemView::SelectRows );
    this->statisticSalesTable->setSelectionMode( QAbstractItemView::SingleSelection );

    //скрытие поля с id
    this->statisticSalesTable->setColumnHidden( StatisticTableModel::COLUMN_ID, true );
}

void StatisticPage::updateStatisticTable() {

    QList<ManagerStatisticDTO> list;

    try {
        QDate current( statisticMonth->date() );
        QDate dateFrom( current.year(), current.month(), 1 );
        QDate dateTo( current.year(), current.month(), current.daysInMonth() );
        list = this->salesFacade->getManagersStatistic( dateFrom, dateTo );
    } catch ( QString *error ) {
    }

    //чистим Qhash
    this->managerStatistic.clear();
    //заполняем его новыми данными из бд
    for ( auto i = list.begin(); i != list.end(); i++ ) {

        this->managerStatistic.insert( i->managerId, *i );
    }

    //инициализируем и заполняем модель
    StatisticTableModel *model = static_cast<StatisticTableModel *>( this->statisticTable->model() );
    model->refreshData( list );
}

void StatisticPage::updateStatisticSalesTable() {

    // id всех менеджеров
    QList<int> ids;

    for ( auto i = this->managerStatistic.begin(); i != this->managerStatistic.end(); i++ ) {

        ids.append( i.key() );
    }

    QList<ActiveSaleDTO> list;

    try {
        QDate current( statisticMonth->date() );
        QDate dateFrom( current.year(), current.month(), 1 );
        QDate dateTo( current.year(), current.month(), current.daysInMonth() );
        list = this->salesFacade->getConfirmedSalesSoldFromPeriod( ids, dateFrom, dateTo );
    } catch ( QString *error ) {
    }

    //чистим Qhash
    this->confirmedSales.clear();
    //заполняем его новыми данными из бд
    for ( auto i = list.begin(); i != list.end(); i++ ) {

        this->confirmedSales.insert( i->id, *i );
    }

    //инициализируем и заполняем модель
    StatisticSalesTableModel *model = static_cast<StatisticSalesTableModel *>( this->statisticSalesTable->model() );
    model->refreshData( list );
}

void StatisticPage::viewSelectedManagerStatisticSales( int id ) {

    // id выбранного менеджера
    QList<int> ids;
    ids.append( id );

    QList<ActiveSaleDTO> list;

    try {
        QDate current( statisticMonth->date() );
        QDate dateFrom( current.year(), current.month(), 1 );
        QDate dateTo( current.year(), current.month(), current.daysInMonth() );
        list = this->salesFacade->getConfirmedSalesSoldFromPeriod( ids, dateFrom, dateTo );
    } catch ( QString *error ) {
    }

    //чистим Qhash
    this->confirmedSales.clear();
    //заполняем его новыми данными из бд
    for ( auto i = list.begin(); i != list.end(); i++ ) {

        this->confirmedSales.insert( i->id, *i );
    }

    //инициализируем и заполняем модель
    StatisticSalesTableModel *model = static_cast<StatisticSalesTableModel *>( this->statisticSalesTable->model() );
    model->refreshData( list );
}

//===SLOTS===//
void StatisticPage::monthChanged() {

    this->setEnable( false );

    this->refreshPage();
    this->statisticCalendar->setCurrentPage( this->statisticMonth->date().year(), this->statisticMonth->date().month() );

    this->setEnable( true );
}

void StatisticPage::showManagersStatistic() {

    this->setEnable( false );

    int currentId = this->getSelectedManagerId();
    this->viewSelectedManagerStatisticSales( currentId );
    this->paintCalendar();

    this->setEnable( true );
}

void StatisticPage::showForAll() {

    this->setEnable( false );

    this->refreshPage();

    this->setEnable( true );
}

//===PRIVATE===//
void StatisticPage::setEnable( bool flag ) { this->tabWidget->setEnabled( flag ); }

int StatisticPage::getSelectedManagerId() {

    auto model = static_cast<StatisticTableModel *>( this->statisticTable->model() );
    return model->getRecordId( this->statisticTable->currentIndex().row() );
}

void StatisticPage::paintCalendar() {

    this->clearCalendar();

    if ( !this->confirmedSales.empty() ) {

        //создать карту день-прибыль и общую прибыль за месяц
        double allIncome = 0;
        QMap<QDate, double> map;

        for ( auto i = this->confirmedSales.begin(); i != this->confirmedSales.end(); i++ ) {

            map[i->saleDate] += i->price * i->count;
            allIncome += i->price * i->count;
        }

        //цикл по дням, где окрашиваем
        QBrush brush;
        QColor color;
        for ( auto i = map.begin(); i != map.end(); i++ ) {

            int index = 255 - ( 255 * i.value() / allIncome );
            color.setRgb( index, 255, index );
            QTextCharFormat format = this->statisticCalendar->dateTextFormat( i.key() );
            brush.setColor( color );
            format.setBackground( brush );
            this->statisticCalendar->setDateTextFormat( i.key(), format );
        }
    }
}

void StatisticPage::clearCalendar() {

    QMap<QDate, QTextCharFormat> map = this->statisticCalendar->dateTextFormat();

    for ( auto day = map.begin(); day != map.end(); day++ ) {

        QTextCharFormat format( this->statisticCalendar->dateTextFormat( day.key() ) );

        format.setBackground( Qt::white );
        this->statisticCalendar->setDateTextFormat( day.key(), format );
    }
}
