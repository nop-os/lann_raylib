gcc $(find . -name "*.c") -Iinclude -I../lann/lann/include -Ofast -shared -Llib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -fPIC -o raylib.so
