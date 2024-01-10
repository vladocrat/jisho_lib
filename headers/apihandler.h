#pragma once

#include <QObject>
#include <QVector>

#include "utils/pimpl.h"
#include "translation.h"

namespace JL
{

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

} //! JL
