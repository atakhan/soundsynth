PROGRAM_NAME := SoundSynth

# Настройки компиляции
CC := gcc
I_FLAGS := -I backend/inc -I frontend/inc -I libs/SDL2/include
C_FLAGS := $(I_FLAGS) -std=c11 -Wall -Werror -Wextra -g
LD_FLAGS := -Llibs -lncurses $(wildcard libs/libSDL2*.dylib) -Wl,-rpath,'@loader_path/libs'

# Списки объектных файлов и Генерация путей к объектным файлам
BACKEND_OBJS := api logger sound
FRONTEND_OBJS := cli
MAIN_OBJ := main
ALL_OBJS := $(addprefix out/,$(addsuffix .o,$(BACKEND_OBJS) $(FRONTEND_OBJS) $(MAIN_OBJ)))

all: out $(PROGRAM_NAME)

out:
	mkdir -p out

$(PROGRAM_NAME): $(ALL_OBJS)
	@echo "Linking executable..."
	$(CC) $(C_FLAGS) $^ -o $@ $(LD_FLAGS)
	@echo "Fixing library paths..."
	install_name_tool -change @rpath/SDL2.framework/Versions/A/SDL2 @executable_path/libs/libSDL2-2.0.0.dylib $@

out/%.o: backend/src/%.c
	$(CC) $(C_FLAGS) -c $< -o $@

out/%.o: frontend/src/%.c
	$(CC) $(C_FLAGS) -c $< -o $@

out/%.o: %.c
	$(CC) $(C_FLAGS) -c $< -o $@


clean:
	rm -rf out/*.o $(PROGRAM_NAME) debug.log

clear: clean

.PHONY: all clean clear