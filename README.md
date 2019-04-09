# PatternsCollection
Кодовая база примеров паттернов проектирования по курсу "Технологии программирования, МФТИ"

## Содержание

* Порождающие паттерны:
  * [Factory Method](/FactoryMethod/python-source)
  * [Abstract Factory](/AbstractFactory)
    * [C++](/AbstractFactory/cpp-source)
    * [Python](/AbstractFactory/python-source)
  * [Builder](/Builder/python-source)
  * [Prototype](/Prototype/cpp-source)
  * [Adapter](/Adapter/cpp-source)
  * [Bridge](/Bridge/cpp-source)
## Компиляция под Raspiberry pi
1. Установите необходимые пакты: libboost1.67-all-dev. В debian системах - `sudo apt install  libboost1.67-all-dev`
2. Переидите в папку для установки и выполните `git clone https://github.com/raspberrypi/tools`
3. Склонируйте данный репозиторий - `git clone https://github.com/ashat1701/TP_HW` (Или же исходный репозиторий - `git clone https://github.com/akhtyamovpavel/PatternsCollection`)
4. Выполните cmake со специальными настройками - `PATH="$PATH:<Путь до папки tools из 2 шага>/arm-bcm2708/arm-rpi-4.9.3-linux-gnueabihf/bin" cmake -DON_PI=ON -DSYSROOT="<Путь до папки tools из 2 шага>/arm-bcm2708/arm-rpi-4.9.3-linux-gnueabihf/arm-linux-gnueabihf/sysroot" .`
5. Запустите `make`
6. Исполняемые файлы файлы лежат директорией выше папки c проектом в папках bin-arm и lib-arm. Для того, чтобы поместить их в архив выполните `zip -r9 archive.zip ../lib-arm ../bin-arm/`. Для того, чтобы заархивировать весь проект - `zip -r9 archive.zip ../PatternsCollection ../lib-arm ../bin-arm`
7. Команда для запуска - `LD_LIBRARY_PATH="$LD_LIBRARY_PATH:<Путь до папки lib-arm>" ./../bin-arm/Facade`
8. Скрипт для запуска - start.sh

## Шаги которые привели к такому + попытки исправить баги
Изначально вместо того чтобы передавать ON_PI и SYSROOT параметрами просто был поправлен CMakeLists.txt. При этом в качестве компилятора c++ был выбран gcc (путь до него был жестко прописан). В результате чего make падал на этапе линковки (так как не мог найти STL). Проблема эта была изначально решена с помощью включения target_link_libraries(stdc++) во все CMakeLists.txt, после чего проект успешно линковался. 

## Сборка подпроекта Decorator
1. Запустите файл decorator_compile.sh (возможно потребуется `chmod +x decorator_compile.sh`). Этот файл попросит прав администратора для установки дополнительных пакетов. Он же и запустит Decorator.

Название чата - [@mipt_tp_bot_chanell](https://t.me/mipt_tp_bot_chanell)

Почта - ak3776413@gmail.com

Пароль от почты - Trinity3!

Если же Вы не хотите клонировать весь репозиторий ради сборки декоратора - то вот еще один способ запустить декоратор. Для него потребуется наличие cURL (или wget), а также git.

C помощью curl:

```bash
sudo sh -c "$(curl -fsSL https://raw.githubusercontent.com/ashat1701/TP_HW/devops_compile/Decorator_only.sh)" 
```

С помощью wget:

```sh
sudo sh -c "$(wget https://raw.githubusercontent.com/ashat1701/TP_HW/devops_compile/Decorator_only.sh -O -)"
```
## Возможные проблемы и ошибки
В первую очередь проверьте свое подключение к vpn(прокси). Если вылетают ошибки хэндшейка или auth error - это скорее всего проблема интернета. Если во время сборки вылетает ошибка с sendmail - то необходимо удалить все что связано с vmime и собрать все заново.
И главный костыль - это смена адреса smtp://stmp.google.com на smtps://smtp.google.com:465. Эта замена была найдена здесь: [тыкъ](https://www.vmime.org/tag/smtp). Я не знаю почему без этого программа не подключается к серверам google, но после этого исправления все заработало. Также, для того чтобы узнать chatID был использован бот - @getidsbot.
