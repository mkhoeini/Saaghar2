/***************************************************************************
 *  This file is part of Saaghar, a Persian poetry software                *
 *                                                                         *
 *  Copyright (C) 2010-2011 by S. Razi Alavizadeh                          *
 *  E-Mail: <s.r.alavizadeh@gmail.com>, WWW: <http://pozh.org>             *
 *                                                                         *
 *  This program is free software; you can redistribute it and/or modify   *
 *  it under the terms of the GNU General Public License as published by   *
 *  the Free Software Foundation; either version 3 of the License,         *
 *  (at your option) any later version                                     *
 *                                                                         *
 *  This program is distributed in the hope that it will be useful,        *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *  GNU General Public License for more details                            *
 *                                                                         *
 *  You should have received a copy of the GNU General Public License      *
 *  along with this program; if not, see http://www.gnu.org/licenses/      *
 *                                                                         *
 ***************************************************************************/

#include <QTranslator>
#include <QtGui/QApplication>
#include <QLatin1String>

#include <QExtendedSplashScreen>
#include "mainwindow.h"

#ifdef Q_WS_WIN
#ifdef STATIC
	#include <QtPlugin>
	Q_IMPORT_PLUGIN(qsqlite)
#endif
#endif


/* A dummy class to cover for splash screen */
/*
class QExtendedSplashScreen : public QObject
{
	Q_OBJECT

public:
	QExtendedSplashScreen(const QPixmap&, Qt::WindowFlags) {}
	QExtendedSplashScreen(QWidget*, const QPixmap&, Qt::WindowFlags) {}
	virtual ~QExtendedSplashScreen() {}

	const QPixmap pixmap() const {}
	void setPixmap(const QPixmap&) {}
	void finish(QWidget*) {}
	void repaint() {}
	void forceRepaint() {}//after repaint calls 'processEvent()'

public slots:
	void showMessage(const QString&, int, const QColor&) {}
	void showMessage(const QString&) {} //uses last setted alignment and color
	void setMessageOptions(QRect, int, const QColor&) {}
	void clearMessage();

signals:
	void messageChanged(const QString &);
};
*/
int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	bool fresh = false;
	if (QCoreApplication::arguments().contains("-fresh", Qt::CaseInsensitive))
		fresh = true;

	QTranslator translator;

	QStringList translationDirs;
        translationDirs << "/usr/share/saaghar" 
                << QCoreApplication::applicationDirPath() + "/../Resources" 
                << QCoreApplication::applicationDirPath()
                << ":/ts/";

	foreach (QString dir, translationDirs)
	{
		if (translator.load(QLocale::system(), QLatin1String("saaghar"), dir))
		{
			app.installTranslator(&translator);
		}
		if (translator.load(QLocale::system(), QLatin1String("qt"), dir))
		{
			app.installTranslator(&translator);
		}
	}

	//'At Development Stage' message
	//QMessageBox::information(0, QObject::tr("At Development Stage"), QObject::tr("This is an experimental version! Don\'t release it!\nWWW: http://saaghar.pozh.org"));

	QPixmap pixmap(":/resources/images/saaghar-splash.png");
	QExtendedSplashScreen splash(pixmap, Qt::WindowStaysOnTopHint);
	splash.setMessageOptions(QRect(pixmap.rect().topLeft()+QPoint(30,400), pixmap.rect().bottomRight()+QPoint(-300,0)), Qt::AlignLeft|Qt::AlignBottom, Qt::blue);

	MainWindow w(0, &splash, fresh);
	w.show();

	splash.finish(&w);
//	w.emitReSizeEvent();//maybe a Qt BUG//before 'QMainWindow::show()' the computation of width of QMainWindow is not correct!

	return app.exec();
}
