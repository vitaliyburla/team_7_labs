/****************************************************************************
** Meta object code from reading C++ file 'TestClient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Lab6Client/TestClient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TestClient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestClient_t {
    QByteArrayData data[25];
    char stringdata0[265];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestClient_t qt_meta_stringdata_TestClient = {
    {
QT_MOC_LITERAL(0, 0, 10), // "TestClient"
QT_MOC_LITERAL(1, 11, 9), // "connected"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 6), // "testIn"
QT_MOC_LITERAL(4, 29, 9), // "testError"
QT_MOC_LITERAL(5, 39, 6), // "reason"
QT_MOC_LITERAL(6, 46, 12), // "disconnected"
QT_MOC_LITERAL(7, 59, 12), // "testReceived"
QT_MOC_LITERAL(8, 72, 4), // "Test"
QT_MOC_LITERAL(9, 77, 4), // "test"
QT_MOC_LITERAL(10, 82, 14), // "resultReceived"
QT_MOC_LITERAL(11, 97, 4), // "mark"
QT_MOC_LITERAL(12, 102, 5), // "error"
QT_MOC_LITERAL(13, 108, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(14, 137, 11), // "socketError"
QT_MOC_LITERAL(15, 149, 15), // "connectToServer"
QT_MOC_LITERAL(16, 165, 12), // "QHostAddress"
QT_MOC_LITERAL(17, 178, 7), // "address"
QT_MOC_LITERAL(18, 186, 4), // "port"
QT_MOC_LITERAL(19, 191, 12), // "setTestIndex"
QT_MOC_LITERAL(20, 204, 5), // "index"
QT_MOC_LITERAL(21, 210, 10), // "sendAnswer"
QT_MOC_LITERAL(22, 221, 12), // "answersIndex"
QT_MOC_LITERAL(23, 234, 18), // "disconnectFromHost"
QT_MOC_LITERAL(24, 253, 11) // "onReadyRead"

    },
    "TestClient\0connected\0\0testIn\0testError\0"
    "reason\0disconnected\0testReceived\0Test\0"
    "test\0resultReceived\0mark\0error\0"
    "QAbstractSocket::SocketError\0socketError\0"
    "connectToServer\0QHostAddress\0address\0"
    "port\0setTestIndex\0index\0sendAnswer\0"
    "answersIndex\0disconnectFromHost\0"
    "onReadyRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestClient[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,
       4,    1,   76,    2, 0x06 /* Public */,
       6,    0,   79,    2, 0x06 /* Public */,
       7,    1,   80,    2, 0x06 /* Public */,
      10,    1,   83,    2, 0x06 /* Public */,
      12,    1,   86,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    2,   89,    2, 0x0a /* Public */,
      19,    1,   94,    2, 0x0a /* Public */,
      21,    1,   97,    2, 0x0a /* Public */,
      23,    0,  100,    2, 0x0a /* Public */,
      24,    0,  101,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void, 0x80000000 | 13,   14,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 16, QMetaType::UShort,   17,   18,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TestClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TestClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connected(); break;
        case 1: _t->testIn(); break;
        case 2: _t->testError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->disconnected(); break;
        case 4: _t->testReceived((*reinterpret_cast< const Test(*)>(_a[1]))); break;
        case 5: _t->resultReceived((*reinterpret_cast< const double(*)>(_a[1]))); break;
        case 6: _t->error((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 7: _t->connectToServer((*reinterpret_cast< const QHostAddress(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 8: _t->setTestIndex((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 9: _t->sendAnswer((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->disconnectFromHost(); break;
        case 11: _t->onReadyRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TestClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TestClient::connected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TestClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TestClient::testIn)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TestClient::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TestClient::testError)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TestClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TestClient::disconnected)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (TestClient::*)(const Test & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TestClient::testReceived)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (TestClient::*)(const double & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TestClient::resultReceived)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (TestClient::*)(QAbstractSocket::SocketError );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TestClient::error)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TestClient::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_TestClient.data,
    qt_meta_data_TestClient,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TestClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TestClient.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TestClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void TestClient::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void TestClient::testIn()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void TestClient::testError(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TestClient::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void TestClient::testReceived(const Test & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void TestClient::resultReceived(const double & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void TestClient::error(QAbstractSocket::SocketError _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
