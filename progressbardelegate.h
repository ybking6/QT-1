#ifndef PROGRESSBARDELEGATE_H
#define PROGRESSBARDELEGATE_H

#include <QStyledItemDelegate>

class ProgressBarDelegate : public QStyledItemDelegate
{
public:
    explicit ProgressBarDelegate(QObject *parent = nullptr);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // PROGRESSBARDELEGATE_H
//这个头文件定义了一个自定义的委托类 ProgressBarDelegate，通常用于在Qt的视图中显示进度条或其他自定义的绘制内容。通过重写 paint 和 sizeHint 函数，可以实现对单元格内容的个性化绘制和大小控制。
