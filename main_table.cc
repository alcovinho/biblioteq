/*
** -- Qt Includes --
*/

#include <QtDebug>

/*
** -- Local Includes --
*/

#include "main_table.h"

/*
** -- main_table() --
*/

main_table::main_table(QWidget *parent):QTableWidget(parent)
{
  setDragEnabled(false);
  setAcceptDrops(false);
  horizontalHeader()->setMovable(true);
  horizontalHeader()->setSortIndicator(0, Qt::AscendingOrder);
  horizontalHeader()->setSortIndicatorShown(true);
  horizontalHeader()->setStretchLastSection(true);
  verticalHeader()->setResizeMode(QHeaderView::Fixed);
}

/*
** -- setColumns() --
*/

void main_table::setColumns(const QString &username,
			    const QString &type, const QString &roles)
{
  QStringList list;

  m_columnHeaderIndexes.clear();

  if(type == "All" ||
     type == "All Available" ||
     type == "All Overdue" ||
     type == "All Requested" ||
     type == "All Reserved")
    {
      if(type == "All Overdue" || type == "All Reserved")
	{
	  if(!roles.isEmpty())
	    {
	      list.append(tr("Borrower"));
	      list.append(tr("Member ID"));
	      m_columnHeaderIndexes.append("Borrower");
	      m_columnHeaderIndexes.append("Member ID");
	    }

	  list.append(tr("Barcode"));
	  list.append(tr("Reservation Date"));
	  list.append(tr("Due Date"));
	  m_columnHeaderIndexes.append("Barcode");
	  m_columnHeaderIndexes.append("Reservation Date");
	  m_columnHeaderIndexes.append("Due Date");
	}
      else if(type == "All Requested")
	{
	  if(!roles.isEmpty())
	    {
	      list.append(tr("Borrower"));
	      list.append(tr("Member ID"));
	      m_columnHeaderIndexes.append("Borrower");
	      m_columnHeaderIndexes.append("Member ID");
	    }

	  list.append(tr("Request Date"));
	  m_columnHeaderIndexes.append("Request Date");
	}

      list.append(tr("Title"));
      list.append(tr("ID Number"));
      list.append(tr("Publisher"));
      list.append(tr("Publication Date"));
      list.append(tr("Categories"));
      list.append(tr("Language"));
      list.append(tr("Price"));
      list.append(tr("Monetary Units"));
      list.append(tr("Quantity"));
      list.append(tr("Location"));
      m_columnHeaderIndexes.append("Title");
      m_columnHeaderIndexes.append("ID Number");
      m_columnHeaderIndexes.append("Publisher");
      m_columnHeaderIndexes.append("Publication Date");
      m_columnHeaderIndexes.append("Categories");
      m_columnHeaderIndexes.append("Language");
      m_columnHeaderIndexes.append("Price");
      m_columnHeaderIndexes.append("Monetary Units");
      m_columnHeaderIndexes.append("Quantity");
      m_columnHeaderIndexes.append("Location");

      if(type != "All Requested")
	{
	  list.append(tr("Availability"));
	  list.append(tr("Total Reserved"));
	  m_columnHeaderIndexes.append("Availability");
	  m_columnHeaderIndexes.append("Total Reserved");
	}

      list.append(tr("Type"));
      list.append("MYOID");
      m_columnHeaderIndexes.append("Type");
      m_columnHeaderIndexes.append("MYOID");

      if(type == "All Requested")
	{
	  list.append("REQUESTOID");
	  m_columnHeaderIndexes.append("REQUESTOID");
	}
    }
  else if(type == "Books")
    {
      list.append(tr("Title"));
      list.append(tr("Author(s)"));
      list.append(tr("Publisher"));
      list.append(tr("Publication Date"));
      list.append(tr("Place of Publication"));
      list.append(tr("Edition"));
      list.append(tr("Categories"));
      list.append(tr("Language"));
      list.append(tr("ISBN-10"));
      list.append(tr("Price"));
      list.append(tr("Monetary Units"));
      list.append(tr("Quantity"));
      list.append(tr("Book Binding Type"));
      list.append(tr("Location"));
      list.append(tr("ISBN-13"));
      list.append(tr("LC Control Number"));
      list.append(tr("Call Number"));
      list.append(tr("Dewey Class Number"));
      list.append(tr("Availability"));
      list.append(tr("Total Reserved"));
      list.append(tr("Type"));
      list.append("MYOID");
      m_columnHeaderIndexes.append("Title");
      m_columnHeaderIndexes.append("Author(s)");
      m_columnHeaderIndexes.append("Publisher");
      m_columnHeaderIndexes.append("Publication Date");
      m_columnHeaderIndexes.append("Place of Publication");
      m_columnHeaderIndexes.append("Edition");
      m_columnHeaderIndexes.append("Categories");
      m_columnHeaderIndexes.append("Language");
      m_columnHeaderIndexes.append("ISBN-10");
      m_columnHeaderIndexes.append("Price");
      m_columnHeaderIndexes.append("Monetary Units");
      m_columnHeaderIndexes.append("Quantity");
      m_columnHeaderIndexes.append("Book Binding Type");
      m_columnHeaderIndexes.append("Location");
      m_columnHeaderIndexes.append("ISBN-13");
      m_columnHeaderIndexes.append("LC Control Number");
      m_columnHeaderIndexes.append("Call Number");
      m_columnHeaderIndexes.append("Dewey Class Number");
      m_columnHeaderIndexes.append("Availability");
      m_columnHeaderIndexes.append("Total Reserved");
      m_columnHeaderIndexes.append("Type");
      m_columnHeaderIndexes.append("MYOID");
    }
  else if(type == "DVDs")
    {
      list.append(tr("Title"));
      list.append(tr("Format"));
      list.append(tr("Studio"));
      list.append(tr("Release Date"));
      list.append(tr("Number of Discs"));
      list.append(tr("Runtime"));
      list.append(tr("Categories"));
      list.append(tr("Language"));
      list.append(tr("UPC"));
      list.append(tr("Price"));
      list.append(tr("Monetary Units"));
      list.append(tr("Quantity"));
      list.append(tr("Location"));
      list.append(tr("Rating"));
      list.append(tr("Region"));
      list.append(tr("Aspect Ratio"));
      list.append(tr("Availability"));
      list.append(tr("Total Reserved"));
      list.append(tr("Type"));
      list.append("MYOID");
      m_columnHeaderIndexes.append("Title");
      m_columnHeaderIndexes.append("Format");
      m_columnHeaderIndexes.append("Studio");
      m_columnHeaderIndexes.append("Release Date");
      m_columnHeaderIndexes.append("Number of Discs");
      m_columnHeaderIndexes.append("Runtime");
      m_columnHeaderIndexes.append("Categories");
      m_columnHeaderIndexes.append("Language");
      m_columnHeaderIndexes.append("UPC");
      m_columnHeaderIndexes.append("Price");
      m_columnHeaderIndexes.append("Monetary Units");
      m_columnHeaderIndexes.append("Quantity");
      m_columnHeaderIndexes.append("Location");
      m_columnHeaderIndexes.append("Rating");
      m_columnHeaderIndexes.append("Region");
      m_columnHeaderIndexes.append("Aspect Ratio");
      m_columnHeaderIndexes.append("Availability");
      m_columnHeaderIndexes.append("Total Reserved");
      m_columnHeaderIndexes.append("Type");
      m_columnHeaderIndexes.append("MYOID");
    }
  else if(type == "Journals" || type == "Magazines")
    {
      list.append(tr("Title"));
      list.append(tr("Publisher"));
      list.append(tr("Publication Date"));
      list.append(tr("Place of Publication"));
      list.append(tr("Volume"));
      list.append(tr("Issue"));
      list.append(tr("Categories"));
      list.append(tr("Language"));
      list.append(tr("ISSN"));
      list.append(tr("Price"));
      list.append(tr("Monetary Units"));
      list.append(tr("Quantity"));
      list.append(tr("Location"));
      list.append(tr("LC Control Number"));
      list.append(tr("Call Number"));
      list.append(tr("Dewey Number"));
      list.append(tr("Availability"));
      list.append(tr("Total Reserved"));
      list.append(tr("Type"));
      list.append("MYOID");
      m_columnHeaderIndexes.append("Title");
      m_columnHeaderIndexes.append("Publisher");
      m_columnHeaderIndexes.append("Publication Date");
      m_columnHeaderIndexes.append("Place of Publication");
      m_columnHeaderIndexes.append("Volume");
      m_columnHeaderIndexes.append("Issue");
      m_columnHeaderIndexes.append("Categories");
      m_columnHeaderIndexes.append("Language");
      m_columnHeaderIndexes.append("ISSN");
      m_columnHeaderIndexes.append("Price");
      m_columnHeaderIndexes.append("Monetary Units");
      m_columnHeaderIndexes.append("Quantity");
      m_columnHeaderIndexes.append("Location");
      m_columnHeaderIndexes.append("LC Control Number");
      m_columnHeaderIndexes.append("Call Number");
      m_columnHeaderIndexes.append("Dewey Number");
      m_columnHeaderIndexes.append("Availability");
      m_columnHeaderIndexes.append("Total Reserved");
      m_columnHeaderIndexes.append("Type");
      m_columnHeaderIndexes.append("MYOID");
    }
  else if(type == "Music CDs")
    {
      list.append(tr("Title"));
      list.append(tr("Artist"));
      list.append(tr("Format"));
      list.append(tr("Recording Label"));
      list.append(tr("Release Date"));
      list.append(tr("Number of Discs"));
      list.append(tr("Runtime"));
      list.append(tr("Categories"));
      list.append(tr("Language"));
      list.append(tr("Catalog Number"));
      list.append(tr("Price"));
      list.append(tr("Monetary Units"));
      list.append(tr("Quantity"));
      list.append(tr("Location"));
      list.append(tr("Audio"));
      list.append(tr("Recording Type"));
      list.append(tr("Availability"));
      list.append(tr("Total Reserved"));
      list.append(tr("Type"));
      list.append("MYOID");
      m_columnHeaderIndexes.append("Title");
      m_columnHeaderIndexes.append("Artist");
      m_columnHeaderIndexes.append("Format");
      m_columnHeaderIndexes.append("Recording Label");
      m_columnHeaderIndexes.append("Release Date");
      m_columnHeaderIndexes.append("Number of Discs");
      m_columnHeaderIndexes.append("Runtime");
      m_columnHeaderIndexes.append("Categories");
      m_columnHeaderIndexes.append("Language");
      m_columnHeaderIndexes.append("Catalog Number");
      m_columnHeaderIndexes.append("Price");
      m_columnHeaderIndexes.append("Monetary Units");
      m_columnHeaderIndexes.append("Quantity");
      m_columnHeaderIndexes.append("Location");
      m_columnHeaderIndexes.append("Audio");
      m_columnHeaderIndexes.append("Recording Type");
      m_columnHeaderIndexes.append("Availability");
      m_columnHeaderIndexes.append("Total Reserved");
      m_columnHeaderIndexes.append("Type");
      m_columnHeaderIndexes.append("MYOID");
    }
  else if(type == "Photograph Collections")
    {
      list.append(tr("Title"));
      list.append(tr("ID"));
      list.append(tr("About"));
      list.append(tr("Type"));
      list.append("MYOID");
      m_columnHeaderIndexes.append("Title");
      m_columnHeaderIndexes.append("ID");
      m_columnHeaderIndexes.append("About");
      m_columnHeaderIndexes.append("Type");
      m_columnHeaderIndexes.append("MYOID");
    }
  else if(type == "Video Games")
    {
      list.append(tr("Title"));
      list.append(tr("Game Rating"));
      list.append(tr("Platform"));
      list.append(tr("Mode"));
      list.append(tr("Publisher"));
      list.append(tr("Release Date"));
      list.append(tr("Place of Publication"));
      list.append(tr("Genres"));
      list.append(tr("Language"));
      list.append(tr("UPC"));
      list.append(tr("Price"));
      list.append(tr("Monetary Units"));
      list.append(tr("Quantity"));
      list.append(tr("Location"));
      list.append(tr("Availability"));
      list.append(tr("Total Reserved"));
      list.append(tr("Type"));
      list.append("MYOID");
      m_columnHeaderIndexes.append("Title");
      m_columnHeaderIndexes.append("Game Rating");
      m_columnHeaderIndexes.append("Platform");
      m_columnHeaderIndexes.append("Mode");
      m_columnHeaderIndexes.append("Publisher");
      m_columnHeaderIndexes.append("Release Date");
      m_columnHeaderIndexes.append("Place of Publication");
      m_columnHeaderIndexes.append("Genres");
      m_columnHeaderIndexes.append("Language");
      m_columnHeaderIndexes.append("UPC");
      m_columnHeaderIndexes.append("Price");
      m_columnHeaderIndexes.append("Monetary Units");
      m_columnHeaderIndexes.append("Quantity");
      m_columnHeaderIndexes.append("Location");
      m_columnHeaderIndexes.append("Availability");
      m_columnHeaderIndexes.append("Total Reserved");
      m_columnHeaderIndexes.append("Type");
      m_columnHeaderIndexes.append("MYOID");
    }

  setColumnCount(list.size());
  setHorizontalHeaderLabels(list);

  if(type != "All" &&
     type != "All Available" &&
     type != "All Overdue" &&
     type != "All Requested" &&
     type != "All Reserved")
    {
      /*
      ** Hide the Type and MYOID columns.
      */

      setColumnHidden(list.size() - 1, true);
      setColumnHidden(list.size() - 2, true);
    }
  else
    {
      /*
      ** Hide the MYOID and REQUESTOID columns.
      */

      setColumnHidden(list.size() - 1, true);

      if(type == "All Requested")
	setColumnHidden(list.size() - 2, true);
    }

  list.clear();

  QString l_type(type);
  QString indexstr("");

  indexstr.append(username);
  indexstr.append(l_type.replace(" ", "_"));
  indexstr.append("_header_state");

  for(int i = 0; i < hiddenColumns[indexstr].size(); i++)
    setColumnHidden(hiddenColumns[indexstr][i], true);
}

