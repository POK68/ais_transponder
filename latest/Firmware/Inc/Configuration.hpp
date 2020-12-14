/*
  Copyright (c) 2016-2020 Peter Antypas

  This file is part of the MAIANA™ transponder firmware.

  The firmware is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <https://www.gnu.org/licenses/>
 */

#ifndef CONFIGURATION_HPP_
#define CONFIGURATION_HPP_

// This singleton manages user-definable configuration data stored in Flash.

#include "StationData.h"

// This should be plenty big (no need to be a whole flash page)
typedef union
{
  StationData station;
  uint64_t dw[64];
} ConfigPage;

class Configuration
{
public:
  static Configuration &instance();

  void init();

  // Station data is separate from other configuration values and occupies a different address
  bool writeStationData(const StationData &data);
  bool readStationData(StationData &data);
  void resetToDefaults();
  void reportStationData();
private:
  Configuration();
  bool erasePage();
  bool writePage();
};

#endif /* CONFIGURATION_HPP_ */


