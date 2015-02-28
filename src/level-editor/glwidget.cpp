#include <iostream>

#include <QCoreApplication>
#include <QKeyEvent>
#include <QDebug>

#include "engine/graphics.h"
#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
}

GLWidget::~GLWidget()
{
}

void GLWidget::initializeGL()
{
  Initialize();
}

void GLWidget::resizeGL(int width, int height)
{
  Resize(width, height);
}

void GLWidget::paintGL()
{
  Render();
}
