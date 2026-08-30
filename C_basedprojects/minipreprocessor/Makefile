target = project1.o commentremoval.o headerfile.o macroreplace.o
cc = gcc

exe: $(target)
	$(cc) -o mypreprocessor $(target)

project1.o: project1.c header.h
	$(cc) -c $<

commentremoval.o: commentremoval.c header.h
	$(cc) -c $<

headerfile.o: headerfile.c header.h
	$(cc) -c $<

macroreplace.o: macroreplace.c header.h
	$(cc) -c $<

clean:
	@echo "Cleaning up..."
	rm -f *.o mypreprocessor
