/******************************************************************************
    Copyright (C) 2013 by Hugh Bailey <obs.jim@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/

#pragma once

#include <QtGui>
#include <QAction>
#include <QComboBox>
#include <QDialog>
#include <QGroupBox>
#include <QSystemTrayIcon>
#include <QWidget>

class OBSTray : public QDialog {
	Q_OBJECT
public:
	OBSTray();
	void setVisible(bool visible) Q_DECL_OVERRIDE;

protected:
	void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private slots:
	void setIcon(int index);

public slots:
	void closeObsTray();

signals:
	void closeObs();

private:
	void createActions();
	void createTrayIcon();

	QGroupBox *iconGroupBox;
	QComboBox *iconComboBox;

	QAction *setupAction;
	QAction *stopAction;
	QAction *quitAction;

	QSystemTrayIcon *trayIcon;
	QIcon defaultIcon;
	QIcon playingIcon;
	QMenu *trayIconMenu;
};