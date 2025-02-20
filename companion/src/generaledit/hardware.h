/*
 * Copyright (C) OpenTX
 *
 * Based on code named
 *   th9x - http://code.google.com/p/th9x
 *   er9x - http://code.google.com/p/er9x
 *   gruvin9x - http://code.google.com/p/gruvin9x
 *
 * License GPLv2: http://www.gnu.org/licenses/gpl-2.0.html
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#pragma once

#include "generaledit.h"

class CompoundItemModelFactory;
class FilteredItemModelFactory;
class QGridLayout;
class AutoComboBox;

class HardwarePanel : public GeneralPanel
{
    Q_OBJECT

  public:
    HardwarePanel(QWidget * parent, GeneralSettings & generalSettings, Firmware * firmware, CompoundItemModelFactory * editorItemModels);
    virtual ~HardwarePanel();

  signals:
    void internalModuleChanged();

  private slots:
    void on_internalModuleChanged();

  private:
    Board::Type board;
    CompoundItemModelFactory *editorItemModels;
    FilteredItemModelFactory *tabFilteredModels;
    QGridLayout *grid;
    AutoComboBox *internalModule;
    unsigned int m_internalModule = 0;
    AutoComboBox *internalModuleBaudRate;

    void addStick(int index, int & row);
    void addPot(int index, int & row);
    void addSlider(int index, int & row);
    void addSwitch(int index, int & row);
    void addLabel(QString text, int row, int col);
    void addLine(int & row);
    void addParams(int & row, QWidget * widget1, QWidget * widget2 = nullptr);
};
