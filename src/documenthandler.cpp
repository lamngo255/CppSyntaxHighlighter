#include "documenthandler.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QQmlEngine>
#include <QUrl>
#include "highlighter.h"

DocumentHandler::DocumentHandler(QObject *parent)
    : QObject(parent)
{
}

void DocumentHandler::openFile(const QString& path)
{
    QUrl url(path);
    QFile file(url.toLocalFile());
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream stream(&file);
    auto text = stream.readAll();
    setText(text);
    file.close();
}

void DocumentHandler::onOpenTriggered()
{
    auto fileName = QFileDialog::getOpenFileName(0, QString("Open"));
    if (fileName.isEmpty())
        return;
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream stream(&file);
    auto text = stream.readAll();
    setText(text);
    file.close();
}

void DocumentHandler::setDocument(QQuickTextDocument* document)
{
    auto highlighter = new Highlighter(document->textDocument());
    Q_UNUSED(highlighter)
}

QString DocumentHandler::text() const
{
    return m_text;
}

void DocumentHandler::setText(QString text)
{
    if (m_text != text) {
        m_text = text;
        emit textChanged(text);
    }
}
