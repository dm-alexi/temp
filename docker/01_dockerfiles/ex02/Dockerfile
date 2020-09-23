FROM ruby
RUN curl -sS https://dl.yarnpkg.com/debian/pubkey.gpg | apt-key add && \
	echo "deb https://dl.yarnpkg.com/debian/ stable main" | tee /etc/apt/sources.list.d/yarn.list && \
	apt-get update && apt-get -y upgrade && apt-get -y install yarn sqlite3 && gem install rails
ONBUILD COPY /app /opt/app
ONBUILD WORKDIR /opt/app
ONBUILD RUN bundle install && rake db:migrate && rake db:setup && rake db:seed