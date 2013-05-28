EXEC=flovv
VAPI_DIR=vapi
PACKAGES=--pkg gl --pkg libglfw --pkg sqlite3
SOURCES=src/*.vala src/**/*.vala
FLAGS=-DDEBUG

all:
	valac --vapidir=$(VAPI_DIR) $(PACKAGES) -X $(FLAGS) $(SOURCES) -o $(EXEC)
