#ifndef GLWIDGET_H
#define GLWIDGET_H

#include "dioptre/graphics/opengl.h"
#include "dioptre/graphics/opengl/graphics.h"

#include <QOpenGLWidget>

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
  dioptre::graphics::GraphicsInterface* renderer_;
};

#endif // GLWIDGET_H
