##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## This is the Makefile for the Zappy project
## Its goal is to call each CMake
##

.PHONY: all clean fclean re tests_run \
	zappy_server zappy_ai zappy_gui

# Colors and formatting
GREEN =		\033[1;32m
YELLOW =	\033[1;33m
RED =		\033[1;31m
BLUE =		\033[1;36m
GOLD =		\033[1;33m
MAGENTA =	\033[1;35m
RESET =		\033[0m

RUNNING = [$(YELLOW)~$(RESET)]
SUCCESS = [$(GREEN)✔$(RESET)]
FAILURE = [$(RED)✘$(RESET)]
SKIPPED = [$(MAGENTA)@$(RESET)]

all: zappy_server zappy_ai zappy_gui
	@printf "$(SUCCESS)$(GREEN)  🎉  Zappy built successfully$(RESET)\n"

zappy_server:
	@mkdir -p build
	@cmake -S . -B build -DSERVER=ON -DGUI=OFF
	@cmake --build build --target zappy_server
	@cp build/server/zappy_server .
	@printf "$(SUCCESS)$(GREEN)  🚀  Zappy server built \
successfully$(RESET)\n"

zappy_ai:
	@mkdir -p build/robots
	@cd robots && CARGO_TARGET_DIR=../build/robots cargo build --release
	@cp build/robots/release/zappy_ai .
	@printf "$(SUCCESS)$(GREEN)  🤖  Zappy AI built successfully$(RESET)\n"

zappy_gui:
	@mkdir -p build
	@cmake -S . -B build -DGUI=ON -DSERVER=OFF
	@cmake --build build --target zappy_gui
	@cp build/gui/zappy_gui .
	@printf "$(SUCCESS)$(GREEN)  🎨  Zappy GUI built successfully$(RESET)\n"

clean:
	@rm -rf build
	@printf "$(SUCCESS)$(GREEN)  🧹  Cleaned successfully$(RESET)\n"

fclean: clean
	@rm -f zappy_server zappy_ai zappy_gui
	@printf "$(SUCCESS)$(GREEN)  🔥  Binaries removed successfully$(RESET)\n"

re: fclean all

tests_run: fclean
	@mkdir -p build
	@cmake -S . -B build -DTESTS=ON -DSERVER=ON -DGUI=ON
	@cmake --build build --target zappy_tests
	@./build/tests/zappy_tests --gtest_output=xml
