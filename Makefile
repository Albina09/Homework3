.PHONY := clean
bin := Project
sources := Project.c

$(bin): $(sources)
	gcc $(sources) -o $(bin) -g

clean:
	rm -rf $(bin)

