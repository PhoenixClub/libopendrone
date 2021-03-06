/**
 * This file is part of libopendrone.
 *
 * libopendrone is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * libopendrone is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with libopendrone.  If not, see <http://www.gnu.org/licenses/>.
 */

/** Generated by cmake */

// Version numbers (major.minor)
#define OPENDRONE_VERSION_MAJOR 0
#define OPENDRONE_VERSION_MINOR 1

// If available, use poll() over select()
#define USE_UNIX_POLL 1

// Platform detection
#ifdef _WIN32
  #define PLAF_WIN
  #define USE_SELECT
#else
  #define PLAF_UNIX
  #if USE_UNIX_POLL
    #define USE_POLL
  #else
    #define USE_SELECT
  #endif
#endif
