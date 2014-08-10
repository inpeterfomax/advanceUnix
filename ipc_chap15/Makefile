#this makefile for compile all the programme of CHAP15

OBJ = pipe consumer  shm_client shm_server

.PHONY:all clean


$(OBJ): *.o
	gcc -o $@ $< 


clean:
	rm -rf $(OBJ)
	rm -rf *.o
