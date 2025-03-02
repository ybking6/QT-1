#include "progressbardelegate.h"
#include <QProgressBar>
#include <QApplication>
ProgressBarDelegate::ProgressBarDelegate(QObject *parent)
    : QStyledItemDelegate{parent}
{}
void ProgressBarDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    int progress = index.data().toInt();//data() 方法返回一个 QVariant 对象，QVariant 是 Qt 中用于存储多种类型数据的通用容器。
    // 使用样式表绘制进度条，避免重复创建对象
    QStyleOptionProgressBar progressBarOption;
    progressBarOption.rect = option.rect;
    progressBarOption.minimum = 0;
    progressBarOption.maximum = 100;
    progressBarOption.progress = progress;
    progressBarOption.text = QString::number(progress) + "%";
    progressBarOption.textVisible = true;

    QApplication::style()->drawControl(QStyle::CE_ProgressBar, &progressBarOption, painter);
}

QSize ProgressBarDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QSize(100, 20); // 保持固定大小，或根据需求动态调整
}
//QStyledItemDelegate是在qt中对于tableview Qlistview中自定义单元格的大小
