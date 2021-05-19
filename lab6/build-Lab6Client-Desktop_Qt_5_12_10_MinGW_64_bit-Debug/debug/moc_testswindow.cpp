/****************************************************************************
** Meta object code from reading C++ file 'testswindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Lab6Client/testswindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testswindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestsWindow_t {
    QByteArrayData data[20];
    char stringdata0[233];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestsWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestsWindow_t qt_meta_stringdata_TestsWindow = {
    {
QT_MOC_LITERAL(0, 0, 11), // "TestsWindow"
QT_MOC_LITERAL(1, 12, 16), // "handleNextButton"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 17), // "attemptConnection"
QT_MOC_LITERAL(4, 48, 17), // "connectedToServer"
QT_MOC_LITERAL(5, 66, 11), // "attemptTest"
QT_MOC_LITERAL(6, 78, 5), // "index"
QT_MOC_LITERAL(7, 84, 6), // "testIn"
QT_MOC_LITERAL(8, 91, 10), // "testFailed"
QT_MOC_LITERAL(9, 102, 6), // "reason"
QT_MOC_LITERAL(10, 109, 12), // "testReceived"
QT_MOC_LITERAL(11, 122, 4), // "Test"
QT_MOC_LITERAL(12, 127, 4), // "test"
QT_MOC_LITERAL(13, 132, 14), // "resultReceived"
QT_MOC_LITERAL(14, 147, 4), // "mark"
QT_MOC_LITERAL(15, 152, 10), // "sendAnswer"
QT_MOC_LITERAL(16, 163, 22), // "disconnectedFromServer"
QT_MOC_LITERAL(17, 186, 5), // "error"
QT_MOC_LITERAL(18, 192, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(19, 221, 11) // "socketError"

    },
    "TestsWindow\0handleNextButton\0\0"
    "attemptConnection\0connectedToServer\0"
    "attemptTest\0index\0testIn\0testFailed\0"
    "reason\0testReceived\0Test\0test\0"
    "resultReceived\0mark\0sendAnswer\0"
    "disconnectedFromServer\0error\0"
    "QAbstractSocket::SocketError\0socketError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestsWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    1,   72,    2, 0x08 /* Private */,
       7,    0,   75,    2, 0x08 /* Private */,
       8,    1,   76,    2, 0x08 /* Private */,
      10,    1,   79,    2, 0x08 /* Private */,
      13,    1,   82,    2, 0x08 /* Private */,
      15,    0,   85,    2, 0x08 /* Private */,
      16,    0,   86,    2, 0x08 /* Private */,
      17,    1,   87,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, QMetaType::Double,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,   19,

       0        // eod
};

void TestsWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TestsWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->handleNextButton(); break;
        case 1: _t->attemptConnection(); break;
        case 2: _t->connectedToServer(); break;
        case 3: _t->attemptTest((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 4: _t->testIn(); break;
        case 5: _t->testFailed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->testReceived((*reinterpret_cast< const Test(*)>(_a[1]))); break;
        case 7: _t->resultReceived((*reinterpret_cast< const double(*)>(_a[1]))); break;
        case 8: _t->sendAnswer(); break;
        case 9: _t->disconnectedFromServer(); break;
        case 10: _t->error((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TestsWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_TestsWindow.data,
    qt_meta_data_TestsWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TestsWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestsWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TestsWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int TestsWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
