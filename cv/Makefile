all:
	@make -C ./libft/
	@make -C ./assembler/
	@make -C ./vm/

asm:
	@make -C ./assembler/

corewar:
	@make -C ./vm/

clean:
	@make clean -C ./assembler/
	@make clean -C ./vm/

fclean:
	@make fclean -C ./assembler/
	@make fclean -C ./vm/

re: fclean all

.PHONY: all clean fclean re