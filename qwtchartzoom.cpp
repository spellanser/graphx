/**************************************************************/
/*                                                            */
/*               ���������� ������ QwtChartZoom               */
/*                         ������ 1.1                         */
/*                                                            */
/* ���������� ��������� ������ ���������,                     */
/* �. �������-��������� ������������ ���., 2011 �.            */
/*                                                            */
/* ����������� ��������� ������������� � ���������������.     */
/* ���������� ������ �����������.                             */
/*                                                            */
/**************************************************************/

#include "qwtchartzoom.h"

// �����������
QwtChartZoom::QwtChartZoom(QwtPlot *qp,QObject *parent) :
    QObject(parent)
{
    // ���������� ���� ��� ����, ����� ����� ������ ���������� ��������
    // ������� ������� ������� ���� ������������� � �������� ��������
    isbF = false;
    // ��������� �����������, ������������ ��������� �������� �������
    // ��� �������� ������ ����
    sfact = 1.2;
    // �������� ��������� QwtPlot, ��� ������� ����� ������������� ��� ��������������
    qwtp = qp;
    // ������������� ��� ��������, ����������� ������������ ������� �� ����������
    qwtp->setFocusPolicy(Qt::StrongFocus);
    // ������� ������, ���������� �� ����������� ���������� �������
    zwid = 0;
    // � ��������� ��� ���� (�� ��������� - ������)
    zwClr = Qt::black;
    // ���������� ������� ������
    convType = ctNone;
    // ������������� ���������� ���� �������
    qwtp->installEventFilter(this);
}

// ��������� ����� �����, �������� ����� ������ �������
void QwtChartZoom::setRubberBandColor(QColor clr) {
    zwClr = clr;
}

// ��������� �������
void QwtChartZoom::setCursor(QCursor cur) {
    qwtp->canvas()->setCursor(cur);
}

// �������� ������� ������ ������� � �������� ��������
void QwtChartZoom::fixBoundaries() {
    // ����� ������ ������������ ���� � ��� �����
    // ����������� �� ������������� ����������� �������
    isbF = false;
    // ����������� �������� ������ ���������� � ������ ������
    // ������-���� �������������� ��� ������ fixBounds()
}

// ������� ������������ ��������������� �������
// ��� �������� ������ ���� (�� ��������� �� ����� 1.2)
void QwtChartZoom::setWheelFactor(double fact) {
    sfact = fact;
}

// ���������� �������� �������
void QwtChartZoom::storeCursor() {
    tCursor = qwtp->canvas()->cursor();
}

// �������������� �������
void QwtChartZoom::restCursor() {
    qwtp->canvas()->setCursor(tCursor);
}

// ���������� ���� �������
bool QwtChartZoom::eventFilter(QObject *obj,QEvent *event)
{
    // ���� ������� ����� ��������� � QwtPlot
    if (obj == qwtp)
    {
        // ���� ��������� ���� �� ������� �� ����, �� �������� ���������� procMouseEvent
        if (event->type() == QEvent::MouseButtonPress ||
            event->type() == QEvent::MouseMove ||
            event->type() == QEvent::MouseButtonRelease) procMouseEvent(event);

        // ���� ��������� ���� �� ������� �� ����������, �� �������� ���������� switchWheel
        if (event->type() == QEvent::KeyPress ||
            event->type() == QEvent::KeyRelease) switchWheel(event);

        // ���� ������� ������� ��������� ������ ����, �� �������� ���������� procWheel
        if (event->type() == QEvent::Wheel) procWheel(event);
    }
    // �������� ���������� ������������ ����������� �������
    return QObject::eventFilter(obj,event);
}

// ���������� ������� ������� �� ����
void QwtChartZoom::procMouseEvent(QEvent *event)
{
    // ������� ��������� �� ������� �� ����
    QMouseEvent *mEvent = static_cast<QMouseEvent *>(event);
    // ���� ������ ������ ����, �� �������� ���������� procMouseButtonPress
    if (event->type() == QEvent::MouseButtonPress) procMouseButtonPress(mEvent);
    // ����� ���� ����, �� �������� ���������� procMouseMove
    else if (event->type() == QEvent::MouseMove) procMouseMove(mEvent);
    // ����� ���� �������� ������ ����, �� �������� ���������� procMouseButtonRelease
    else if (event->type() == QEvent::MouseButtonRelease) procMouseButtonRelease(mEvent);
}

