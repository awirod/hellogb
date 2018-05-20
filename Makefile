SRC = tile.c map.c sprite.c hello.c
OBJ = $(SRC:%.c=%.o)
IMAGE = hello.gb

.c.o:
	lcc -c $<

$(IMAGE): $(OBJ)
	lcc -o $@ $(OBJ)

clean:
	@rm -fv $(IMAGE) $(OBJ)
