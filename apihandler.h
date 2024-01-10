#pragma once

#include <QObject>
#include <QVector>

#include "pimpl.h"
#include "translation.h"

class ApiHandler final : public QObject
{
    Q_OBJECT
public:
    ApiHandler() noexcept;
    ~ApiHandler() noexcept;

    void translate(const QString&) noexcept;

signals:
    void finished(const QVector<Translation>&);

private:
    DECLARE_PIMPL
};

