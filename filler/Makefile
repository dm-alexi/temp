all:
	make -C ./filler/
	make -C ./visualizer/

clean:
	make clean -C ./filler/
	make clean -C ./visualizer/

fclean:
	make fclean -C ./filler/
	make fclean -C ./visualizer/

re: fclean all

.PHONY: all clean fclean re