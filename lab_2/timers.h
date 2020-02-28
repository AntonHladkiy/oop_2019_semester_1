#ifndef TIMERS_H
#define TIMERS_H

#include <QTime>
#include <QMediaPlayer>
class Timers
{
public:
    QTime* time;
    QMediaPlayer* music;
    bool is_active;
    Timers(QTime* _time,bool _is_active,QMediaPlayer* _music);
};

#endif // TIMERS_H
