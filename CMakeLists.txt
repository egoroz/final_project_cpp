cmake_minimum_required(VERSION 3.5)

project(CheloFight) # Можешь назвать как угодно

set(CMAKE_CXX_STANDARD 17)

# ВАЖНО ДЛЯ UBUNTU: Если ты ставил SFML через sudo apt install libsfml-dev, 
# то путь указывать не нужно, CMake сам всё найдет. 
# Эту строку лучше закомментировать:
# set(SFML_DIR "path/to/SFML/cmake/modules")

find_package(SFML 2.5 COMPONENTS network system window graphics audio REQUIRED)

# Добавление пути к заголовочным файлам
include_directories(include)

# =====================================================================
# 1. ОБЩИЕ ФАЙЛЫ (Нужны и Клиенту, и Серверу)
# Здесь должна быть физика, анимации, парсер карт и т.д.
# Я добавил сюда player.cpp и entity.cpp, так как сервер их использует!
# =====================================================================
file(GLOB_RECURSE SHARED_SOURCES 
    "src/anim.cpp" 
    "src/player.cpp" 
    "src/entity.cpp" 
    "lib/*/*.cpp"
)

# =====================================================================
# 2. ФАЙЛЫ ТОЛЬКО ДЛЯ КЛИЕНТА (ИГРЫ)
# Здесь меню, отрисовка фона, камера и точка входа клиента (main.cpp)
# =====================================================================
file(GLOB_RECURSE CLIENT_SOURCES 
    "src/main.cpp" 
    "src/background.cpp" 
    "src/view.cpp" 
    "src/gameplay.cpp" 
    "src/Menu.cpp"
)

# =====================================================================
# 3. ФАЙЛЫ ТОЛЬКО ДЛЯ СЕРВЕРА
# Укажи здесь правильный путь к твоему server.cpp
# =====================================================================
set(SERVER_SOURCES "src/server/server.cpp") # Поменяй путь, если он лежит в другом месте


# Добавляем заголовочные файлы (чтобы они отображались в IDE)
file(GLOB_RECURSE HEADERS "include/*.hpp" "include/*.h" "lib/*/*.hpp" "lib/*/*.h")


# =====================================================================
# СОЗДАЕМ ИСПОЛНЯЕМЫЙ ФАЙЛ КЛИЕНТА
# =====================================================================
add_executable(GameClient ${CLIENT_SOURCES} ${SHARED_SOURCES} ${HEADERS})
target_link_libraries(GameClient sfml-network sfml-system sfml-window sfml-graphics sfml-audio)

# =====================================================================
# СОЗДАЕМ ИСПОЛНЯЕМЫЙ ФАЙЛ СЕРВЕРА
# =====================================================================
add_executable(GameServer ${SERVER_SOURCES} ${SHARED_SOURCES} ${HEADERS})
# Серверу обычно не нужен модуль audio, поэтому я его убрал из линковки
target_link_libraries(GameServer sfml-network sfml-system sfml-window sfml-graphics)