#include "speed_asker.h"

speed_asker::speed_asker(std::atomic<int>* speeder, QWidget *parent)
    : QDialog{parent}, speed(speeder)
{
    slider.setRange(0, 1000);
    slider.setSliderPosition(*speed);
    value.setMinimumWidth(50);
    value.setNum(*speed);
    main_layer.addWidget(&slider, 1);
    main_layer.addWidget(&value, 1);

    connect(&slider, &QSlider::valueChanged, &value,
            static_cast<void (QLabel::*)(int)>(&QLabel::setNum));
}

void speed_asker::move_speed(int val)
{
    *speed = val;
}
