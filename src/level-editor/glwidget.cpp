#include <iostream>

#include <QCoreApplication>
#include <QKeyEvent>
#include <QDebug>

#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
    , renderer_(new dioptre::graphics::opengl::Renderer(nullptr))
{
}

GLWidget::~GLWidget()
{
}

void GLWidget::initializeGL()
{
  renderer_->Initialize();
}

void GLWidget::resizeGL(int width, int height)
{
  renderer_->Resize(width, height);
}

void GLWidget::paintGL()
{
  renderer_->Render();
}
