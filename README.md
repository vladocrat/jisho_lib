# Jisho_lib

![Build & test](https://github.com/vladocrat/jisho_lib/actions/workflows/ci.yml/badge.svg?event=push)

## !IN DEVELOPMENT 

This is a web scrapping lib for accessing [jisho.org](https://jisho.org/). Since they don't have any public API's and I kinda wanted to use their massive dictionary for a quick desktop access.

## Dependencies

This lib is written in:

* C++17
* Qt 5.15.2
* Cmake 3.8
* OpenSSL 3.2.0 ([this](https://github.com/vladocrat/openssl_3-2-0_windows_x64) version works for me)

## Usage

```C++
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    auto handler = new JL::ApiHandler;

    QObject::connect(handler, &JL::ApiHandler::finished, [](const QVector<JL::Translation>& translations){
        qDebug() << translations;
    });

    handler->translate("こんにちは");

    return a.exec();
}
```
