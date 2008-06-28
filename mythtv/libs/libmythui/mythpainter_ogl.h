#ifndef MYTHPAINTER_OPENGL_H_
#define MYTHPAINTER_OPENGL_H_

#include "mythpainter.h"
#include "mythimage.h"

#include <list>
using namespace std;

class MythOpenGLPainter : public MythPainter
{
  public:
    MythOpenGLPainter();
   ~MythOpenGLPainter();

    virtual QString GetName(void) { return QString("OpenGL"); }
    virtual bool SupportsAnimation(void) { return true; }
    virtual bool SupportsAlpha(void) { return true; }
    virtual bool SupportsClipping(void) { return false; }

    virtual void Begin(QWidget *parent);
    virtual void End();

    virtual void DrawImage(const QRect &dest, MythImage *im, const QRect &src,
                           int alpha);
    virtual void DrawText(const QRect &dest, const QString &msg, int flags,
                          const MythFontProperties &font, int alpha,
                          const QRect &boundRect);

    virtual MythImage *GetFormatImage();
    virtual void DeleteFormatImage(MythImage *im);

  protected:
    inline int CalcAlpha(int alpha1, int alpha2);

    MythImage *GetImageFromString(const QString &msg, int flags, const QRect &r,
                                  const MythFontProperties &font, 
                                  const QRect &boundRect);

    QMap<QString, MythImage *> m_StringToImageMap;
    list<QString> m_StringExpireList;

    int q_gl_texture;
    int texture_rects;
    QGLWidget *m_realParent;
};

#endif
