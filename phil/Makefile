all: philosophers

philosophers:
	@make -C ./philo/

bonus:
	@make -C ./philo_bonus/

clean:
	@make clean -C ./philo/
	@make clean -C ./philo_bonus/

fclean:
	@make fclean -C ./philo/
	@make fclean -C ./philo_bonus/

re: fclean all

.PHONY: all clean fclean re bonus