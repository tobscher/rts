#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>

#include "dioptre/graphics/opengl/renderer.h"

class GLWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    GLWidget(QWidget *parent = 0);
    ~GLWidget();

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

private:
  dioptre::graphics::opengl::Renderer* renderer_;
};

#endif // GLWIDGET_H
