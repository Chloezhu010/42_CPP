# cpp00 Makefile

# compile all exercises
all: 
	@echo "Compile all exercises"
	@$(MAKE) -C ex00
	@$(MAKE) -C ex01
	@$(MAKE) -C ex02

clean:
	@echo "Clean all exercises"
	@$(MAKE) -C ex00 clean
	@$(MAKE) -C ex01 clean
	@$(MAKE) -C ex02 clean

fclean:
	@echo "Fclean all exercises"
	@$(MAKE) -C ex00 fclean
	@$(MAKE) -C ex01 fclean
	@$(MAKE) -C ex02 fclean

re: fclean all

.PHONY: all ex00 ex01 ex02 clean re