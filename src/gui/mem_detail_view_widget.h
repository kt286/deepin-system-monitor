/*
* Copyright (C) 2019 ~ 2020 Uniontech Software Technology Co.,Ltd
*
* Author:      maojj <maojunjie@uniontech.com>
* Maintainer:  maojj <maojunjie@uniontech.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MEM_DETAIL_VIEW_WIDGET_H
#define MEM_DETAIL_VIEW_WIDGET_H

#include "base/base_detail_view_widget.h"

/**
 * @brief Memory detail view widget
 */
class MemStatViewWidget;
class MemSummaryViewWidget;
class MemDetailViewWidget : public BaseDetailViewWidget
{
    Q_OBJECT

public:
    explicit MemDetailViewWidget(QWidget *parent = nullptr);

public slots:
    void detailFontChanged(const QFont &font) override;
    void onModelUpdate();

private:
    MemStatViewWidget *m_memstatWIdget;
    MemSummaryViewWidget *m_memsummaryWidget;
};

#endif // MEM_DETAIL_VIEW_WIDGET_H
