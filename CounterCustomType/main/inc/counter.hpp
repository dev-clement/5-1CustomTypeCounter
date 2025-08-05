#ifndef COUNTER_HPP
#define COUNTER_HPP

#include <QtQml>
#include <QTimer>
#include <QObject>

class Counter : public QObject {
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(int count READ count WRITE setCount NOTIFY countChanged)
    Q_PROPERTY(bool up READ up WRITE setUp NOTIFY upChanged)
public:
    explicit Counter(QObject *po_parent = nullptr);

    int count() const;
    void setCount(int o_count);

    bool up() const;
    void setUp(bool o_up);

    Q_INVOKABLE void start();
    Q_INVOKABLE void stop();

signals:
    void countChanged(int i_count);
    void upChanged(bool b_isUp);

private:
    int _i_count;
    bool _b_up;
    QTimer *_po_timer;
};

#endif // COUNTER_HPP
