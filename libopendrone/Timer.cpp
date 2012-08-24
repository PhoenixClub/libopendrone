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

#include <libopendrone/Timer.h>

#ifdef PLAF_WIN
  #include <winsock.h>
#endif

#ifdef PLAF_UNIX
  #include <sys/select.h>
  #include <poll.h>
#endif

namespace opendrone
{
    void SleepMillis(long millis) 
    {
#ifdef USE_SELECT
        fd_set* dummyPtr = 0;
#ifdef PLAF_WIN 
        // Damn windows.. This might impact performance ever so slightly..
        fd_set dummy;
        SOCKET s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
        FD_ZERO(&dummy);
        FD_SET(s, &dummy);
        dummyPtr = &dummy;
#endif
        struct timeval tv;
        tv.tv_sec = millis/1000;
        tv.tv_usec = (millis%1000)*1000;
        int x = select(0, 0, 0, dummyPtr, &tv);
#endif
#ifdef USE_POLL
        poll(0, 0, millis);
#endif
    }
}