CC = gcc
CFLAGS = -Wall -Wextra

TARGET = student

SOURCES = studentmain.c \
          stud_add1.c \
          stud_del1.c \
          stud_delall1.c \
          stud_mod1.c \
          stud_revlist1.c \
          stud_save1.c \
          stud_show1.c \
          stud_sort1.c

OBJECTS = $(SOURCES:.c=.o)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.c student.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)
