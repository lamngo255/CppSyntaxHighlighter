#ifndef DOCUMENTHANDLER_H
#define DOCUMENTHANDLER_H

#include <QQuickTextDocument>

class DocumentHandler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)

public:
    explicit DocumentHandler(QObject *parent = 0);

    ~DocumentHandler() { }

    Q_INVOKABLE void openFile(const QString& path);
    Q_INVOKABLE void onOpenTriggered();
    Q_INVOKABLE void setDocument(QQuickTextDocument* document);
    QString text() const;

public slots:
    void setText(QString text);

signals:
    void textChanged(QString text);

private:
    QString m_text;
};

#endif // DOCUMENTHANDLER_H