// ���������� ������� �� ������ ����
void QwtChartZoom::procMouseButtonPress(QMouseEvent *mEvent)
{
    // ��������� �������� ������� ������� (���� ����� ��� �� ���� �������)
    fixBounds();
    // ���� � ������ ������ ��� �� ������� �� ���� �� �������
    if (convType == ctNone)
    {
        // ���������� ������� ��������� ������� (������������ ����� QwtPlot)
        scp_x = mEvent->pos().x() - qwtp->canvas()->geometry().x();
        scp_y = mEvent->pos().y() - qwtp->canvas()->geometry().y();
        // ���� ������ ��������� ��� ������ QwtPlot
        if (scp_x >= 0 &&
            scp_x < qwtp->canvas()->geometry().width() &&
            scp_y >= 0 &&
            scp_y < qwtp->canvas()->geometry().height())
        {
            // ���� ������ ����� ������ ����, �� �������� �������� �������
            // ��� ������������������� �������
            if (mEvent->button() == Qt::LeftButton) startZoom();
            // ����� ���� ������ ������ ������ ����, �� �������� �����
            // ����������� �������
            else if (mEvent->button() == Qt::RightButton) startDrag();
        }
    }
}

// ���������� ����������� ����
void QwtChartZoom::procMouseMove(QMouseEvent *mEvent)
{
    // ���� ������� ����� ��������� ��������, ��
    // ��������� ��������� ������� ��� ������������������� �������
    if (convType == ctZoom) selectZoomRect(mEvent);
    // ����� ���� ������� ����� ����������� �������, ��
    // ��������� ����������� �������
    else if (convType == ctDrag) execDrag(mEvent);
}

// ���������� ���������� ������ ����
void QwtChartZoom::procMouseButtonRelease(QMouseEvent *mEvent)
{
    // ���� ������� ����� ��������� �������� ��� ����� ����������� �������
    if (convType==ctZoom || convType==ctDrag)
    {
        // ���� �������� ����� ������ ����, ��
        // ��������� ������������������� ������� � ������������ � ���������� ��������
        if (mEvent->button() == Qt::LeftButton) execZoom(mEvent);
        // ����� ���� �������� ������ ������ ����, ��
        // ���������� ����������� �������
        else if (mEvent->button() == Qt::RightButton) endDrag();
    }
}

// ��������� ��������� ��������
void QwtChartZoom::startZoom()
{
    // ����������� ��������������� ������� ������
    convType = ctZoom;
    storeCursor();  // ���������� ������� ������
    // ������������� ������ Cross
    setCursor(Qt::CrossCursor);
    // ������� ������, ������� ����� ���������� ���������� �������
    // (�� ����� ��������������� �� ��� �� �������, ��� � QwtPlot)
    zwid = new QWidget(qwtp->parentWidget());
    // � ��������� ��� ����
    zwid->setStyleSheet(QString(
        "background-color:rgb(%1,%2,%3);").arg(
        zwClr.red()).arg(zwClr.green()).arg(zwClr.blue()));
}

