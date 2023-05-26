#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QMessageBox>

#include "widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setupUI();
    setFixedSize(400, 400);
}

Widget::~Widget()
{
}


void Widget::setupUI()
{
    QFont labelFont("Times", 10, QFont::Bold);
    QLabel* mLabel = new QLabel("QTextEdit interactions", this);
    mLabel->setFont(labelFont);
    mLabel->move(100, 25);

    QTextEdit* mTextEdit = new QTextEdit(this);
    mTextEdit->move(70, 55);
    // textChanged
    // connect(mTextEdit, &QTextEdit::textChanged, [=](){ qDebug() << "Text changed!" ; });
    /*
     * Copy
     * Cut
     * Paste
     * Undo
     * Redo
     * setPlainText
     * setHtml
     * toPlainText
     * toHtml
     */
    // Copy
    QPushButton* copyButton = new QPushButton("Copy", this);
    copyButton->setMinimumSize(50, 25);
    copyButton->move(10, 250);
    connect(copyButton, &QPushButton::clicked, [=](){ mTextEdit->copy(); });
    // Cut
    QPushButton* cutButton = new QPushButton("Cut", this);
    cutButton->setMinimumSize(50, 25);
    cutButton->move(110, 250);
    connect(cutButton, &QPushButton::clicked, [=](){ mTextEdit->cut(); });
    // Paste
    QPushButton* pasteButton = new QPushButton("Paste", this);
    pasteButton->setMinimumSize(50, 25);
    pasteButton->move(210, 250);
    connect(pasteButton, &QPushButton::clicked, [=](){ mTextEdit->paste(); });
    // Undo
    QPushButton* undoButton = new QPushButton("Undo", this);
    undoButton->setMinimumSize(50, 25);
    undoButton->move(10, 280);
    connect(undoButton, &QPushButton::clicked, [=](){ mTextEdit->undo(); });
    // Redo
    QPushButton* redoButton = new QPushButton("Redo", this);
    redoButton->setMinimumSize(50, 25);
    redoButton->move(110, 280);
    connect(redoButton, &QPushButton::clicked, [=](){ mTextEdit->redo(); });
    // setPlainText
    QPushButton* setPlainTextButton = new QPushButton("Plain text", this);
    setPlainTextButton->setMinimumSize(100, 25);
    setPlainTextButton->move(10, 310);
    connect(setPlainTextButton, &QPushButton::clicked, [=](){ mTextEdit->setPlainText("Some plain text Some plain text Some plain text"); });
    // setHtml
    QPushButton* setHtmlButton = new QPushButton("Html", this);
    setHtmlButton->setMinimumSize(100, 25);
    setHtmlButton->move(120, 310);
    connect(setHtmlButton, &QPushButton::clicked, [=](){ mTextEdit->setHtml("<h1>Some h1 header</h1><p>Some paragraph html elem</p>"); });
    // toPlainText
    QPushButton* toPlainTextButton = new QPushButton("Grab Text", this);
    toPlainTextButton->setMinimumSize(100, 24);
    toPlainTextButton->move(10, 340);
    connect(toPlainTextButton, &QPushButton::clicked, [=](){ QMessageBox::information(this, "Info", "Grabbed plain text: " + mTextEdit->toPlainText()); });
    // toHtml
    QPushButton* toHtmlButton = new QPushButton("Grab Html", this);
    toHtmlButton->setMinimumSize(100, 25);
    toHtmlButton->move(120, 340);
    connect(toHtmlButton, &QPushButton::clicked, [=](){ QMessageBox::information(this, "Info", "Grabbed html: " + mTextEdit->toHtml()); });
}
