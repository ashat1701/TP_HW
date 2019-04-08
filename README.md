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
3. Склонируйте данный репозиторий - `git clone https://github.com/ashat1701/TP_HW`
4. Выполните cmake со специальными настройками - `PATH="$PATH:<Путь до папки tools из 2 шага>/arm-bcm2708/arm-rpi-4.9.3-linux-gnueabihf/bin" cmake -DON_PI=ON -DSYSROOT="<Путь до папки tools из 2 шага>/arm-bcm2708/arm-rpi-4.9.3-linux-gnueabihf/arm-linux-gnueabihf/sysroot" .`
5. Запустите `make`
6. Нужные файлы лежат директорией выше папки c проектом в папках bin-arm и lib-arm. Для того, чтобы поместить их в архив выполните `zip -r9 archive.zip lib-arm bin-arm/Facade`
7. И, наконец, для запуска - `bin-arm/Facade`

## Шаги которые привели к такому + попытки исправить баги
Изначально вместо того чтобы передавать ON_PI и SYSROOT параметрами просто был поправлен CMakeLists.txt. При этом в качестве компилятора c++ был выбран gcc (путь до него был жестко прописан). В результате чего make падал на этапе линковки (так как не мог найти STL). Проблема эта была изначально решена с помощью включения target_link_libraries(stdc++) во все CMakeLists.txt, после чего проект успешно линковался. 

## Сборка подпроекта Decorator

