/**
 * Copyright (C) 2015 Deepin Technology Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 **/

#ifndef DSPINBOX_H
#define DSPINBOX_H

#include <QSpinBox>

#include "dtkwidget_global.h"
#include "dobject.h"

DWIDGET_BEGIN_NAMESPACE

class DSpinBoxPrivate;
class DSpinBox : public QSpinBox, public DTK_CORE_NAMESPACE::DObject
{
    Q_OBJECT

    Q_PROPERTY(bool alert READ isAlert WRITE setAlert NOTIFY alertChanged)
    Q_PROPERTY(int defaultValue READ defaultValue WRITE setDefaultValue NOTIFY defaultValueChanged)

public:
    explicit DSpinBox(QWidget *parent = 0);

    QLineEdit *lineEdit() const;

    bool isAlert() const;
    int defaultValue() const;

public Q_SLOTS:
    void setAlert(bool alert);
    void setDefaultValue(int defaultValue);

Q_SIGNALS:
    void alertChanged(bool alert);
    void defaultValueChanged(int defaultValue);

protected:
    void resizeEvent(QResizeEvent *e) Q_DECL_OVERRIDE;

private:
    D_DECLARE_PRIVATE(DSpinBox)
};

class DDoubleSpinBoxPrivate;
class DDoubleSpinBox : public QDoubleSpinBox, public DTK_CORE_NAMESPACE::DObject
{
    Q_OBJECT

    Q_PROPERTY(bool alert READ isAlert WRITE setAlert NOTIFY alertChanged)
    Q_PROPERTY(double defaultValue READ defaultValue WRITE setDefaultValue NOTIFY defaultValueChanged)

public:
    explicit DDoubleSpinBox(QWidget *parent = 0);

    bool isAlert() const;
    double defaultValue() const;

public Q_SLOTS:
    void setAlert(bool alert);
    void setDefaultValue(double defaultValue);

Q_SIGNALS:
    void alertChanged(bool alert);
    void defaultValueChanged(double defaultValue);

protected:
    void resizeEvent(QResizeEvent *e) Q_DECL_OVERRIDE;

private:
    D_DECLARE_PRIVATE(DDoubleSpinBox)
    double m_defaultValue;
};

DWIDGET_END_NAMESPACE

#endif // DSPINBOX_H
