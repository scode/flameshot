// Copyright(c) 2017-2018 Alejandro Sirgo Rica & Contributors
//
// This file is part of Flameshot.
//
//     Flameshot is free software: you can redistribute it and/or modify
//     it under the terms of the GNU General Public License as published by
//     the Free Software Foundation, either version 3 of the License, or
//     (at your option) any later version.
//
//     Flameshot is distributed in the hope that it will be useful,
//     but WITHOUT ANY WARRANTY; without even the implied warranty of
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//     GNU General Public License for more details.
//
//     You should have received a copy of the GNU General Public License
//     along with Flameshot.  If not, see <http://www.gnu.org/licenses/>.

#ifndef GLOBALSHORTCUTFILTER_H
#define GLOBALSHORTCUTFILTER_H

#include <QObject>
#include <QAbstractNativeEventFilter>

class GlobalShortcutFilter : public QObject, public QAbstractNativeEventFilter {
    Q_OBJECT
public:
    explicit GlobalShortcutFilter(QObject *parent = 0);

    bool nativeEventFilter(const QByteArray &eventType, void *message, long *result);

signals:
    void printPressed();

private:
    quint32 getNativeModifier(Qt::KeyboardModifiers modifiers);
    quint32 nativeKeycode(Qt::Key key);
    bool registerShortcut(quint32 nativeKey, quint32 nativeMods);
    bool unregisterShortcut(quint32 nativeKey, quint32 nativeMods);

};

#endif // GLOBALSHORTCUTFILTER_H
