#include <QDebug>
#include "counter.hpp"

Counter::Counter(QObject *po_parent)
    : QObject{ po_parent }
    , _i_count{ 0 }
    , _b_up{ true }
    , _po_timer{ new QTimer{ this } } {
    qDebug() << "We instantiate the counter instance !";
    _po_timer->setInterval(1000);
    connect(_po_timer, &QTimer::timeout, [=]() {
        if (_b_up) {
            _i_count++;
        } else {
            _i_count--;
        }
        emit countChanged(_i_count);
    });
}

int Counter::count() const {
    return _i_count;
}

void Counter::setCount(int o_count) {
    if (_i_count == o_count)
        return;
    _i_count = o_count;
    emit countChanged(_i_count);
}

bool Counter::up() const
{
    return _b_up;
}

void Counter::setUp(bool o_up)
{
    if (_b_up == o_up)
        return;
    _b_up = o_up;
    emit upChanged(_b_up);
}

void Counter::start() {
    _po_timer->start();
}

void Counter::stop() {
    _po_timer->stop();
}
