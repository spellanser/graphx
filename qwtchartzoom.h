#ifndef QWTCHARTZOOM_H
#define QWTCHARTZOOM_H

#include <QObject>
#include <QEvent>
#include <QMouseEvent>
#include "qwt_plot.h"
#include <qwt_plot_canvas.h>

class QwtChartZoom : public QObject
{
    Q_OBJECT

public:
    // �����������
    explicit QwtChartZoom(QwtPlot *,QObject * = 0);

    // ��������� ����� �����, �������� ����� ������ �������
    void setRubberBandColor(QColor);
    // �������� ������� ������ ������� � �������� ��������
    void fixBoundaries();
    // ������� ������������ ��������������� �������
    // ��� �������� ������ ����
    void setWheelFactor(double);

protected:
    // ���������� ���� �������
    bool eventFilter(QObject *,QEvent *);

private:
    double isb_xl,isb_xr;   // �������� ������� ������� �� ��� x
    double isb_yb,isb_yt;   // �������� ������� ������� �� ��� y
    bool isbF;              // ����, �������� ������������� ��������� �������� ������� �������
                            // ���� isbF �������, �� ��� ������ ������� �� ������ ������� �������
                            // ������� ����� ��������� � ���������� isb_xl,isb_xr,isb_yb,isb_yt,
                            // � ��� ������ ��������������� � ����������� ������ ����� ������������
                            // ������ � ���� ��������
    // �������� ���� �������� �������������� �������
    //     ctNone - ��� ��������������
    //     ctZoom - ��������� ��������
    //     ctDrag - ����������� �������
    //     ctWheel - ����� Wheel (��������� �������� ��� �������� ������ ����)
    // (��������, ������������ �� ctNone ��������� ������ ����
    // ������ ����� ��� ������ ������ ���� ��� ������� Ctrl)
    enum QConvType {ctNone,ctZoom,ctDrag,ctWheel};
    QConvType convType;     // ��� �������� �������������� �������
    double scb_xl,scb_xr;   // ������� ������� ������� �� ��� x � ������ ������ ��������������
    double scb_yb,scb_yt;   // ������� ������� ������� �� ��� y � ������ ������ ��������������
    int scp_x,scp_y;        // ��������� ������� � ������ ������ ��������������
                            // (� �������� ������������ ����� QwtPlot)
    double cs_kx,cs_ky;     // ������� �������������� ��������� �� ���� x � y
                            // (��������� ���������� ��� ����������� �� ���� ������)
    double sfact;           // �����������, ������������ ��������� �������� �������
                            // ��� �������� ������ ���� (�� ��������� ����� 1.2)
    QwtPlot *qwtp;          // ��������� QwtPlot, ������� ���������� ������
    QWidget *zwid;          // ������ ��� ����������� �����, �������� ����� ������ �������
    QColor zwClr;           // ���� �����, �������� ����� ������ �������
    QCursor tCursor;        // ����� ��� ���������� �������� �������

    void storeCursor();     // ���������� �������� �������
    void setCursor(QCursor);// ��������� �������
    void restCursor();      // �������������� �������

    // ���������� ������� ������� �� ����
    void procMouseEvent(QEvent *);

    // ���������� ������� �� ������ ����
    void procMouseButtonPress(QMouseEvent *);
    // ���������� ����������� ����
    void procMouseMove(QMouseEvent *);
    // ���������� ���������� ������ ����
    void procMouseButtonRelease(QMouseEvent *);

    // ��������� ��������� ��������
    void startZoom();
    // ��������� ����� ������ ������� ��� ��������� ��������
    void selectZoomRect(QMouseEvent *);
    // ���������� ��������� ��������
    void execZoom(QMouseEvent *);

    // ��������� ����������� �������
    void startDrag();
    // ���������� ����������� �������
    void execDrag(QMouseEvent *);
    // ���������� ����������� �������
    void endDrag();

    // ���������� �������/���������� ������� Ctrl
    void switchWheel(QEvent *);
    // ���������� �������� ������ ����
    void procWheel(QEvent *);

    // ����������� �������� ������� ������ �������
    // � �������� �������� (���� ���� isbF �������)
    void fixBounds();
    // �������������� �������� ������ �������
    void restBounds();
};

#endif // QWTCHARTZOOM_H
