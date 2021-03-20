﻿#include "widget.h"
#include "ui_widget.h"

#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent* e)
{
    /*
     【高级部分】
    */
    QPainter painter(this); // this:在当前窗口绘图
    painter.drawEllipse(QPoint(100, 100), 50, 50);
    // 设置抗锯齿能力
    painter.setRenderHint(QPainter::HighQualityAntialiasing);
    painter.drawEllipse(QPoint(250, 100), 50, 50);

    painter.drawRect(QRect(20,20,50,50));
    // 移动画笔
    painter.translate(100, 0);
    // 保存画笔
    painter.save();
    painter.drawRect(QRect(20,20,50,50)); // 与第一个矩形重叠
    painter.translate(100, 0);
    // 取出画笔状态
    painter.restore();
    painter.drawRect(QRect(20,20,50,50));

#if 0
    /*
     【基础部分】
    */
    // 设置画笔
    QPen pen(QColor(255,0,0));
    // 设置画笔宽度
    pen.setWidth(2);
    // 设置画笔风格
    pen.setStyle(Qt::DashDotLine);
    // 启用画笔
    painter.setPen(pen);
    // 画刷（填充封闭图形）
    QBrush brush(Qt::cyan);
    // 设置画刷风格
    brush.setStyle(Qt::DiagCrossPattern);
    painter.setBrush(brush);
    // 绘制线条
    painter.drawLine(QPoint(0, 0), QPoint(100, 100));
    // 绘制圆圈
    painter.drawEllipse(QPoint(100, 100), 50, 50);
    // 绘制矩形
    painter.drawRect(QRect(50,50,50,50));
    // 绘制文本
    painter.drawText(QRect(150,150,100,100), "应似飞鸿踏雪泥");
#endif
}
