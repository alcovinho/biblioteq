#include "generic_thread.h"

extern qtbook *qmain;

/*
** -- generic_thread() --
*/

generic_thread::generic_thread(void)
{
  type = -1;
  eType = "";
  errorStr = "";
  list.clear();
  outputListBool.clear();
}

/*
** -- ~generic_thread() --
*/

generic_thread::~generic_thread()
{
  list.clear();
  LOCResults.clear();
}

/*
** -- run() --
*/

void generic_thread::run(void)
{
  /*
  ** Some of this could have been implemented with Qt signals.
  */

  switch(type)
    {
    case READ_USER_CONFIG_FILE:
      {
	QFile qf;
	myqstring str = "";
	QTextStream qts;

	qf.setFileName(filename);

	if(!qf.open(QIODevice::ReadOnly))
	  {
	    errorStr = "Unable to read ";
	    errorStr.append(filename);
	    errorStr.append(". This file may not yet exist. If you wish to "
			    "create it, "
			    "please choose the Save Options selection that "
			    "is located in the Options menu.");
	    return;
	  }

	qts.setDevice(&qf);

	while(!qts.atEnd())
	  {
	    str = str.prepConfigString(qts.readLine().trimmed());
	    list.append(str);
	  }

	qf.close();
	break;
      }
    case WRITE_USER_CONFIG_FILE:
      {
	QFile qf;
	QTextStream qts;

	qf.setFileName(filename);

	if(!qf.open(QIODevice::WriteOnly))
	  {
	    errorStr = "Unable to save the configuration settings ";
	    errorStr.append("to ");
	    errorStr.append(filename);
	    errorStr.append(".");
	    return;
	  }

	qts.setDevice(&qf);
	qts << "# Please do not edit this file!" << endl;
	qts << "show_table_grid=";
	qts << outputListBool.takeFirst() << endl;
	qts << "populate_table_on_connect=";
	qts << outputListBool.takeFirst() << endl;
	qts << "automatically_resize_columns=";
	qts << outputListBool.takeFirst() << endl;
	qts << "automatically_populate_on_filter=";
	qts << outputListBool.takeFirst() << endl;
	qts << "reset_error_log_on_disconnect=";
	qts << outputListBool.takeFirst() << endl;
	qts << "automatically_populate_on_create=";
	qts << outputListBool.takeFirst() << endl;
	qts << "main_window_geometry=" << qmain->getGeometryString() << endl;
	qts << "global_font=" << qmain->font().toString() << endl;
	qf.close();
	break;
      }
    case READ_GLOBAL_CONFIG_FILE:
      {
	QFile qf;
	myqstring str = "";
	QTextStream qts;

	qf.setFileName(filename);

	if(!qf.open(QIODevice::ReadOnly))
	  {
	    errorStr = "Unable to read ";
	    errorStr.append(filename);
	    errorStr.append(". This file is required by BiblioteQ.");
	    return;
	  }

	qts.setDevice(&qf);

	while(!qts.atEnd())
	  {
	    str = str.prepConfigString(qts.readLine().trimmed(), true);
	    list.append(str);
	  }

	qf.close();
	break;
      }
    case QUERY_LIBRARY_OF_CONGRESS:
      {
	size_t i = 0;
	const char *rec = NULL;
	ZOOM_resultset r;
	ZOOM_connection z = ZOOM_connection_new
	  ((const char *) (qmain->getLOCHash().value("Address") + ":" +
			   qmain->getLOCHash().value("Port") + "/" +
			   qmain->getLOCHash().value("Database")).
	   toStdString().data(), 0);

	ZOOM_connection_option_set(z, "preferredRecordSyntax", "USMARC");
	r = ZOOM_connection_search_pqf
	  (z, (const char *) LOCSearchStr.toStdString().data());

	while((rec = ZOOM_record_get(ZOOM_resultset_record(r, i),
				     "render", NULL)) != NULL)
	  {
	    i += 1;
	    LOCResults.append(rec);
	  }

	ZOOM_resultset_destroy(r);
	ZOOM_connection_destroy(z);

	if(LOCResults.isEmpty())
	  {
	    eType = "Query Error";
	    errorStr = "Query Error";
	  }

	/*
	  try
	  {
	  ZOOM::connection conn
	  (qmain->getLOCHash().value("Address").toStdString(),
	  qmain->getLOCHash().value("Port").toInt());
	  conn.option
	  ("databaseName",
	  qmain->getLOCHash().value("Database").toStdString());
	  conn.option("preferredRecordSyntax", "USMARC");
	  ZOOM::resultSet rs
	  (conn, ZOOM::prefixQuery(LOCSearchStr.toStdString()));

	  for(i = 0; i < rs.size(); i++)
	  {
	  ZOOM::record rec(rs, i);
	  LOCResults.append(rec.render().data());
	  }
	  }
	  catch(ZOOM::systemException &e)
	  {
	  eType = "System Error";
	  errorStr = QString::number(e.errcode()) +
	  QString(" (%1)").arg(e.errmsg().data());
	  }
	  catch(ZOOM::bib1Exception &e)
	  {
	  eType = "BIB-1 Error";
	  errorStr = QString::number(e.errcode()) +
	  QString(" (%1): %2").arg(e.errmsg().data()).arg
	  (e.addinfo().data());
	  }
	  catch(ZOOM::queryException &e)
	  {
	  eType = "Query Error";
	  errorStr = QString::number(e.errcode()) +
	  QString(" (%1): %2").arg(e.errmsg().data()).arg
	  (e.addinfo().data());
	  }
	  catch(ZOOM::exception &e)
	  {
	  eType = "General Error";
	  errorStr = QString::number(e.errcode()) +
	  QString(" (%1)").arg(e.errmsg().data());
	  }
	*/

	break;
      }
    default:
      break;
    }
}

/*
** -- getList() --
*/

QStringList generic_thread::getList(void)
{
  return list;
}

/*
** -- getErrorStr() --
*/

QString generic_thread::getErrorStr(void)
{
  return errorStr;
}

/*
** -- setType() --
*/

void generic_thread::setType(const int type_arg)
{
  type = type_arg;
}

/*
** -- setOutput() --
*/

void generic_thread::setOutputList(const QList<bool> &list_arg)
{
  int i = 0;

  for(i = 0; i < list_arg.size(); i++)
    outputListBool.append(list_arg.at(i));
}

/*
** -- setFilename() --
*/

void generic_thread::setFilename(const QString &filename_arg)
{
  filename = filename_arg;
}

/*
** -- setLOCSearchString() --
*/

void generic_thread::setLOCSearchString(const QString &LOCSearchStr_arg)
{
  LOCSearchStr = LOCSearchStr_arg;
}

/*
** -- getLOCResults() --
*/

QStringList generic_thread::getLOCResults(void)
{
  return LOCResults;
}

/*
** -- getEType() --
*/

QString generic_thread::getEType(void)
{
  return eType;
}