/*
** -- resetTable() --
*/

void main_table::resetTable(const QString &username, const QString &type,
			    const QString &roles)
{
  clear();
  setRowCount(0);
  setColumnCount(0);
  scrollToTop();
  horizontalScrollBar()->setValue(0);

  if(!type.isEmpty())
    setColumns(username, type, roles);

  horizontalHeader()->setSortIndicator(0, Qt::AscendingOrder);
  horizontalHeader()->setSortIndicatorShown(true);
  resizeColumnsToContents();
  horizontalHeader()->setStretchLastSection(true);
  clearSelection();
  setCurrentItem(0);
}

/*
** -- recordColumnHidden() --
*/

void main_table::recordColumnHidden(const QString &username,
				    const QString &type, const int index,
				    const bool hidden)
{
  QString l_type(type);
  QString indexstr("");

  indexstr.append(username);
  indexstr.append(l_type.replace(" ", "_"));
  indexstr.append("_header_state");

  if(hidden)
    {
      if(!hiddenColumns[indexstr].contains(index))
	hiddenColumns[indexstr].append(index);
    }
  else
    (int) hiddenColumns[indexstr].removeAll(index);
}

/*
** -- friendlyStates() --
*/

QHash<QString, QString> main_table::friendlyStates(void) const
{
  QHash<QString, QString> states;

  for(int i = 0; i < hiddenColumns.keys().size(); i++)
    {
      QString state("");

      for(int j = 0; j < hiddenColumns[hiddenColumns.keys().at(i)].size();
	  j++)
	state += QString::number
	  (hiddenColumns[hiddenColumns.keys().at(i)].at(j)).append(",");

      if(state.endsWith(","))
	state = state.mid(0, state.length() - 1);

      states[hiddenColumns.keys().at(i)] = state;
    }

  return states;
}

/*
** -- parseStates() --
*/

void main_table::parseStates(const QHash<QString, QString> &states)
{
  for(int i = 0; i < states.keys().size(); i++)
    {
      QList<int> intList;
      QStringList strList
	(states[states.keys().at(i)].split(",",
					   QString::SkipEmptyParts));

      for(int j = 0; j < strList.size(); j++)
	if(strList.at(j).toInt() >= 0)
	  intList.append(strList.at(j).toInt());

      hiddenColumns[states.keys().at(i)] = intList;
    }
}

/*
** -- columnNumber() --
*/

int main_table::columnNumber(const QString &name)
{
  return m_columnHeaderIndexes.indexOf(name);
}

/*
** -- columnNames() --
*/

QStringList main_table::columnNames(void) const
{
  return m_columnHeaderIndexes.toList();
}
