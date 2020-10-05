FROM debian
EXPOSE 80 443 22
# install dependencies
RUN apt-get update && apt-get upgrade -y && apt-get install -y curl openssh-server ca-certificates postfix tzdata
# add repository
RUN curl https://packages.gitlab.com/install/repositories/gitlab/gitlab-ce/script.deb.sh | bash
# install gitlab
RUN apt-get install -y gitlab-ce && apt-get clean
# configure https
RUN mkdir -p /etc/gitlab/ssl && chmod 755 /etc/gitlab/ssl \
	&& openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/gitlab/ssl/gitlab.key -out /etc/gitlab/ssl/gitlab.crt -subj "/C=/ST=/L=/O=/CN=" \
	&& echo "nginx['ssl_certificate'] = \"/etc/gitlab/ssl/gitlab.crt\"" >> /etc/gitlab/gitlab.rb \
	&& echo "nginx['ssl_certificate_key'] = \"/etc/gitlab/ssl/gitlab.key\"" >> /etc/gitlab/gitlab.rb \
	&& echo "nginx['redirect_http_to_https'] = true" >> /etc/gitlab/gitlab.rb \
	&& echo "letsencrypt['enable'] = false" >> /etc/gitlab/gitlab.rb
ENTRYPOINT echo "external_url \"https://$DOCKER_IP\"" >> /etc/gitlab/gitlab.rb \
	&& (/opt/gitlab/embedded/bin/runsvdir-start &) && gitlab-ctl reconfigure && tail -f /dev/null
