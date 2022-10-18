#//a make file for compiling the main program

CC=gcc

create_subdirectory.0: create_subdirectory.c project_management.h
	$(CC) -c create_subdirectory.c -o create_subdirectory.o
wizard.o: wizard.c project_management.h
	$(CC) -c wizard.c -o wizard.o
delete.o: delete.c project_management.h
	$(CC) -c delete.c -o delete.o
check_tag.o: check_tag.c project_management.h
	$(CC) -c check_tag.c -o check_tag.o
searching_tag.o: searching_tag.c project_management.h
	$(CC) -c searching_tag.c -o searching_tag.o
add_tag.o: add_tag.c project_management.h
	$(CC) -c add_tag.c -o add_tag.o
move_tag.o: move_tag.c project_management.h
	$(CC) -c move_tag.c -o move_tag.o
rename.o: rename.c project_management.h
	$(CC) -c rename.c -o rename.o
find_tag.o: find_tag.c project_management.h
	$(CC) -c find_tag.c -o find_tag.o
repository.o: repository.c project_management.h
	$(CC) -c repository.c -o repository.o
create_directory.o: create_directory.c project_management.h
	$(CC) -c create_directory.c -o create_directory.o
add_workload.o: add_workload.c project_management.h
	$(CC) -c add_workload.c -o add_workload.o
create_plantuml.o: create_plantuml.c project_management.h
	$(CC) -c create_plantuml.c -o create_plantuml.o
list_plantuml.o: list_plantuml.c project_management.h
	$(CC) -c list_plantuml.c -o list_plantuml.o
read_file.o: read_file.c project_management.h
	$(CC) -c read_file.c -o read_file.o
read_menu.o: read_menu.c project_management.h
	$(CC) -c read_menu.c -o read_menu.o
moving_files.o: moving_files.c project_management.h
	$(CC) -c moving_files.c -o moving_files.o
libcompiled.a: create_subdirectory.o delete.o check_tag.o searching_tag.o add_tag.o move_tag.o rename.o find_tag.o repository.o create_directory.o add_workload.o create_plantuml.o list_plantuml.o wizard.o read_file.o moving_files.o read_menu.o
	ar rv libcompiled.a create_subdirectory.o delete.o check_tag.o searching_tag.o add_tag.o move_tag.o rename.o find_tag.o repository.o create_directory.o add_workload.o create_plantuml.o list_plantuml.o wizard.o read_file.o moving_files.o read_menu.o
pm: pm.c libcompiled.a
	$(CC) pm.c -L. -lcompiled -o pm
all: pm