// ��������� ����� ������ ������� ��� ��������� ��������
void QwtChartZoom::selectZoomRect(QMouseEvent *mEvent)
{
    // scp_x - ���������� ������� � �������� �� ��� x � ��������� ������ �������
    //     (����� ���� ������ ����� ������ ����)
    // mEvent->pos().x() - qwtp->canvas()->geometry().x() - ���������� �������
    //     � �������� �� ��� x � ������� ������ �������
    // mEvent->pos().x() - qwtp->canvas()->geometry().x() - scp_x - �������� �������
    //     � �������� �� ��� x �� ���������� ��������� � ��������������
    //     ������ dx ���������� �������
    int dx = mEvent->pos().x() - qwtp->canvas()->geometry().x() - scp_x;
    // qwtp->geometry().x() - ��������� QwtPlot �� ��� x ������������ �������, ��� �����������
    // qwtp->geometry().x() + qwtp->canvas()->geometry().x() - ��������� ����� QwtPlot
    //     �� ��� x ������������ �������, ��� �����������
    // qwtp->geometry().x() + qwtp->canvas()->geometry().x() + scp_x - ��������� gx0 ��������� �����
    //     �� ��� x ������������ �������, ����������� QwtPlot, ��� ����� � �������� �����
    //     ��� ����������� ���������� �������
    int gx0 = qwtp->geometry().x() + qwtp->canvas()->geometry().x() + scp_x;
    // ���� ������ ���������� ������� ������������, �� ������� ����� ��������� ����� ���������,
    //     � ����� ������ �� �� ���������� � �������� ����� ��� ����������� ���������� �������
    if (dx < 0) {dx = -dx; gx0 -= dx;}
    // ����� ���� ������ ����� ����, �� ��� ���� ����� ���������� ������� ���-���� �����������,
    //     ������������� ������� �� ������ �������
    else if (dx == 0) dx = 1;
    // ���������� ���������� ������ dy ���������� �������
    int dy = mEvent->pos().y() - qwtp->canvas()->geometry().y() - scp_y;
    // � ��������� gy0 ��������� ����� �� ��� y
    int gy0 = qwtp->geometry().y() + qwtp->canvas()->geometry().y() + scp_y;
    // ���� ������ ���������� ������� ������������, �� ������� ����� ��������� ���� ���������,
    //     � ����� ������ �� �� ���������� � �������� ����� ��� ����������� ���������� �������
    if (dy < 0) {dy = -dy; gy0 -= dy;}
    // ����� ���� ������ ����� ����, �� ��� ���� ����� ���������� ������� ���-���� �����������,
    //     ������������� ������� �� ������ �������
    else if (dy == 0) dy = 1;
    // ������������� ��������� � ������� �������, ������������� ���������� �������
    zwid->setGeometry(gx0,gy0,dx,dy);
    // ��������� ����� ��� �������, ������������� ���������� �������
    // ������������ �������
    QRegion rw(0,0,dx,dy);
    // ���������� �������
    QRegion rs(1,1,dx-2,dy-2);
    // ������������� ����� ����� ��������� �� ������������ ������� ����������
    zwid->setMask(rw.subtracted(rs));
    // ������ ������, ������������� ���������� �������, �������
    zwid->setVisible(true);
    // �������������� QwtPlot
    zwid->repaint();
}

// ���������� ��������� ��������
void QwtChartZoom::execZoom(QMouseEvent *mEvent)
{
    // ���� ������� ����� ��������� ��������
    if (convType == ctZoom)
    {
        restCursor();   // ��������������� ������
        // ������� ������, ������������ ���������� �������
        delete zwid;
        // ���������� ��������� �������, �.�. ���������� xp � yp
        // �������� ����� ���������� ������� (� �������� ������������ ����� QwtPlot)
        int xp = mEvent->pos().x() - qwtp->canvas()->geometry().x();
        int yp = mEvent->pos().y() - qwtp->canvas()->geometry().y();
        // ���� ��������� ������������� ������ ������ ��� ����� �����,
        // �� ��������������� �������� ������� ������� (�������� ����������)
        if (xp<scp_x || yp<scp_y) restBounds();
        // ����� ���� ������ ���������� ������� ����������, �� �������� �������
        else if (xp-scp_x >= 8 && yp-scp_y >= 8)
        {
            // ������������� ����� ������� ����� x �� ��������� �����, � ������ �� ��������
            qwtp->setAxisScale(QwtPlot::xBottom,
                               qwtp->invTransform(QwtPlot::xBottom,scp_x),
                               qwtp->invTransform(QwtPlot::xBottom,xp));
            // ������������� ������� ������� ����� y �� ��������� �����, � ������ �� ��������
            qwtp->setAxisScale(QwtPlot::yLeft,
                               qwtp->invTransform(QwtPlot::yLeft,yp),
                               qwtp->invTransform(QwtPlot::yLeft,scp_y));
            // �������������� ������
            qwtp->replot();
        }
        // ������� ������� ������
        convType = ctNone;
    }
}

