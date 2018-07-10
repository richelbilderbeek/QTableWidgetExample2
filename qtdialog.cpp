#include "qtdialog.h"
#include <boost/lexical_cast.hpp>

#include "ui_qtdialog.h"

QtDialog::QtDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QtDialog)
{
  ui->setupUi(this);

  QTableWidget * const t = ui->tableWidget;
  t->setRowCount(10);
  const int n_rows = t->rowCount();
  const int n_cols = t->columnCount();
  for (int col=0; col!=n_cols; ++col)
  {
    for (int row=0; row!=n_rows; ++row)
    {
      QTableWidgetItem * const i = new QTableWidgetItem;
      if (col != 3)
      {
        //Checkbox
        i->setFlags(
            Qt::ItemIsSelectable
          | Qt::ItemIsUserCheckable
        );
        i->setCheckState(Qt::Unchecked);
      }
      else
      {
        //Text
        i->setFlags(
            Qt::ItemIsSelectable
          | Qt::ItemIsEditable
          | Qt::ItemIsEnabled);
        const QString s = "("
          + QString::number(col)
          + ","
          + QString::number(row)
          + ")"
        ;
        i->setText(s);
      }
      t->setItem(row, col, i);
    }
  }
  t->setColumnWidth(0,24);
  t->setColumnWidth(1,24);
  t->setColumnWidth(2,24);
}

QtDialog::~QtDialog()
{
  delete ui;
}
