/*
Copyright (C) 2017 - 2017 Evan Teran
                          evan.teran@gmail.com

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
*/

#ifndef BOOKMARKS_MODEL_20170103_H_
#define BOOKMARKS_MODEL_20170103_H_

#include <QAbstractItemModel>
#include <QVector>
#include "Types.h"

namespace BookmarksPlugin {

class BookmarksModel : public QAbstractItemModel {
	Q_OBJECT

public:
	struct Bookmark {
		edb::address_t address;
		enum {
			Code, Data, Stack
		}              type;
		QString        comment;
	};

public:
	BookmarksModel(QObject *parent = 0);
	virtual ~BookmarksModel();

public:
	virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	virtual QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
	virtual QModelIndex parent(const QModelIndex &index) const override;
	virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;
	virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

public:
	void addBookmark(const Bookmark &r);
	void clearBookmarks();
	void deleteBookmark(const QModelIndex &index);
	void setComment(const QModelIndex &index, const QString &comment);


public:
	QVector<Bookmark> &bookmarks() { return bookmarks_; }

private:
	QVector<Bookmark> bookmarks_;
};

}

#endif
