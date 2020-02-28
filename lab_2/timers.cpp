#include "timers.h"
#include <vector>

Timers::Timers(QTime* _time,bool _is_active,QMediaPlayer* _music)
{
is_active=_is_active;
time=_time;
music=_music;

}
