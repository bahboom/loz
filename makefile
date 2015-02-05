all: 
	mkdir -p debug
	g++ -g src/*.cpp -lcygwin -lSDL2main -lSDL2 -lglu32 -lopengl32 -mwindows -o debug/loz
	mkdir -p   release
	cp lib/*   release
	cp debug/* release
	
run: all
	debug/loz
	
debug: all
	gdb debug/loz.exe

commit:
	git commit -a -m "Commit: ${comment}"
	git push
