#ifndef SPEED_ASKER_H
#define SPEED_ASKER_H

#include <QDialog>
#include <QSlider>
#include <QHBoxLayout>
#include <atomic>
#include <qlabel.h>

class speed_asker : public QDialog
{
    Q_OBJECT
public:
    explicit speed_asker(std::atomic<int>* speeder, QWidget *parent = nullptr);
private slots:
    void move_speed(int);
private:
    QHBoxLayout main_layer{this};
    QLabel value{};
    QSlider slider{};
    std::atomic<int>* speed;
};

#endif // SPEED_ASKER_H
