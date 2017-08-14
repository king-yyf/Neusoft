#include "ordermachine.h"
#include "ui_ordermachine.h"

void ordermachine::initData(){
    QSqlTableModel *model = new QSqlTableModel;
    model->setTable("dishes");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->show();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->hideColumn(1);
    ui->tableView->hideColumn(2);
}
