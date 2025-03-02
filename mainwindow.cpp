#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    progressBarDelegate = new ProgressBarDelegate(this);
    //新建一个 progressBarDelegate类
    // 设置表格的代理
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setRowCount(5);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "任务名称" << "负责人" << "进度");

    // 设置进度列使用自定义代理
    ui->tableWidget->setItemDelegateForColumn(2, progressBarDelegate);//将你自定义的类应用到列中就用来画进度条

    // 填充表格数据
    QStringList tasks = {"任务1", "任务2", "任务3", "任务4", "任务5"};
    QStringList assignees = {"张三", "李四", "王五", "赵六", "孙七"};
    QList<int> progresses = {30, 50, 70, 90, 10};

    for (int i = 0; i < tasks.size(); ++i) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(tasks[i]));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(assignees[i]));
        QTableWidgetItem *progressItem = new QTableWidgetItem(QString::number(progresses[i]));//因为要显示字符串而最后一列的话是自定义代理所以需要新建一个指针来调用方法
        progressItem->setData(Qt::DisplayRole, progresses[i]); // 确保数据类型为整数
        ui->tableWidget->setItem(i, 2, progressItem);
    }

    // 调整列宽适应内容
    ui->tableWidget->resizeColumnsToContents();
}



MainWindow::~MainWindow()
{
    delete ui;
}
