FROM ruby
RUN curl -sS https://dl.yarnpkg.com/debian/pubkey.gpg | apt-key add && \
	echo "deb https://dl.yarnpkg.com/debian/ stable main" | tee /etc/apt/sources.list.d/yarn.list && \
	apt-get update && apt-get -y install yarn && gem install rails
ONBUILD COPY /app /opt/app
ONBUILD WORKDIR /opt/app
ONBUILD RUN bundle install && rails webpacker:install && rake db:migrate && rake db:setup && rake db:seed