/********************************************************************************
** Form generated from reading UI file 'stylesheeteditor.ui'
**
** Created: Tue May 1 14:49:40 2018
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STYLESHEETEDITOR_H
#define UI_STYLESHEETEDITOR_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QComboBox>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QPushButton>
#include <QSpacerItem>
#include <QTextEdit>
#include <QWidget>

QT_BEGIN_NAMESPACE

class Ui_StyleSheetEditor
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *spacerItem;
    QSpacerItem *spacerItem1;
    QComboBox *styleSheetCombo;
    QSpacerItem *spacerItem2;
    QComboBox *styleCombo;
    QLabel *label_7;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem3;
    QPushButton *applyButton;
    QTextEdit *styleTextEdit;
    QLabel *label_8;

    void setupUi(QWidget *StyleSheetEditor)
    {
        if (StyleSheetEditor->objectName().isEmpty())
            StyleSheetEditor->setObjectName(QString::fromUtf8("StyleSheetEditor"));
        StyleSheetEditor->resize(475, 408);
        gridLayout = new QGridLayout(StyleSheetEditor);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        spacerItem = new QSpacerItem(32, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem, 0, 6, 1, 1);

        spacerItem1 = new QSpacerItem(32, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem1, 0, 0, 1, 1);

        styleSheetCombo = new QComboBox(StyleSheetEditor);
        styleSheetCombo->setObjectName(QString::fromUtf8("styleSheetCombo"));

        gridLayout->addWidget(styleSheetCombo, 0, 5, 1, 1);

        spacerItem2 = new QSpacerItem(10, 16, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem2, 0, 3, 1, 1);

        styleCombo = new QComboBox(StyleSheetEditor);
        styleCombo->setObjectName(QString::fromUtf8("styleCombo"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(styleCombo->sizePolicy().hasHeightForWidth());
        styleCombo->setSizePolicy(sizePolicy);

        gridLayout->addWidget(styleCombo, 0, 2, 1, 1);

        label_7 = new QLabel(StyleSheetEditor);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_7, 0, 1, 1, 1);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        spacerItem3 = new QSpacerItem(321, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem3);

        applyButton = new QPushButton(StyleSheetEditor);
        applyButton->setObjectName(QString::fromUtf8("applyButton"));
        applyButton->setEnabled(false);

        hboxLayout->addWidget(applyButton);


        gridLayout->addLayout(hboxLayout, 2, 0, 1, 7);

        styleTextEdit = new QTextEdit(StyleSheetEditor);
        styleTextEdit->setObjectName(QString::fromUtf8("styleTextEdit"));

        gridLayout->addWidget(styleTextEdit, 1, 0, 1, 7);

        label_8 = new QLabel(StyleSheetEditor);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_8, 0, 4, 1, 1);


        retranslateUi(StyleSheetEditor);

        QMetaObject::connectSlotsByName(StyleSheetEditor);
    } // setupUi

    void retranslateUi(QWidget *StyleSheetEditor)
    {
        StyleSheetEditor->setWindowTitle("Style Editor");
        styleSheetCombo->clear();
        styleSheetCombo->insertItems(0, QStringList()
         << "Default"
         << "Modo"
        );
        label_7->setText("Style:");
        applyButton->setText("&Apply");
        label_8->setText("Style Sheet:");
    } // retranslateUi

};

namespace Ui {
    class StyleSheetEditor: public Ui_StyleSheetEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STYLESHEETEDITOR_H
