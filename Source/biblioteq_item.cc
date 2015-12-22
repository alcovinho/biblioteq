/*
** -- Qt Includes --
*/

#include <QComboBox>
#include <QDateEdit>
#include <QLineEdit>
#include <QSpinBox>
#include <QTextEdit>
#include <QTimeEdit>

/*
** -- Local Includes --
*/

#include "biblioteq_hyperlinked_text_edit.h"
#include "biblioteq_item.h"

/*
** -- biblioteq_item() --
*/

biblioteq_item::biblioteq_item(void)
{
  row = -1;
  oldq = -1;
  isQueryEnabled = false;
  parentWid = 0;
}

/*
** -- biblioteq_item() --
*/

biblioteq_item::biblioteq_item(const int rowArg)
{
  row = rowArg;
  oldq = -1;
  isQueryEnabled = false;
  parentWid = 0;
}

/*
** -- ~biblioteq_item() --
*/

biblioteq_item::~biblioteq_item()
{
  imageValues.clear();
  widgetValues.clear();
}

/*
** -- getRow() --
*/

int biblioteq_item::getRow(void) const
{
  return row;
}

/*
** -- getOldQ() --
*/

int biblioteq_item::getOldQ(void) const
{
  return oldq;
}

/*
** -- updateRow() --
*/

void biblioteq_item::updateRow(const int rowArg)
{
  row = rowArg;
}

/*
** -- getID() --
*/

QString biblioteq_item::getID(void) const
{
  return oid;
}

/*
** -- print() --
*/

void biblioteq_item::print(QWidget *parent)
{
  QPrinter printer;
  QPrintDialog dialog(&printer, parent);
  QTextDocument document;

#ifdef Q_OS_MAC
#if QT_VERSION < 0x050000
  dialog.setAttribute(Qt::WA_MacMetalStyle, true);
#endif
#endif
  printer.setPageSize(QPrinter::Letter);
  printer.setColorMode(QPrinter::GrayScale);

  if(dialog.exec() == QDialog::Accepted)
    {
      document.setHtml(html);
      document.print(&printer);
    }
}

/*
** -- updateFont() --
*/

void biblioteq_item::updateFont(const QFont &font, QWidget *window)
{
  if(!window)
    return;

  window->setFont(font);

  foreach(QWidget *widget, window->findChildren<QWidget *>())
    widget->setFont(font);
}

/*
** -- setOldQ() --
*/

void biblioteq_item::setOldQ(const int q)
{
  oldq = q;
}

/*
** -- storeData() --
*/

void biblioteq_item::storeData(QMainWindow *window)
{
  if(!window)
    return;

  QString classname = "";
  QString objectname = "";

  imageValues.clear();
  widgetValues.clear();

  foreach(QWidget *widget, window->findChildren<QWidget *>())
    {
      classname = widget->metaObject()->className();
      objectname = widget->objectName();

      if(classname == "QSpinBox")
	widgetValues[objectname] =
	  (qobject_cast<QSpinBox *> (widget))->text().trimmed();
      else if(classname == "QLineEdit")
	widgetValues[objectname] =
	  (qobject_cast<QLineEdit *> (widget))->text().trimmed();
      else if(classname == "QComboBox")
	widgetValues[objectname] =
	  (qobject_cast<QComboBox *> (widget))->currentText().trimmed();
      else if(classname == "QDateEdit")
	widgetValues[objectname] =
	  (qobject_cast<QDateEdit *> (widget))->date().toString("MM/dd/yyyy");
      else if(classname == "QTextEdit")
	widgetValues[objectname] =
	  (qobject_cast<QTextEdit *> (widget))->toPlainText().trimmed();
      else if(classname == "QDoubleSpinBox")
	widgetValues[objectname] =
	  (qobject_cast<QDoubleSpinBox *> (widget))->text().trimmed();
      else if(classname == "QTimeEdit")
	widgetValues[objectname] =
	  (qobject_cast<QTimeEdit *> (widget))->text().trimmed();
      else if(classname == "biblioteq_hyperlinked_text_edit")
	widgetValues[objectname] =
	  (qobject_cast<biblioteq_hyperlinked_text_edit *> (widget))->
	  toPlainText().
	  trimmed();
      else if(classname == "biblioteq_image_drop_site")
	imageValues[objectname] =
	  (qobject_cast<biblioteq_image_drop_site *> (widget))->image;
    }
}

/*
** -- hasDataChanged() --
*/

bool biblioteq_item::hasDataChanged(QMainWindow *window) const
{
  if(!window)
    return false;

  int i = 0;
  bool hasChanged = false;
  QString classname = "";
  QString objectname = "";
  QMap<QString, QImage> newimg;
  QMap<QString, QString> newdata;

  foreach(QWidget *widget, window->findChildren<QWidget *>())
    {
      classname = widget->metaObject()->className();
      objectname = widget->objectName();

      if(classname == "QSpinBox")
	newdata[objectname] =
	  (qobject_cast<QSpinBox *> (widget))->text().trimmed();
      else if(classname == "QLineEdit")
	newdata[objectname] =
	  (qobject_cast<QLineEdit *> (widget))->text().trimmed();
      else if(classname == "QComboBox")
	newdata[objectname] =
	  (qobject_cast<QComboBox *> (widget))->currentText().
	  trimmed();
      else if(classname == "QDateEdit")
	newdata[objectname] =
	  (qobject_cast<QDateEdit *> (widget))->date().toString
	  ("MM/dd/yyyy");
      else if(classname == "QTextEdit")
	newdata[objectname] =
	  (qobject_cast<QTextEdit *> (widget))->toPlainText().trimmed();
      else if(classname == "QDoubleSpinBox")
	newdata[objectname] =
	  (qobject_cast<QDoubleSpinBox *> (widget))->text().trimmed();
      else if(classname == "QTimeEdit")
	newdata[objectname] =
	  (qobject_cast<QTimeEdit *> (widget))->text().trimmed();
      else if(classname == "biblioteq_hyperlinked_text_edit")
	newdata[objectname] =
	  (qobject_cast<biblioteq_hyperlinked_text_edit *> (widget))->
	  toPlainText().trimmed();
      else if(classname == "biblioteq_image_drop_site")
	newimg[objectname] =
	  (qobject_cast<biblioteq_image_drop_site *> (widget))->image;
    }

  for(i = 0; i < widgetValues.size(); i++)
    if(widgetValues[widgetValues.keys()[i]] != newdata[widgetValues.keys()[i]])
      {
	hasChanged = true;
	break;
      }

  if(!hasChanged)
    for(i = 0; i < imageValues.size(); i++)
      if(imageValues[imageValues.keys()[i]] != newimg[imageValues.keys()[i]])
	{
	  hasChanged = true;
	  break;
	}

  newimg.clear();
  newdata.clear();
  return hasChanged;
}