// ��������� ����������� �������
void QwtChartZoom::startDrag()
{
    // ����������� ��������������� ������� ������
    convType = ctDrag;
    storeCursor();  // ���������� ������� ������
    // ������������� ������ OpenHand
    setCursor(Qt::OpenHandCursor);
    // ���������� ������� �������������� ��������� �� ��� x
    //     (�.�. ������ �� ������� ���������� ���������� �� ����� x
    //     ��� ����������� ������� ������ �� ���� ������)
    cs_kx = qwtp->invTransform(QwtPlot::xBottom,scp_x+1) - qwtp->invTransform(QwtPlot::xBottom,scp_x);
    // ���������� ���������� ������� �������������� ��������� �� ��� y
    cs_ky = qwtp->invTransform(QwtPlot::yLeft,scp_y+1) - qwtp->invTransform(QwtPlot::yLeft,scp_y);
    // �������� ����� ����� x �� �����
    QwtScaleMap sm = qwtp->canvasMap(QwtPlot::xBottom);
    // ��� ���� ����� ����������� ��������� ����� � ������ �������
    scb_xl = sm.s1(); scb_xr = sm.s2();
    // ���������� �������� ����� ����� y �� �����
    sm = qwtp->canvasMap(QwtPlot::yLeft);
    // ��� ���� ����� ����������� ��������� ������ � ������� �������
    scb_yb = sm.s1(); scb_yt = sm.s2();
}

// ���������� ����������� �������
void QwtChartZoom::execDrag(QMouseEvent *mEvent)
{
    // ������������� ������ ClosedHand
    setCursor(Qt::ClosedHandCursor);
    // scp_x - ���������� ������� � �������� �� ��� x � ��������� ������ �������
    //     (����� ���� ������ ������ ������ ����)
    // mEvent->pos().x() - qwtp->canvas()->geometry().x() - ���������� �������
    //     � �������� �� ��� x � ������� ������ �������
    // mEvent->pos().x() - qwtp->canvas()->geometry().x() - scp_x - �������� �������
    //     � �������� �� ��� x �� ���������� ���������
    // (mEvent->pos().x() - qwtp->canvas()->geometry().x() - scp_x) * cs_kx -  ��� �� ��������,
    //     �� ��� � �������� ����� x
    // dx - �������� ������ �� ��� x ������� � �������� ������
    //     (����� ������ ������������ ������ ������������ ������, ���� ������� ������� �������� �����)
    double dx = -(mEvent->pos().x() - qwtp->canvas()->geometry().x() - scp_x) * cs_kx;
    // ������������� ����� ����� � ������ ������� ����� ��� ��� x
    //     ����� ������� = ��������� ������� + ��������
    qwtp->setAxisScale(QwtPlot::xBottom,scb_xl+dx,scb_xr+dx);
    // ���������� ���������� dy - �������� ������ �� ��� y
    double dy = -(mEvent->pos().y() - qwtp->canvas()->geometry().y() - scp_y) * cs_ky;
    // ������������� ����� ������ � ������� ������� ����� ��� ��� y
    qwtp->setAxisScale(QwtPlot::yLeft,scb_yb+dy,scb_yt+dy);
    // �������������� ������
    qwtp->replot();
}

// ���������� ����������� �������
void QwtChartZoom::endDrag()
{
    // ���� ������� ����� ����������� �������
    if (convType == ctDrag)
    {
        restCursor();       // �� ��������������� ������
        convType = ctNone;  // � ������� ������� ������
    }
}

// ���������� �������/���������� ������� Ctrl
void QwtChartZoom::switchWheel(QEvent *event)
{
    // ������� ��������� �� ������� �� ����������
    QKeyEvent *kEvent = static_cast<QKeyEvent *>(event);
    // ���� ������/�������� ������� Ctrl
    if (kEvent->key() == Qt::Key_Control)
    {
        // ���� ������� ������
        if (event->type() == QEvent::KeyPress)
        {
            // ���� �� ������� ������� ������ �����,
            // �� �������� ����� Wheel
            if (convType==ctNone) convType = ctWheel;
        }
        // ����� ���� ������� ��������
        else if (event->type() == QEvent::KeyRelease)
        {
            // ���� ������� ����� Wheel,
            // �� ��������� ���
            if (convType == ctWheel) convType = ctNone;
        }
    }
}

