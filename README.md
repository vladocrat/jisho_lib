# Jisho_lib

![Build & test](https://github.com/vladocrat/jisho_lib/actions/workflows/ci.yml/badge.svg)

## !IN DEVELOPMENT 

This is a web scrapping lib for accessing [jisho.org](https://jisho.org/). Since they don't have any public API's and I kinda wanted to use their massive dictionary for a quick desktop access.

## Dependencies

This lib is written in:

* C++17
* Qt 5.15.2
* Cmake 3.14

## Usage

```C++
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    auto handler = new ApiHandler;

    QObject::connect(handler, &ApiHandler::finished, [](const QVector<Translation>& translations){
        qDebug() << translations;
    });

    handler->translate("こんにちは");

    return a.exec();
}
```
