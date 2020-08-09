all:
	@make -C ./libft/
	@make -C ./filler/
	@make -C ./visualizer/

filler:
	@make -C ./libft/
	@make -C ./filler

visual:
	@make -C ./libft/
	@make -C ./visualizer/

clean:
	@make clean -C ./libft/
	@make clean -C ./filler/
	@make clean -C ./visualizer/

fclean:
	@make fclean -C ./libft/
	@make fclean -C ./filler/
	@make fclean -C ./visualizer/

re: fclean all

.PHONY: all clean fclean re