// ���������� �������� ������ ����
void QwtChartZoom::procWheel(QEvent *event)
{
    // ���� ������� ����� Wheel (���� ������ ������� Ctrl)
    if (convType == ctWheel)
    {
        // �������� ��� QEvent � QWheelEvent
        QWheelEvent *wEvent = static_cast<QWheelEvent *>(event);
        // ���� ��������� ������������ ������ ����
        if (wEvent->orientation() == Qt::Vertical)
        {
            // ��������� �������� ������� ������� (���� ����� ��� �� ���� �������)
            fixBounds();
            // �������� ����� ����� ��� x �� �����
            QwtScaleMap sm = qwtp->canvasMap(QwtPlot::xBottom);
            // ���������� ����� ������������� �� ����� x ���������
            double mx = (sm.s1() + sm.s2()) / 2;
            // � ���������� ���������
            double dx = (sm.s2() - sm.s1()) / 2;
            // �� �� ����� ����������� � ���� y
            sm = qwtp->canvasMap(QwtPlot::yLeft);
            // ���������� ����� ������������� �� ����� y ���������
            double my = (sm.s1() + sm.s2()) / 2;
            // � ���������� ���������
            double dy = (sm.s2() - sm.s1()) / 2;
            // ���������� ���� �������� ������ ����
            // (�������� 120 ������������� ���� �������� 15�)
            int wd = wEvent->delta();
            // ��������� �������������� ���������
            // (�� ������� ��� ����� ��������/�������� ������)
            double kw = sfact * wd / 120;
            // ���� ���� �������� �����������, �� ����������� ������� �������������
            if (wd > 0)
            {
                // ��������� ���������� ������������ ���������� � kw ���
                dx /= kw; dy /= kw;
                // ������������� ����� ����� � ������ ������� ����� ��� ��� x
                // (����� ������������ ����� ������� �������� �� �����,
                // � ������� ������������ � ������, �.�. ����������� ������� �������������)
                qwtp->setAxisScale(QwtPlot::xBottom,mx-dx,mx+dx);
                // ���������� ������������� ����� ������ � ������� ������� ����� ��� ��� y
                qwtp->setAxisScale(QwtPlot::yLeft,my-dy,my+dy);
                // �������������� ������
                qwtp->replot();
            }
            // ����� ���� ���� �������� �����������, �� ����������� ������� �����������
            else if (wd < 0)
            {
                // ����������� ���������� ������������ ���������� � -kw ���
                dx *= -kw; dy *= -kw;
                // ������������� ����� ����� � ������ ������� ����� ��� ��� x
                // (����� ������������ ����� ������� �������� �� �����,
                // � ������� ��������� �� ������, �.�. ����������� ������� �����������)
                qwtp->setAxisScale(QwtPlot::xBottom,mx-dx,mx+dx);
                // ���������� ������������� ����� ������ � ������� ������� ����� ��� ��� y
                qwtp->setAxisScale(QwtPlot::yLeft,my-dy,my+dy);
                // �������������� ������
                qwtp->replot();
            }
        }
    }
}

// ����������� �������� ������� ������ �������
// � �������� �������� (���� ���� isbF �������)
void QwtChartZoom::fixBounds()
{
    // ���� ����� ��� �� ���� �������
    if (!isbF)
    {
        // �������� ����� ����� ��� x �� �����
        QwtScaleMap sm = qwtp->canvasMap(QwtPlot::xBottom);
        // � ���������� ������� ����� � ������ ������� �����
        isb_xl = sm.s1(); isb_xr = sm.s2();
        // �� �� ����� ����������� � ���� y
        sm = qwtp->canvasMap(QwtPlot::yLeft);
        // ���������� ������� ������ � ������� ������� �����
        isb_yb = sm.s1(); isb_yt = sm.s2();
        // ������������� ������ �������� ������ �������
        isbF = true;
    }

}

// �������������� �������� ������ �������
void QwtChartZoom::restBounds()
{
    // ������������� ����������� �����
    // ����� � ������ ������� ����� ��� ��� x
    qwtp->setAxisScale(QwtPlot::xBottom,isb_xl,isb_xr);
    // � ������ � ������� ������� ����� ��� ��� y
    qwtp->setAxisScale(QwtPlot::yLeft,isb_yb,isb_yt);
    // �������������� ������
    qwtp->replot();
}
