#include <QCoreApplication>
#include <QtTest>

// add necessary includes here
#include "../clientAppRadamant/serverconnector.h"

class radamanttests : public QObject
{
    Q_OBJECT

public:
    radamanttests();
    ~radamanttests();

private slots:
    void test_case1();
    void test_case2();
    void test_case3();
    void test_case4();
    void test_case5();

private:
    ServerConnector sc;
};

radamanttests::radamanttests() {
    sc.setHost("95.165.152.146:27015");
}

radamanttests::~radamanttests() {}

// Авторизация с правилными учетными данными
void radamanttests::test_case1() {
    int rep = sc.Authorize("testuser", "12345");
    qDebug() << rep;
    QVERIFY2(rep != -1, "Не удалось авторизовать верного пользователя");
}

void radamanttests::test_case2()
{
    int rep = sc.Authorize("testuser", "wrongPassword");
    qDebug() << rep;
    QVERIFY2(rep == -1, "Удалось авторизовать неверного пользователя");
}

void radamanttests::test_case3()
{
    Person person("Well", "0000111111");
    bool rep = sc.ManualPass(&person, 1);

    QVERIFY2(rep, "Не удалось пропустить своего сотрудника");
}

void radamanttests::test_case4()
{
    Person person("Well", "1234567890");
    bool rep = sc.ManualPass(&person, 1);

    QVERIFY2(!rep, "Удалось пропустить не своего сотрудника");
}

void radamanttests::test_case5()
{
    bool rep = sc.SOS(1);

    QVERIFY2(rep, "Ошибка отправки SOS-сигнала");
}


QTEST_MAIN(radamanttests)

#include "tst_radamanttests.moc"
