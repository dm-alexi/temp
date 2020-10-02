FROM debian
EXPOSE 80 443 22
# install dependencies
RUN apt-get update && apt-get upgrade -y && apt-get install -y curl openssh-server ca-certificates postfix tzdata
# add repository
RUN curl https://packages.gitlab.com/install/repositories/gitlab/gitlab-ce/script.deb.sh | bash
# install gitlab
RUN apt-get install -y gitlab-ce && apt-get clean
#&& rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*
# configure gitlab
ENTRYPOINT (/opt/gitlab/embedded/bin/runsvdir-start &) && gitlab-ctl reconfigure && tail -f /dev/null