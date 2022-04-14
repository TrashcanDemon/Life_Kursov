# Life_Kursov

Игра-жизнь с графическим интерфейсом в OpenGL. Программа написана на C++ с использованием основных библиотек OpenGL и библиотеки утилит FreeGLUT.

## Сборка программы

Чтобы собрать программу вручную, необходимо:

•	Установить MinGW-w64, перейдя по ссылке https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/. После установки, добавьте полные пути к папкам «bin» и «x86_64-w64-mingw32\bin» в переменную окружения PATH.

•	Установить CMake, по ссылке https://cmake.org/download/.

•	Установить библиотеку FreeGLUT. Сделать это можно, перейдя по ссылке http://freeglut.sourceforge.net/ и скачав самую последнюю версию в подразделе «Stable Releases» (программа была сделана с использованием версии 3.2.2). FreeGLUT поставляется только в виде исходного кода, так что после скачивания и разархивирования файла этот код нужно собрать и установить в MinGW с помощью CMake. Для этого нужно перейти в разархивированную папку, содержащую файл «CMakeLists.txt», с помощью командной строки и ввести команду «cmake -G "MinGW Makefiles" -S . -B . -DCMAKE_INSTALL_PREFIX=C:\mingw64\x86_64-w64-mingw32» (DCMAKE_INSTALL_PREFIX должен равняться вашему пути к MinGW-w64 папке «x86_64-w64-mingw32»). После этого, введите «mingw32-make all», а по окончанию этого введите «mingw32-make install». Теперь у вашего компилятора MinGW-w64 автоматически должен быть доступ к хедерам и библиотеке FreeGLUT.

•	(Необязательно) Установить компонент GnuWin32 «Make for Windows», перейдя по ссылке http://gnuwin32.sourceforge.net/packages/make.htm. Это позволит вам воспользоваться прилагающийся к проекту мейкфайлу введя команду «make», заметно упрощая сборку программы.

  (Альтернативно) Можно перейти в папку с исходным кодом в командной строке и ввести команду «g++ main.cpp printer.cpp world.cpp -o life -lopengl32 -lfreeglut -lglu32».
