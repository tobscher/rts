#include <iostream>

#include <QCoreApplication>
#include <QKeyEvent>
#include <QDebug>

#include "glwidget.h"

#include "dioptre/locator.h"
#include "dioptre/module.h"
#include "dioptre/window/null/window.h"

GLWidget::GLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
  renderer_ = dioptre::Locator::getInstance<dioptre::graphics::GraphicsInterface>(dioptre::Module::M_GRAPHICS);
}

GLWidget::~GLWidget()
{
}

void GLWidget::initializeGL()
{
  renderer_->initialize();
}

void GLWidget::resizeGL(int width, int height)
{
  renderer_->resize(width, height);
}

void GLWidget::paintGL()
{
  renderer_->render();
}
