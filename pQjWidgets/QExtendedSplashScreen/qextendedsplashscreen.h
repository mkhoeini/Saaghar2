/***************************************************************************
 *  This file is part of QExtendedSplashScreen, a custom Qt widget         *
 *                                                                         *
 *  Copyright (C) 2011 by S. Razi Alavizadeh                               *
 *  E-Mail: <s.r.alavizadeh@gmail.com>, WWW: <http://pozh.org>             *
 *                                                                         *
 *  The initial idea is from a custom lineEdit from qt labs.               *
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

#ifndef QTRANSPARENTSPLASH_H
#define QTRANSPARENTSPLASH_H

#include <QWidget>
class QVBoxLayout;
class QLabel;

class QExtendedSplashScreen : public QWidget
{
	Q_OBJECT

public:
	explicit QExtendedSplashScreen(const QPixmap &pixmap = QPixmap(), Qt::WindowFlags f = 0);
	QExtendedSplashScreen(QWidget *parent, const QPixmap &pixmap = QPixmap(), Qt::WindowFlags f = 0);
	virtual ~QExtendedSplashScreen();

	const QPixmap pixmap() const;
	void setPixmap(const QPixmap &pixmap);
	void finish(QWidget *mainWin);
	void repaint();
	void forceRepaint();//after repaint calls 'processEvent()'

public slots:
	void showMessage(const QString &message, int alignment, const QColor &color = Qt::black);
	void showMessage(const QString &message);//uses last setted alignment and color
	void setMessageOptions(QRect rect, int alignment = Qt::AlignLeft, const QColor &color = Qt::black);
	void clearMessage();

private:
	void init(const QPixmap &pixmap);
	QLabel *pixmapLabel;
	QVBoxLayout *mainLayout;
	void drawContents();
	QPixmap splashPixmap;
	QString currentStatus;
	QColor textColor;
	int textAlign;
	QRect textRect;
	Q_DISABLE_COPY(QExtendedSplashScreen)

protected:
	void mouseDoubleClickEvent(QMouseEvent *);
	virtual void drawContents(QPainter *painter);

signals:
	void messageChanged(const QString &);
};
#endif // QTRANSPARENTSPLASH_H
