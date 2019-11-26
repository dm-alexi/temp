if [ $(shasum /etc/crontab | cut -d ' ' -f1) != $(cat ~/scripts/cron_sha) ]; then
	echo "Crontab modification detected." | mail -s "Crontab modified!" root@localhost
	shasum /etc/crontab | cut -d ' ' -f1 > ~/scripts/cron_sha
fi